#include<iostream>
using namespace std;

class RationalNumber
{
private:
    int num;
    int den;
public:
    void Assign(int numerator,int denominator)
    {
        if(denominator!=0)
        {
            num=numerator;
            den=denominator;
        }
        else
            cout<<"Invalid input.\n";
    }
    double convert()
    {
        return (double)num/(double)den;
    }
    void invert()
    {
        if(num!=0)
        {
            int temp=num;
            num=den;
            den=temp;
        }
        else
            cout<<"Invalid input.\n";
    }
    void print()
    {
        cout<<"The Rational Number is "<<num<<"/"<<den<<endl;
    }
};

int main()
{
    RationalNumber R;
    int p, q;
    cin>>p>>q;
    R.Assign(p,q);
    if(q!=0)
    {
        R.print();
        cout<<"and the value is "<<R.convert()<<endl;
        cout<<"For invert operation: \n";
        R.invert();
        if(p!=0)
       {
           R.print();
           cout<<"and the value is "<<R.convert()<<endl;
       }
    }
    return 0;
}
