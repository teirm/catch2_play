// Catch2 tests for summation class
// 
// 19 January 2021

#define CATCH_CONFIG_MAIN

#include <Summer.hpp>

#include <catch2/catch_all.hpp>

TEST_CASE("Instance adds value given", "[add-value]") {
    unsigned int initial_value = 0;
    
    Summer sum_thing(initial_value);
    REQUIRE(sum_thing.add_value(10) == 10);
}

TEST_CASE("Instance returns current value", "[get-value]") {
    unsigned int initial_value = 10;

    Summer sum_thing(initial_value);
    REQUIRE(sum_thing.get_current_value() == 10);
}

TEST_CASE("Instance resets value", "[reset-value]") {
    unsigned int initial_value = 10;

    Summer sum_thing(initial_value);
    sum_thing.reset_value();
    sum_thing.add_value(10);
    REQUIRE(sum_thing.get_current_value() == 10);
}
