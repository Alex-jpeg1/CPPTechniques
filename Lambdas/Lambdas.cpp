#include<iostream>

//lambda to add 2 numbers that are read from the keyboard
//the return type will be void
class Lambda
{
   public:
      Lambda(int _x, int _y): x(_x), y(_y){}

      inline void operator()() const 
         {
            std::cout<<x+y;
         }
   private:
      const int x;
      const int y;
};
//This is called a functor and is a c++ only compatible 

struct LambdaPointer{
   public:
      LambdaPointer(){};
};

//TO DO implement a lambda with a pointer function
int main()
{
   //auto Lambda = [](){}; // a simple lambda to see the syntax
   
   int x = 10;
   //Now i will create a Lambda object that takes all the variable around and prints their values
   auto Lambda1 = [=]()
                      {
                       std::cout<<x<<' ';
                      };

   Lambda1();//this example takes all the values around by value and is not allowed to modify any of them
   
   auto Lambda2 = [=]() mutable 
                        {
                           x--;
                           std::cout<<x<<' ';
                        }; //This lambda allows to modify the values of the variables captured though it does not modify the value from the function it captured it from
   Lambda2();

   //std::cout<<x<<'\n';

   auto Lambda3 = [&](){
                         x--;
                         std::cout<<x<<' ';
                        }; //This Lambda captures by reference and the values will be modified even outside
   Lambda3();
   
   //std::cout<<x<<'\n'; // x has been modified 
   
   //Lambdas will be transformed into a class each lambda with its own class 
   //These clases are called functors and are pretty much overloads of the () operator 
   //I will demonstrate this in a code although i will not ensure a 1 to 1 class definition of the Lambdas that are created by the compiler
   
   //TO DO Learn to implement a lambda by hand and try to call it
   //Done implemented as a functor
   int y=20;
   Lambda f = Lambda(x,y);
   f();
}

