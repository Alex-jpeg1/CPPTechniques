#include <iostream>

using namespace std;



int main()
{
    //int vexingParse(); //This can be interpreted as a function and creates ambiguity
    //This is mostly seen when attempting to create an object and try to explicitly call its default constructor 
    class VexingParseExample
    {
        public:
        VexingParseExample() = default;
    };

    //VexingParseExample _VexingParseExample;//written like this it calls the constructor by default and creates no ambiguity
    //VexingParseExample _VexingParseExample(); //written like this can be mistaken for a function signature and creates ambiguity
    //VexingParseExample _VexingParseExample{}; //written like this is a workaround of the explicit default constructor call that raises no error 
}