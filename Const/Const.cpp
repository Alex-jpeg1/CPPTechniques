#include <iostream>
#include <vector>

using namespace std; //unsafe used to not write so many rezolutions in these example
//do not use this in projects

template <typename T>
ostream& operator<<(ostream& out, vector<T> v)
{
    for(const T x: v)
    {
        out<<x<<' ';
    }
    out<<'\n';
    return out;
}

int main()
{
    //Lets test the const keyword using a vector iterator

    vector<int> v(10,10); //create a vector of 10 elements all initialized with 10

    vector<int>::iterator itr = v.begin(); //This is an interator that cand both modify the value and its own value

    *itr = 20; //transforms the first value to 20
    *(++itr) = 30; //increment the operator and make the second element as 30

    cout<<v;

    //untill now no errors shoudl occur

    const vector<int>::iterator citr = v.begin();//This is a constant iterator that points to non const value

    *citr = 40; //This transform the first element to 40
    //*(++citr) = 50; // This would result in an error as we try to modify the actual value of the pointer not the value it points to

    cout<<v;
    //untill now an error occurs as we cannot modify the citr 

    vector<int>::const_iterator cvitr = v.begin(); //This iterator can be modified but it cannot modify the values it points to

    //*cvitr = 100; //this line creates an error as we try to modify a const value 
    //*(++cvitr) = 110; //This line also creates an error for similar reason as the above example although the operator++ allows to modify the value of the iterator

    cout<<v;

    //untill now we have 2 errors when trying to modify the values the iterators point to 

    const vector<int>::const_iterator ccvitr = v.begin(); //this is a const iterator that points to const value

    //*ccvitr = 120; //This results in an error as we cannot modify the value
    //*(++ccvitr) = 130; //This results first in an error of trying to increment the pointer which is const although it cannot modify the value either

    cout<<v;
    //untill now still 2 errors but we cannot modify the value with *(++ccvitr) the incrementing error simply occurs first 
}