#include <iostream>
#include <string>
using namespace std;

class TestCopyAssignmentOperator
{
    public:
    TestCopyAssignmentOperator(std::string& name):
    _name(name)
    {}

    private:
    std::string& _name;
};


int main()
{
    //int vexingParse(); //This can be interpreted as a function and creates ambiguity
    //This is mostly seen when attempting to create an object and try to explicitly call its default constructor 
    //class VexingParseExample
    //{
    //    public:
    //    VexingParseExample() = default;
    //};
    //VexingParseExample _VexingParseExample;//written like this it calls the constructor by default and creates no ambiguity
    //VexingParseExample _VexingParseExample(); //written like this can be mistaken for a function signature and creates ambiguity
    //VexingParseExample _VexingParseExample{}; //written like this is a workaround of the explicit default constructor call that raises no error 


    //I will now present some properties of the copy assignment operator
    std::string Test1Val("Test");
    TestCopyAssignmentOperator test1(Test1Val);

    std::string Test1Val2("Test1");
    TestCopyAssignmentOperator test2(Test1Val2);

    //test2 = test1;
    //This operator will not work and will raise a compilation error 
    //The reason for that is because the compiler cannot decide how to manage the reference 
    //References cannot be moved after initialization so this would bring ambiguity so the operator is deleted by default in this case
    
    TestCopyAssignmentOperator Test1Val3(test1); 

    //In this case there is no error as the reference is automaticaly initialized with the value from test1


}