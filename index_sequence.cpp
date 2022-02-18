//
// Created by dingmao on 2022/2/7.
//

#include <gtest/gtest.h>

////////////////////////////////////
template <size_t ...N>
static constexpr auto square_nums(size_t index, std::index_sequence<N...>) {
    constexpr auto nums = std::array<int, sizeof...(N)> { N * N ... };
    return nums[index];
}

template <size_t N>
constexpr static auto const_nums(size_t index) {
    return square_nums(index, std::make_index_sequence<N>{});
}

////////////////////////////////////

template <typename Tuple, typename Func, size_t ... N>
void func_call_tuple(const Tuple& t, Func&& func, std::index_sequence<N...>) {
    static_cast<void>(std::initializer_list<int>{(func(std::get<N>(t)), 0)...});
}

template <typename ... Args, typename Func>
void travel_tuple(const std::tuple<Args...>& t, Func&& func) {
    func_call_tuple(t, std::forward<Func>(func), std::make_index_sequence<sizeof...(Args)>{});
}

////////////////////////////////////

TEST(TemplateTest, MakeIndexSequence) {

    std::cout << const_nums<101>(100);

    static_assert(const_nums<101>(100) == 100 * 100);
}

TEST(TemplateTest, MakeIndexSequence2) {

    auto t = std::make_tuple(1, 4.56, "happen lee");
    travel_tuple(t, [](auto&& item) {
        std::cout << item << ",";
    });
}