#include<iostream>
using namespace std;
const int LIMIT = 26;

template<class T>
class safearay
{
private:
    T arr[LIMIT];
public:
    T& operator [](int n)
    {
        if( n< 0 || n>=LIMIT )
        {
            cout << "\nIndex out of bounds";
            exit(1);
        }
        return arr[n];
    }
};

int main()
{
    safearay<int>sa1;
    for(int j=0; j<LIMIT; j++)
        sa1[j] = j*10;
    for(int j=0; j<LIMIT; j++)
    {
        int temp = sa1[j];
        cout << "Element "<< j << " is " << temp << endl;
    }
    safearay<char>ch;
    for(int j=0; j<LIMIT; j++)
        ch[j] = 'a'+j;
    for(int j=0; j<LIMIT; j++)
    {
        char temp = ch[j];
        cout << "Element " << j << " is " << temp << endl;
    }
    return 0;
}
