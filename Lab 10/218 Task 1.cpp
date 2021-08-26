/**
differences between virtual and pure virtual function
VIRTUAL FUNCTION:
for virtual function we see that a base class pointer, which is assigned the address of an derived class object, can override
a function in base class if virtual keyword in used before that function in the base class.
now here, we can have 2 scenarios-
1. the function exists in the derived class- the derived class function is executed
2. the function does not exist in the derived class- the base class function is executed

PURE VIRTUAL FUNCTION:
for pure virtual function we write the virtual function declaration in the base class and (=0) after the declaration, which
indicates that this function is a pure virtual function and it makes the base class an abstract class, which means it cannot
have an independent object created. It can only work when the function exists in the derived class that's object has been
assigned to the base pointer.
*/

#include<iostream>
using namespace std;

class machine ///has a pure virtual function in the class, object cannot be created, an abstract class
{
protected:
    string name;
    string used_for;
public:
    machine(string n, string use):name(n),used_for(use)
    {

    }
    ~machine()
    {

    }
    virtual void getinfo()=0;  ///pure virtual function
};

class Electric_machine: public machine ///has virtual function in the class
{
private:
    float power;
public:
    Electric_machine(string n, string use, float p):machine(n,use),power(p)
    {

    }
    ~Electric_machine()
    {

    }
    virtual void getinfo() ///virtual function, also overrides pure virtual function in the base class
    {
        cout<<"Name of the machine: "<<name<<endl<<"Used for: "<<used_for<<endl<<"Power: "<<power<<endl;
    }
};

class solar_power_machine:public machine
{
private:
    int avg_hours;
public:
    solar_power_machine(string n, string use, float h):machine(n,use),avg_hours(h)
    {

    }
    ~solar_power_machine()
    {

    }
    void getinfo() ///overrides the pure virtual function in the base class
    {
        cout<<"Name of the machine: "<<name<<endl<<"Used for: "<<used_for<<endl<<"Average sunlight hours: "<<avg_hours<<endl;
    }
};

/**has a pure virtual function in the base class but the function is not present in the derived class, derived class
object cannot be created*/
class NonElectric_machine:public machine
{
public:
    NonElectric_machine(string n, string use):machine(n,use)
    {

    }
    ~NonElectric_machine()
    {

    }
};

class industrial_use_machine: public Electric_machine
{
private:
    int working_hours;
public:
    industrial_use_machine(string n, string use, float p, int w): Electric_machine(n,use,p),working_hours(w)
    {

    }
    ~industrial_use_machine()
    {

    }
    void getinfo() ///overrides base class function
    {
        Electric_machine::getinfo(); ///calls for base class function
        cout<<"Working Hours: "<<working_hours<<endl;
    }
};

///Here the function from the base class is not present in the derived class, the function in base class will be executed
class household_use_machine: public Electric_machine
{
private:
    string used_at;
public:
    household_use_machine(string n, string use, float p, string At):Electric_machine(n,use,p),used_at(At)
    {

    }
    ~household_use_machine()
    {

    }
};

int main()
{
    machine *mptr;
    ///machine m("tv","entertainment"); (cannot create object m as machine is an abstract class)
    Electric_machine *eptr;
    Electric_machine e("calculator","calculation",328.3);
    solar_power_machine s("solar watch","shows time", 13);
    /**NonElectric_machine n("hand grinder", "grinding herbs"); (cannot create object as it inherits a pure virtual function
                                                                 from the base class but the function does not exist in the
                                                                 derived class) */
    industrial_use_machine i("computer","multi purpose",234.53,27);
    household_use_machine h("washing machine","washing",234.53,"laundry");
    mptr=&e;
    mptr->getinfo();
    mptr=&s;
    mptr->getinfo();
    eptr=&i;
    eptr->getinfo();
    eptr=&h;
    eptr->getinfo();
    mptr=&i;
    mptr->getinfo();
    return 0;
}
