#include <iostream>
#include <memory>
#include "assert.h"
#include "vector_insert.h"
#include <gtest/gtest.h>

class IndexReader {}
;

void print(std::unique_ptr<IndexReader>* index_reader) {
    assert(index_reader != nullptr);
}

TEST(HelloTest, UniquePtr) {
    std::unique_ptr<IndexReader> index_reader;
    print(&index_reader);

//    vector_insert *vi = new vector_insert();
//    vi -> test_vector_insert();

    EXPECT_FALSE(false);
}
