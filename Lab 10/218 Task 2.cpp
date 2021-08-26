#include<iostream>
using namespace std;

/**
Here the copy constructor and the assignment operator has been introduced in a new form
In case we hadn't introduced our own version of the copy constructor and the assignment operator &
used the default ones, the no_of_copies wouldn't have increased by 1 every time a new copy was made.
*/
class Copy
{
private:
    int data;
    int no_of_copies;
public:
    Copy():data(5),no_of_copies(0)
    {

    }
    Copy(int d, int nC):data(d),no_of_copies(nC)
    {

    }
    void operator = (Copy &c)
    {
        data=c.data;
        no_of_copies=++c.no_of_copies;
        cout<<"Assignment operator invoked!\n";
    }
    Copy(Copy& c)
    {
        data=c.data;
        no_of_copies=++c.no_of_copies;
        cout<<"Copy constructor invoked!\n";
    }
    void showdata()
    {
        cout<<"Data: "<<data<<endl<<"No of copies: "<<no_of_copies<<endl;
    }
};

/**
This class is restricted from copying copying from one object to another
as both the assignment operator and the copy constructors are kept as
private members
*/
class notCopy
{
private:
    int data;
    int no_of_copies;
    void operator = (notCopy& c)
    {

    }
    notCopy c2(c1);
    notCopy(notCopy& c)
    {

    }
public:
    notCopy():data(5),no_of_copies(0)
    {

    }
    notCopy(int d, int nC):data(d),no_of_copies(nC)
    {

    }
    void showdata()
    {
        cout<<"Data: "<<data<<endl<<"No of copies: "<<no_of_copies<<endl;
    }
};

int main()
{
    Copy c1(7,0);
    Copy c2;
    Copy c3(c1);
    c1.showdata();
    c2.showdata();
    c3.showdata();
    c3=c2;
    c2.showdata();
    c3.showdata();

    ///for the copy restriction class
    notCopy n1(7,0);
    notCopy n2;
    n1.showdata();
    n2.showdata();
    /**Here this part will show error while compiling as the copy constructor and assignment operators
    are kept private in the class
    */
//    notCopy n3(n1);
//    n3.showdata();
//    n3=n2;
//    n2.showdata();
//    n3.showdata();
    return 0;
}
