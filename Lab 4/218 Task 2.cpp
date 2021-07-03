#include<bits/stdc++.h>
using namespace std;

class Rectangle
{
private:
    float length, width;
public:
    Rectangle(float l=1, float w=1):length(l),width(w)
    {

    }
    float perimeter()
    {
        return length+width;
    }
    float area()
    {
        return length*width;
    }
    float diagonal()
    {
        return sqrt(powl(length,2)+powl(width,2));
    }
    float angle()
    {
        return (180*(atan(length/width))/3.1416);
    }
    void getinfo()
    {
        cout<<"Enter length: ";
        cin>>length;
        cout<<"Enter width: ";
        cin>>width;
    }
    void setinfo(float l, float w)
    {
        if(l<1 || l>=20)
            cout<<"Invalid length!"<<endl;
        if(w<1 || w>=20)
            cout<<"Invalid width!"<<endl;
        if(l>=1 && l<20 && w>=1 && w<20)
        {
            length=l;
            width=w;
        }
    }
};

int main()
{
    Rectangle r1;
    Rectangle r2(5, 10);
    cout<<r1.perimeter()<<" "<<r1.area()<<" "<<r1.diagonal()<<" "<<r1.angle()<<endl;
    cout<<r2.perimeter()<<" "<<r2.area()<<" "<<r2.diagonal()<<" "<<r2.angle()<<endl;
    r2.setinfo(6,5);
    cout<<r2.perimeter()<<" "<<r2.area()<<" "<<r2.diagonal()<<" "<<r2.angle()<<endl;
    r1.getinfo();
    cout<<r1.perimeter()<<" "<<r1.area()<<" "<<r1.diagonal()<<" "<<r1.angle()<<endl;
    return 0;
}
