#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

//lambda to add 2 numbers that are read from the keyboard
//the return type will be void

#define constprintVector(v) for(const auto& x:v) std::cout<<x<<" "; 
#define NumberOfBytes(x) sizeof(x)
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
      
      inline void operator()() const
      {
         std::cout<<"LambdaPointer"<<" ";
      }
      using returnType = void(*)();
      inline constexpr operator returnType() const noexcept
      {
         //std::cout<<"Invoked through pointer";
         //This is a test to see it getting invoked through a pointer
         return __invoke;
      }
   private:
      static inline void __invoke()
      {
         LambdaPointer{}.operator()();
      }
};

class CustomGreater
{
   public:
      CustomGreater(){};
      inline bool operator()(int _x, int _y)
      {
         return _x > _y;
      }
      using returnType = bool(*)(int,int);
      inline constexpr operator returnType() const noexcept
      {
         return __invoke;
      }
   private:
      static inline bool __invoke(int _x, int _y)
      {
         return CustomGreater{}.operator()(_x,_y);
      }
};

//This will be similar to the std::greater<int> 
//It will not contain a template as it will be specialized for the int type

/*
void TestFunction(void(*p_Func)())
{
   p_Func();
}*/
namespace Custom
{
   void swap(int& a,int& b)
   {
      a=a+b;
      b=a-b;
      a=a-b;
   }
   //simple swap although it will be templated later on
   void sort(std::vector<int>::iterator begin, std::vector<int>::iterator end, bool(*p_Func)(int,int))
   {
      std::vector<int>::iterator Start;
      std::vector<int>::iterator End = end;
      std::vector<int>::iterator SecondIteration;
      for(Start = begin; Start < End; Start++)
      {
         for(SecondIteration = Start + 1; SecondIteration < End; SecondIteration++)
         {
            if(p_Func(*SecondIteration,*Start))
               {
                  swap(*SecondIteration,*Start);
               }
         }
      }
   }
   //Functional sort algorithm specialized only for ints for the time being will be moved to template 
   //Takes a pointer to a comparison function
   //The algorithm used is not optimal for a sort function but it is used as an example to prove the core concept behind
}
//A custom namespace to implement different functions from the standard library

int main()
{
   //auto Lambda = [](){}; // a simple lambda to see the syntax
   
   //int x = 10;
   //Now i will create a Lambda object that takes all the variable around and prints their values
   //auto Lambda1 = [=]()
                      //{
                      // std::cout<<x<<' ';
                      //};

   //Lambda1();//this example takes all the values around by value and is not allowed to modify any of them
   
   //auto Lambda2 = [=]() mutable 
                        //{
                        //   x--;
                        //   std::cout<<x<<' ';
                        //}; //This lambda allows to modify the values of the variables captured though it does not modify the value from the function it captured it from
   //Lambda2();

   //std::cout<<x<<'\n';

   /*auto Lambda3 = [&](){
                         x--;
                         std::cout<<x<<' ';
                        }; //This Lambda captures by reference and the values will be modified even outside
   Lambda3();
   */
   //std::cout<<x<<'\n'; // x has been modified 
   
   //Lambdas will be transformed into a class each lambda with its own class 
   //These clases are called functors and are pretty much overloads of the () operator 
   //I will demonstrate this in a code although i will not ensure a 1 to 1 class definition of the Lambdas that are created by the compiler
   
   //TO DO Learn to implement a lambda by hand and try to call it
   //Done implemented as a functor
   //int y=20;
   //Lambda f = Lambda(x,y);
   //f();
   
   LambdaPointer Lambdapointer = LambdaPointer{};

   //TestFunction(Lambdapointer);
   auto data = []()
                        {
                           std::vector<int> v(10);
                           for(int i=0;i<10;i++)
                           {
                              v[i] = 100*i;
                           }
                           std::sort(v.begin(),v.end(),std::less<int>());
                           return v;
                        }();
   constprintVector(data);

   Custom::sort(data.begin(),data.end(),CustomGreater());
   //call the sort function giving an object of the CustomGreater functor
   std::cout<<'\n';
   constprintVector(data);
   //This is an example of a workaround on a const value to be initialized with a more complex value
}

