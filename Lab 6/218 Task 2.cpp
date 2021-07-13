#include<bits/stdc++.h>
using namespace std;

class Coordinate
{
private:
    float abscissa;
    float ordinate;
public:
    Coordinate()
    {

    }
    Coordinate(float ab, float ord):abscissa(ab), ordinate(ord)
    {

    }
    ~Coordinate()
    {

    }
    ///get distance from point
    float getDistance(Coordinate C)
    {
        return sqrt(powl((abscissa-C.abscissa),2)+powl((ordinate-C.ordinate),2));
    }
    ///get distance from origin
    float getDistance()
    {
        return sqrt(powl(abscissa,2)+powl(ordinate,2));
    }
    ///changes the abscissa
    void move_x(float val)
    {
        abscissa+=val;
    }
    ///changes the ordinate
    void move_y(float val)
    {
        ordinate+=val;
    }
    ///changes both co-ordinates
    void Move(float val)
    {
        move_x(val);
        move_y(val);
    }
    ///greater
    bool operator >(Coordinate C)
    {
        return getDistance()>C.getDistance();
    }
    ///lesser
    bool operator <(Coordinate C)
    {
        return getDistance()<C.getDistance();
    }
    ///greater-equal
    bool operator >=(Coordinate C)
    {
        return getDistance()>=C.getDistance();
    }
    ///lesser-equal
    bool operator <=(Coordinate C)
    {
        return getDistance()<=C.getDistance();
    }
    ///equal
    bool operator ==(Coordinate C)
    {
        return getDistance()==C.getDistance();
    }
    ///not equal
    bool operator !=(Coordinate C)
    {
        return getDistance()!=C.getDistance();
    }
    ///prefix increment both co-ordinates
    Coordinate operator ++()
    {
        Coordinate temp;
        temp.abscissa=++abscissa;
        temp.ordinate=++ordinate;
        return temp;
    }
    ///postfix increment both co-ordinates
    Coordinate operator ++(int)
    {
        Coordinate temp;
        temp.abscissa=abscissa++;
        temp.ordinate=ordinate++;
        return temp;
    }
    ///prefix decrement both co-ordinates
    Coordinate operator --()
    {
        Coordinate temp;
        temp.abscissa=--abscissa;
        temp.ordinate=--ordinate;
        return temp;
    }
    ///postfix decrement both co-ordinates
    Coordinate operator --(int)
    {
        Coordinate temp;
        temp.abscissa=abscissa--;
        temp.ordinate=ordinate--;
        return temp;
    }
    void display()
    {
        cout<<"\nAbscissa: "<<abscissa<<endl;
        cout<<"Ordinate: "<<ordinate<<endl;
    }
    void display(bool x)
    {
        if(x==true)
            cout<<"TURE!"<<endl;
        else
            cout<<"FALSE!"<<endl;
    }
};

int main()
{
    Coordinate c1(-1,-1);
    Coordinate c2(1,1);
    Coordinate c3;
    cout<<"Distance between c1 and origin: "<<c1.getDistance()<<endl;
    cout<<"Distance between c1 and c2: "<<c1.getDistance(c2)<<endl;
    cout<<"c1==c2? ";
    c1.display(c1==c2);
    cout<<"c1!=c2? ";
    c1.display(c1!=c2);
    c1.move_x(3.2);
    cout<<"Co-ordinates of c1 after moving the point by 3.2 on x-axis: ";
    c1.display();
    c2.move_y(3.2);
    cout<<"Co-ordinates of c2 after moving the point by 3.2 on y-axis: ";
    c2.display();
    cout<<"c1>c2? ";
    c2.display(c1>c2);
    c3=c1--;
    cout<<"Co-ordinates of c1 after postfix decrement: ";
    c1.display();
    cout<<"Co-ordinates of c3 after postfix decrement: ";
    c3.display();
    cout<<"c1<c3? ";
    c1.display(c1<c3);
    c3=++c2;
    cout<<"Co-ordinates of c2 after prefix increment: ";
    c2.display();
    cout<<"Co-ordinates of c3 after prefix increment: ";
    c3.display();
    cout<<"c3>=c2? ";
    c3.display(c3>=c2);
    c1.Move(2);
    cout<<"Co-ordinates of c1 after moving points both on x-axis and y-axis: ";
    c1.display();
    cout<<"c1<=c2? ";
    c1.display(c1<=c2);
    c3=c1++;
    cout<<"Co-ordinates of c1 after postfix increment: ";
    c1.display();
    cout<<"Co-ordinates of c3 after postfix increment: ";
    c3.display();
    c3=--c2;
    cout<<"Co-ordinates of c2 after prefix decrement: ";
    c2.display();
    cout<<"Co-ordinates of c3 after prefix decrement: ";
    c3.display();
    return 0;
}
