#include<iostream>

constexpr int TestFunction(int val)
{
   return val*val;
}

int main()
{
   constexpr int Test = 100;

   //Test++; //This results in an error
   
   std::cout<<TestFunction(Test);


}
