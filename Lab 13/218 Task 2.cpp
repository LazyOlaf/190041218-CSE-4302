#include<iostream>
using namespace std;

namespace my_namespace
{
    const double PI=3.1416;
    double radius=5;
}

int radius=2;

int main()
{
    cout<<"Number of radius in a human body: "<<radius<<endl;
    cout<<"Area: "<<my_namespace::PI*my_namespace::radius*my_namespace::radius;
    return 0;
}
