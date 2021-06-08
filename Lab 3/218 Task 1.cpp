#include<iostream>
using namespace std;

class Counter
{
private:
    int stepValue;
    int Count;
public:
    Counter(): Count(0)
    {

    }
    void setIncrementStep(int step_val)
    {
        stepValue=step_val;
    }
    int getCount()
    {
        return Count;
    }
    void increment()
    {
        Count+=stepValue;
    }
    void resetCount()
    {
        Count=0;
    }
};

int main()
{
    Counter C;
    int step_val;
    cout<<"Enter the step value: ";
    cin>>step_val;
    C.setIncrementStep(step_val);
    C.increment();
    cout<<"Count: "<<C.getCount()<<endl;
    C.resetCount();
    C.setIncrementStep(step_val);
    C.increment();
    C.increment();
    cout<<"Count: "<<C.getCount();
    return 0;
}
