#include "catch2/catch_all.hpp"
#include "../MATH/pow_custom.hpp"
#include <vector>

#define get_size(x) sizeof(x)

TEST_CASE("")
{
   REQUIRE(__cplusplus == 17); //FAILS
}

TEST_CASE("")
{
   REQUIRE(get_size(int *) == 8); //PASSES
}

TEST_CASE("")
{
   std :: vector<int> v = {1,2,3,4,5};
   for(const auto& curr_val: v)
   {
      INFO("Testing for value: " << curr_val);

      REQUIRE(pow2(curr_val) == 10000); //FAILS and drops the test case
   }
}
TEST_CASE("")
{
   std::vector<int> v = {1,2,3,4,5};

   for(const auto& curr_val: v)
   {
      INFO("TESTING FOR VALUE: " << curr_val);
      CHECK(pow2(curr_val) == 1000); //FAILS continues 
   }
}
