#include <iostream>
#include <string>

class TestCopyAssignmentOperator
{
    public:
    TestCopyAssignmentOperator(std::string& name):
    _name(name)
    {}

    private:
    std::string& _name;
};


namespace Testnodiscard
{
    class TestNODISCARD
    {
        public:
        [[nodiscard]] int Getter(){ return 1; }
        [[nodiscard("Unused Value")]] int GetterMessage(){return 0;}
        private:
    };
}

class LivingBeing
{
    public:

    private:
        std::string Birthday;
};

namespace UncopyableObjectsModernWay
{
class UncopyableModern
{
    public:
        UncopyableModern() = default;
        UncopyableModern(const UncopyableModern&) = delete;
        void operator=(const UncopyableModern&) = delete;
    private:

};
//This is a base class for making an onject unable to copy

class Person:public UncopyableModern, public LivingBeing
{
    public:

    private:
        std::string Name;
        int Age;
};
}

namespace UncopyableObjectsDeprecatedWay
{
class UncopyableDeprecated
{
    public:
    UncopyableDeprecated() = default;
    
    private:
    UncopyableDeprecated(const UncopyableDeprecated&);
    void operator=(const UncopyableDeprecated&);
};

class Person:public LivingBeing, public UncopyableDeprecated
{
    public:
    private:
        std::string name;
        int age;
};
}

namespace ImmovableObjectsDelete
{
class Immovable
{
    public:
    Immovable() = default;
    Immovable(Immovable&&) = delete;
    void operator=(Immovable&&) = delete;
    private:
};

class Person: public Immovable
{
    public:
    private:
};

Person GetNewPerson()
{
    return Person{};
}
}
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

    //int copyOperatorcall1, copyOperatorcall2, copyOperatorcall3 = 100;

    //std::cout<<copyOperatorcall1<<" "<<copyOperatorcall2<<" "<<copyOperatorcall3<<'\n';

    //copyOperatorcall1.operator=(copyOperatorcall2);

    //An explicit call on the =operator on a primitive will result in a compilation error

    UncopyableObjectsModernWay::Person FirstPerson;
    //UncopyableObjectsModernWay::Person CopyCtorTestPerson(FirstPerson); //Compilation error cannot call copy ctor (deleted)
    UncopyableObjectsModernWay::Person CopyOperatorTestPerson;

    //CopyOperatorTestPerson = FirstPerson; //Compilation error cannot call copy operator (deleted)

    UncopyableObjectsDeprecatedWay::Person FirstPersonDeprecated;
    //UncopyableObjectsDeprecatedWay::Person CopyCtorTestPersonDeprecated(FirstPersonDeprecated); //Compilation error cannot call copy ctor (private undefined)
    UncopyableObjectsDeprecatedWay::Person CopyOperatorTestPersonDeprecated;

    //CopyOperatorTestPersonDeprecated = FirstPersonDeprecated; //Compilation error cannot call copy operator (private undefined)

    ImmovableObjectsDelete::Immovable TestPersonMove = ImmovableObjectsDelete::Immovable{}; //This should call the move constructor but since c++17 it 
                                                                                            //is transformed in a normal constructor call

    //ImmovableObjectsDelete::Immovable TestPersonMove1 = std::move(ImmovableObjectsDelete::Immovable{}); //In this example i am explicitly casting it to an rvalue so it calls the move constructor 

    //ImmovableObjectsDelete::Immovable TestPersonMove2 = static_cast<ImmovableObjectsDelete::Immovable &&>(ImmovableObjectsDelete::Immovable{}); //In this example i do not use the std::move i 
                                                                                                                                                //cast it myself to an rvalue so i force the move constructor

    ImmovableObjectsDelete::Person TestPersonMove3 = ImmovableObjectsDelete::GetNewPerson(); //This does not result in an error as it is directly constructed there so no move


    //ImmovableObjectsDelete::Person TestPersonMove4 = std::move(ImmovableObjectsDelete::GetNewPerson()); //I again force the cast to &&
    //ImmovableObjectsDelete::Person TestPersonMove5 = static_cast<ImmovableObjectsDelete::Person&&>(ImmovableObjectsDelete::GetNewPerson()); //Same Problem

    //ImmovableObjectsDelete::Person TestPersonMove6 = reinterpret_cast<ImmovableObjectsDelete::Person&&>(ImmovableObjectsDelete::Person{}); //This creates an error due to the fact 
                                                                                                                                            //reinterpret_cast needs a non prvalue addres to be able to create a reference 
    Testnodiscard::TestNODISCARD TestNODISCARD;

    TestNODISCARD.Getter();
    TestNODISCARD.GetterMessage();
}