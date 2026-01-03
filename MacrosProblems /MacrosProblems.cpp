#include<iostream>

#define COMPARE(a,b) f((a)> (b)?(a):(b)) 

void f(int a);

int main()
{
    int a = 5,b = 0;

    COMPARE(++a, b);

    std::cout<<a;

    COMPARE(++a,b+10);

    std::cout<< '\n' << a;
}
void f(int a)
{

}