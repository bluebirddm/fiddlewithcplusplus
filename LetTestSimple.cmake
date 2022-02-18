function(custom_define_tests)
  set(directory_count 0)
  set(test_count 0)
  set(currentArg 0)

  while(currentArg LESS ${ARGC})
    list(APPEND args " ${ARGV${currentArg}}")
    math(EXPR currentArg "${currentArg} + 1")
  endwhile()

  message(STATUS "ARGC_count : ${ARGC}，ARGC_for_each : ${args}")

  set(currentArg 0)
  while (currentArg LESS ${ARGC})
    if ("x${ARGV${currentArg}}" STREQUAL "xDIRECTORY")
      math(EXPR currentArg "${currentArg} + 1")
      if (NOT currentArg LESS ${ARGC})
        message(FATAL_ERROR "Expected base directory!")
      endif()
      set(cur_dir ${directory_count})
      math(EXPR directory_count "${directory_count} + 1")
      set(directory_${cur_dir}_name "${ARGV${currentArg}}")
      # We need a single list of sources to get source_group to work nicely.
      set(directory_${cur_dir}_source_list)

      math(EXPR currentArg "${currentArg} + 1")
      while (currentArg LESS ${ARGC})
        if ("x${ARGV${currentArg}}" STREQUAL "xDIRECTORY")
          break()
        elseif ("x${ARGV${currentArg}}" STREQUAL "xTEST")
          math(EXPR currentArg "${currentArg} + 1")
          if (NOT currentArg LESS ${ARGC})
            message(FATAL_ERROR "Expected test name!")
          endif()

          set(cur_test ${test_count})
          math(EXPR test_count "${test_count} + 1")
          set(test_${cur_test}_name "${ARGV${currentArg}}")
          math(EXPR currentArg "${currentArg} + 1")

          set(test_${cur_test}_directory ${cur_dir})
          set(test_${cur_test}_content_dir)
          set(test_${cur_test}_headers)
          set(test_${cur_test}_sources)
          set(test_${cur_test}_tag)

          set(argumentState 0)
          while (currentArg LESS ${ARGC})
            if ("x${ARGV${currentArg}}" STREQUAL "xHEADERS")
              set(argumentState 1)
            elseif ("x${ARGV${currentArg}}" STREQUAL "xSOURCES")
              set(argumentState 2)
            elseif ("x${ARGV${currentArg}}" STREQUAL "xCONTENT_DIR")
              math(EXPR currentArg "${currentArg} + 1")
              if (NOT currentArg LESS ${ARGC})
                message(FATAL_ERROR "Expected content directory name!")
              endif()
              set(test_${cur_test}_content_dir "${ARGV${currentArg}}")
            elseif ("x${ARGV${currentArg}}" STREQUAL "xTEST" OR
                    "x${ARGV${currentArg}}" STREQUAL "xDIRECTORY")
              break()
            elseif (argumentState EQUAL 1)
              list(APPEND test_${cur_test}_headers
                      "${directory_${cur_dir}_name}${ARGV${currentArg}}"
                      )
            elseif (argumentState EQUAL 2)

              message(STATUS " when argument is directory :
              directory_name : ${directory_${cur_dir}_name},
              file_name      : ${ARGV${currentArg}}")

              list(APPEND test_${cur_test}_sources
                      "${directory_${cur_dir}_name}${ARGV${currentArg}}"
                      )
            else()
              message(FATAL_ERROR "Unknown argument state!")
            endif()
            math(EXPR currentArg "${currentArg} + 1")
          endwhile()
        else()
          message(FATAL_ERROR "Unknown argument inside directory '${ARGV${currentArg}}'!")
        endif()
      endwhile()
    else()
      message(FATAL_ERROR "Unknown argument '${ARGV${currentArg}}'!")
    endif()
  endwhile()


  set(cur_test 0)
  while (cur_test LESS test_count)
    set(cur_test_name ${test_${cur_test}_name})
    set(cur_dir_name ${directory_${test_${cur_test}_directory}_name})

    message(STATUS "cur_test_name : ${cur_test_name}")

    add_executable(${cur_test_name}
            ${test_${cur_test}_headers}
            ${test_${cur_test}_sources}
            )

    # If we have CMake's built-in gtest support use it to add each test
    # function as a separate test.
    gtest_add_tests(TARGET ${cur_test_name}
            WORKING_DIRECTORY "${TOP_DIR}"
            TEST_PREFIX "${cur_test_name}."
            TEST_LIST test_cases)
    set_tests_properties(${test_cases} PROPERTIES TIMEOUT 120)

    target_link_libraries(
            ${cur_test_name}
            gtest_main)
#      apply_folly_compile_options_to_target(${cur_test_name})

    math(EXPR cur_test "${cur_test} + 1")
  endwhile()
endfunction()