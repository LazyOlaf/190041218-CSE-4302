#include<iostream>
using namespace std;

template<class T>

T amax(T* arr, int Size)
{
    T largest=-1000000;
    for(int i=0; i<Size; i++)
    {
        if(arr[i]>largest)
            largest=arr[i];
    }
    return largest;
}

int main()
{
    float fArr[] = {1.5, 3.2, 2.4, 1.3, 1.6, 3.1};
    int intArr[] = {1, 3, 5, 9, 11, 13};
    cout << "MAX in fArray: " <<amax(fArr, 6);
    cout << "\nMAX in intArray: " <<amax(intArr, 6);
    cout << endl;
    return 0;
}
