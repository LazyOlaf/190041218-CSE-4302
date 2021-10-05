#include<iostream>
using namespace std;
const int LIMIT = 26;

template<class T>
class safearay
{
private:
    T arr[LIMIT];
public:
    class index
    {
    public:
        int in;
        index(int ind)
        {
            in=ind;
        }
    };
    T& operator [](int n)
    {
        if( n< 0 || n>=LIMIT )
        {
            throw index(n);
        }
        return arr[n];
    }
};

int main()
{
    safearay<int>sa1;
    safearay<char>ch;
    try
    {

        for(int j=0; j<LIMIT; j++)
            sa1[j] = j*10;
        for(int j=0; j<LIMIT; j++)
        {
            int temp = sa1[j];
            cout << "Element "<< j << " is " << temp << endl;
        }
        for(int j=0; j<LIMIT; j++)
            ch[j] = 'a'+j;
        for(int j=0; j<LIMIT; j++)
        {
            char temp = ch[j];
            cout << "Element " << j << " is " << temp << endl;
        }
        char temp=ch[-1];
        cout<<temp;
    }
    catch(safearay<int>::index i)
    {
        cout<<"Integer array out of bound at index: "<<i.in;
    }
    catch(safearay<char>::index i)
    {
        cout<<"Character array out of bound at index: "<<i.in;
    }
    return 0;
}
