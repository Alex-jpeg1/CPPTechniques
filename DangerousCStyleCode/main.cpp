#include<iostream>

void foo(const char* const val )
{
    std::cout<<val<<std::endl;
}

int main()
{
    char c;
    
    c='A';

    foo(&c);

    std::cin>>c;

    foo(&c);
    //Same result in both cases 
    //This is undefined Behaviour 
    //foo should simply write the value in the terminal 
    //This might return segfault as it writes the values byte by byte until it meets the \0 value and in our case the 
    // value never apears it enters in unallocated zone
}