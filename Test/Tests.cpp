#include "catch2/catch_all.hpp"

#define get_size(x) sizeof(x)

TEST_CASE("")
{
   REQUIRE(__cplusplus == 17); //FAILS
}

TEST_CASE("")
{
   REQUIRE(get_size(int *) == 8); //PASSES
}
