#include<iostream>

void foo(const char* const val )
{
    std::cout<<val<<std::endl;
}

int main()
{
    char* c;
    
    c = new char{'A'};

    foo(c);

    //This is more dangerous and has more chances of resulting in segfaul 
    //It still is considered UB
}