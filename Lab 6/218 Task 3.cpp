#include<bits/stdc++.h>
using namespace std;

class FLOAT
{
private:
    float data;
public:
    FLOAT()
    {

    }
    FLOAT(float d):data(d)
    {

    }
    ~FLOAT()
    {

    }
    FLOAT operator + (FLOAT F)
    {
        FLOAT temp;
        temp.data=data+F.data;
        return temp;
    }
    FLOAT operator -(FLOAT F)
    {
        FLOAT temp;
        temp.data=data-F.data;
        return temp;
    }
    FLOAT operator *(FLOAT F)
    {
        FLOAT temp;
        temp.data=data*F.data;
        return temp;
    }
    FLOAT operator /(FLOAT F)
    {
        FLOAT temp;
        temp.data=data/F.data;
        return temp;
    }
    void display()
    {
        cout<<data<<endl;
    }
};

int main()
{
    FLOAT f1(2.5);
    FLOAT f2(3.1);
    FLOAT f3;
    cout<<"F1+F2= ";
    f3=f1+f2;
    f3.display();
    cout<<"F1-F2= ";
    f3=f1-f2;
    f3.display();
    cout<<"F1*F2: ";
    f3=f1*f2;
    f3.display();
    cout<<"F1/f2= ";
    f3=f1/f2;
    f3.display();
    return 0;
}
