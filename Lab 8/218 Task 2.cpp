/**
1. private members of base class cannot be accessed by derived classes with any kind of inheritance
2. protected member of base class can be accessed by the derived class(1) only within the derived class(1) with any kind of inheritance
   and from a derived class(2) of that derived class(1) only if the protected member has been accessed by a protected or public inheritance
3. public member of base class can be accessed by the derived class(1) only within the derived class(1) with any kind of inheritance
   and from a derived class(2) of that derived class(1) for public and protected inheritance and from anywhere for public inheritance
*/


#include<bits/stdc++.h>
using namespace std;

class Staff
{
private:
    int Code;
    string Name;
protected:
    void whoAmI()
    {
        cout<<"Staff";
    }
public:
    Staff()
    {

    }
    Staff(int c, string s): Code(c), Name(s)
    {

    }
    ~Staff()
    {

    }
    void setinfo(int c, string s)
    {
        Code=c;
        Name=s;
    }
    Staff getinfo()
    {
        Staff temp;
        temp.Code=Code;
        temp.Name=Name;
        return temp;
    }
    void showinfo()
    {
        cout<<setw(19)<<"name"<<setw(20)<<"code\n";
        cout<<setw(19)<<Name<<setw(19)<<Code<<endl;
    }
    void showattributes()
    {
        whoAmI();
    }
};

class Teacher : public Staff
{
private:
    string subject;
    string publication;
protected:
    void whoAmI()
    {
        cout<<"Teacher - ";
        Staff::whoAmI(); ///(can access protected member of base class from anywhere within the derived class for any type of inheritance)
    }
public:
    Teacher()
    {

    }
    Teacher(int c, string s, string s1, string s2): Staff(c,s), subject(s1), publication(s2)
    {

    }
    ~Teacher()
    {

    }
    void setinfo(string s1, string s2)
    {
        subject=s1;
        publication=s2;
    }
    Teacher getinfo()
    {
        Teacher temp;
        temp.subject=subject;
        temp.publication=publication;
        return temp;
    }
    void showinfo()
    {
        Staff::showinfo();
        cout<<setw(20)<<"subject"<<setw(19)<<"publication\n";
        cout<<setw(19)<<subject<<setw(19)<<publication<<endl;
    }
    void showattributes()
    {
        whoAmI();
    }
};

class Officer : private Staff ///no member of the base class can be directly accessed from any derived classes of this class because it has private inheritance
{
private:
    string grade;
protected:
    void whoAmI()
    {
        cout<<"Officer - ";
        Staff::whoAmI();
    }
public:
    Officer()
    {

    }
    Officer(int c, string s, string s1): Staff(c,s), grade(s1)
    {

    }
    ~Officer()
    {

    }
    void setinfo(string s)
    {
        grade=s;
    }
    string getinfo()
    {
        return grade;
    }
    void showinfo()
    {
        Staff::showinfo();
        cout<<setw(20)<<"Category\n";
        cout<<setw(19)<<grade<<endl;
    }
    void showattributes()
    {
        whoAmI();
    }
};

class Typist : protected Staff
{
private:
    float speed;
    void whoAmI()
    {
        cout<<"Typist - ";
        Staff::whoAmI();
    }
public:
    Typist()
    {

    }
    Typist(int c, string s, float sp): Staff(c,s), speed(sp)
    {

    }
    ~Typist()
    {

    }
    void setinfo(float sp)
    {
        speed=sp;
    }
    int getinfo()
    {
        return speed;
    }
    void showinfo()
    {
        Staff::showinfo();
        cout<<setw(20)<<"Speed\n";
        cout<<setw(19)<<speed<<endl;
    }
    void showattributes()
    {
        whoAmI();
    }
};

class Regular : public Typist
{
private:
    float wage;
protected:
    void whoAmI()
    {
        cout<<"regular - ";
        ///Typist::whoAmI(); ///(cannot access private member of base class directly with any kind of inheritance)
        Staff::whoAmI();  ///can access protected member of the base(1) class of the base(2) class if the base(2) class had a public or protected inheritance
    }
public:
    Regular()
    {

    }
    Regular(int c, string s, float sp, float f): Typist(c,s,sp), wage(f)
    {

    }
    ~Regular()
    {

    }
    void setinfo(float c)
    {
        wage=c;
    }
    float getinfo()
    {
        return wage;
    }
    void showinfo()
    {
        Typist::showinfo();
        cout<<setw(20)<<"wage\n";
        cout<<setw(19)<<wage<<endl;
    }
    void showattributes()
    {
        whoAmI();
    }
};

class Casual : public Typist
{
private:
    float daily_wages;
protected:
    void whoAmI()
    {
        cout<<"casual - ";
        Typist::showattributes(); ///private member from base class can only be accessed by the derived class using a public or protected member function of base class
    }
public:
    Casual()
    {

    }
    Casual(int c, string s, float sp, float dw): Typist(c,s,sp), daily_wages(dw)
    {

    }
    ~Casual()
    {

    }
    void setinfo(float dw)
    {
        daily_wages=dw;
    }
    int getinfo()
    {
        return daily_wages;
    }
    void showinfo()
    {
        Typist::showinfo();
        cout<<setw(20)<<"wage\n";
        cout<<setw(19)<<daily_wages<<endl;
    }
    void showattributes()
    {
        whoAmI();
    }
};

int main()
{
    Staff s(473,"A");
    Teacher t(420,"Ataur","programming with c++","Tata McGrawHill");
    Officer o(222,"Md. Rashed","First class");
    Typist ty(362, "D", 87);
    Regular r(333, "Robiul Awal", 85.5, 15000);
    Casual c(333, "Kawser Ahmed", 78.900002, 10000);
    cout<<"About Staff: \n";
    s.showinfo();
    cout<<"I am a ";
    s.showattributes();
    cout<<endl;
    cout<<"About Teacher: \n";
    t.showinfo();
    cout<<"I am a ";
    t.showattributes();
    cout<<endl;
    ///t.whoAmI(); (shows error as whoAmI is a protected member of the class and cannot be accessed from outside)
    ///t.Staff::whoAmI(); (even though teacher class inherits from Staff with public inheritance the protected members remain protected while accessing from somewhere other than each classes)
    cout<<"I am a ";
    t.Staff::showattributes(); ///(we can access public members of base class from outside with public inheritance)
    cout<<endl;
    cout<<"About Officer: \n";
    o.showinfo();
    cout<<"I am a ";
    o.showattributes();
    cout<<endl;
    ///o.Staff::showattributes(); (cannot access any member of the base class outside the derived class as officer class has private inheritance)
    cout<<"About Typist: \n";
    ty.showinfo();
    cout<<"I am a ";
    ty.showattributes();
    ///ty.Staff::showattributes(); (cannot access any member of the base class outside the derived class as officer class has protected inheritance)
    cout<<endl;
    cout<<"About Regular Typist: \n";
    r.showinfo();
    cout<<"I am a ";
    r.showattributes();
    cout<<endl;
    cout<<"About Casual Typist: \n";
    c.showinfo();
    cout<<"I am a ";
    c.showattributes();
    cout<<endl;
    return 0;
}
