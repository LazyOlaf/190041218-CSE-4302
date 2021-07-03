#include<bits/stdc++.h>
using namespace std;

class Employee
{
private:
    string EmpName;
    int ID;
    int age;
    float salary;
    int getStatus()
    {
        if(age<=25)
        {
            if(salary<=20000)
                return 1;
            else
                return 2;
        }
        else
        {
            if(salary<=21000)
                return 1;
            else if(salary>21000 && salary<=60000)
                return 2;
            else
                return 3;
        }
    }
public:
    void FeedInfo()
    {
        cout<<"Enter Employee name: ";
        cin>>EmpName;
        cout<<"Enter ID: ";
        cin>>ID;
        cout<<"Enter age: ";
        cin>>age;
        cout<<"Enter Salary: ";
        cin>>salary;
    }

    void ShowInfo()
    {
        cout<<"Name: "<<EmpName<<endl<<"ID: "<<ID<<endl<<"Age: "<<age<<endl<<"Salary: "<<salary<<endl;
        if(getStatus()==1)
            cout<<"Low Salaried Person."<<endl;
        else if(getStatus()==2)
            cout<<"Moderate Salaried Person."<<endl;
        else
            cout<<"High Salaried Person."<<endl;
    }
};

int main()
{
    Employee e;
    e.FeedInfo();
    e.ShowInfo();
    return 0;
}
