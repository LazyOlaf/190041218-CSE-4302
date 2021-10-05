#include<fstream>
#include<iostream>
#include<typeinfo>
using namespace std;
enum person_type {tstudent,tteacher};
const int MAX = 100;

class person
{
private:
    string name;
    int ID;
    static int n;
    static person* arr[];
public:
    virtual void getdata()
    {
        cin.ignore(10, '\n');
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> ID;
    }
    virtual void putdata()
    {
        cout << "\n Name: "<< name;
        cout << "\n ID: " << ID;
    }
    virtual person_type get_type();
    static void add();
    static void display();
    static void read();
    static void write();
};

int person::n;
person* person::arr[MAX];

class student: public person
{
private:
    int Class;
    char section;
public:
    void getdata()
    {
        person::getdata();
        cout<<"Enter class: ";
        cin>>Class;
        cout<<"Enter section: ";
        cin>>section;
    }
    void putdata()
    {
        person::putdata();
        cout<<"\nClass: "<<Class;
        cout<<"\nSection: "<<section<<endl;
    }
};

class teacher: public person
{
private:
    int Subject;
    int Salary;
public:
    void getdata()
    {
        person::getdata();
        cout<<"Enter subject: ";
        cin>>Subject;
        cout<<"Enter salary: ";
        cin>>Salary;
    }
    void putdata()
    {
        person::putdata();
        cout<<"\nSubject: "<<Subject;
        cout<<"\nSalary: "<<Salary<<endl;
    }
};

void person::add()
{
    char ch;
    cout << "'s' to add a student"
            "\n't' to add a teacher"
            "\nEnter selection: ";
    cin >> ch;
    switch(ch)
    {
    case 's':
        arr[n] = new student;
        break;
    case 't':
        arr[n] = new teacher;
        break;
    default:
        cout << "\nUnknown person type\n";
        return;
    }
    arr[n++]->getdata();
}

void person::display()
{
    for(int j=0; j<n; j++)
    {
        cout << (j+1);
        switch(arr[j]->get_type())
        {
        case tstudent:
            cout << ". Type: Student";
            break;
        case tteacher:
            cout << ". Type: Teacher";
            break;
        default:
            cout << ". Unknown type";
        }
        arr[j]->putdata();
        cout << endl;
    }
}

person_type person::get_type()
{
    if( typeid(*this) == typeid(student))
        return tstudent;
    else if( typeid(*this)==typeid(teacher) )
        return tteacher;
    else
    {
        cerr << "\nWrong type!";
        exit(1);
    }
}

void person::write()
{
    int size;
    cout << "Writing "<< n << " persons.\n";
    ofstream ouf;
    person_type etype;
    ouf.open("PERSON.DAT", ios::trunc | ios::binary);
    if(!ouf)
    {
        cout << "\nCan’t open file\n";
        return;
    }
    for(int j=0; j<n; j++)
    {
        etype = arr[j]->get_type();
        ouf.write( (char*)&etype, sizeof(etype) );
        switch(etype)
        {
        case tstudent:
            size=sizeof(student);
            break;
        case tteacher:
            size=sizeof(teacher);
            break;
        }
        ouf.write( (char*)(arr[j]), size );
        if(!ouf)
        {
            cout << "\nCan’t write to file\n";
            return;
        }
    }
}

void person::read()
{
    int size;
    person_type etype;
    ifstream inf;
    inf.open("PERSON.DAT", ios::binary);
    if(!inf)
    {
        cout << "\nCan’t open file\n";
        return;
    }
    n = 0;
    while(true)
    {
        inf.read( (char*)&etype, sizeof(etype) );
        if( inf.eof() )
            break;
        if(!inf)
        {
            cout << "\nCan’t read type from file\n";
            return;
        }
        switch(etype)
        {
        case tstudent:
            arr[n] = new student;
            size=sizeof(student);
            break;
        case tteacher:
            arr[n] = new teacher;
            size=sizeof(teacher);
            break;
        default:
            cout << "\nUnknown type in file\n";
            return;
        }
        inf.read( (char*)arr[n], size );
        if(!inf)
        {
            cout << "\nCan’t read data from file\n";
            return;
        }
        n++;
    }
    cout << "Reading " << n << " persons\n";
}

int main()
{
    char ch;
    while(true)
    {
        cout << "'a' -- add data for a person"
        "\n'd' -- display data for all person"
        "\n'w' -- write all person data to file"
        "\n'r' -- read all person data from file"
        "\n'x' -- exit"
        "\nEnter selection:";
        cin >> ch;
        switch(ch)
        {
        case 'a':
            person::add();
            break;
        case 'd':
            person::display();
            break;
        case 'w':
            person::write();
            break;
        case 'r':
            person::read();
            break;
        case 'x':
            exit(0);
        default:
            cout << "\nUnknown command";
        }
    }
    return 0;
}
