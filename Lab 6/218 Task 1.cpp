#include<iostream>
using namespace std;

class Counter
{
private:
    int stepValue;
    int Count;
public:
    Counter(): Count(0), stepValue(1)
    {

    }
    ~Counter()
    {

    }
    void setIncrementStep(int step_val)
    {
        if(step_val>=0)
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
    Counter operator + (Counter C)
    {
        Counter temp;
        temp.Count=Count+C.Count;
        temp.stepValue=min(stepValue, C.stepValue);
        return temp;
    }
    Counter operator + (int var)
    {
        Counter temp;
        temp.Count=Count+var;
        temp.stepValue=stepValue;
        return temp;
    }
    friend Counter operator +(int var, Counter C);
    void operator += (Counter C)
    {
        Count+=C.Count;
        stepValue=C.stepValue;
    }
    Counter operator ++ (int)
    {
        Counter temp;
        temp.Count=Count;
        temp.stepValue=stepValue;
        increment();
        return temp;
    }
    Counter operator ++ ()
    {
        increment();
        Counter temp;
        temp.Count=Count;
        temp.stepValue=stepValue;
        return temp;
    }
};

Counter operator + (int var, Counter C)
{
    Counter temp;
    temp.Count=var+C.Count;
    temp.stepValue=C.stepValue;
    return temp;
}

int main()
{
    Counter c1, c2, c3;
    int step_val;
    cout<<"Enter the step value for c2: ";
    cin>>step_val;
    c2.setIncrementStep(step_val);
    c2.increment();
    cout<<"c2 Count after incrementing by step value="<<step_val<<" once from initial value 0: "<<c2.getCount()<<endl;
    c2.resetCount();
    c2.increment();
    c2.increment();
    cout<<"c2 Count after resetting back to 0 and incrementing twice afterwards by step value="<<step_val<<": "<<c2.getCount()<<endl;
    c3.setIncrementStep(2);
    c3.increment();
    c3.increment();
    c3.increment();
    cout<<"c3 Count after incrementing thrice by step value=2 from initial value 0: "<<c3.getCount()<<endl;
    c1=c2+c3;
    cout<<"c1 Count after performing c1=c2+c3 operation: "<<c1.getCount()<<endl;
    cout<<"c2 Count after performing c1=c2+c3 operation: "<<c2.getCount()<<endl;
    cout<<"c3 Count after performing c1=c2+c3 operation: "<<c3.getCount()<<endl;
    c1.increment();
    cout<<"c1 Count after incrementing c1 by step value="<<min(2,step_val)<<" after performing c1=c2+c3 operation: "<<c1.getCount()<<endl;
    cout<<"c2 Count after incrementing c1 by step value="<<min(2,step_val)<<" after performing c1=c2+c3 operation: "<<c2.getCount()<<endl;
    cout<<"c3 Count after incrementing c1 by step value="<<min(2,step_val)<<" after performing c1=c2+c3 operation:: "<<c3.getCount()<<endl;
    c1=c2+5;
    cout<<"c1 Count after performing c1=c2+5 operation: "<<c1.getCount()<<endl;
    cout<<"c2 Count after performing c1=c2+5 operation: "<<c2.getCount()<<endl;
    c1.increment();
    cout<<"c1 Count after incrementing c1 by step value="<<step_val<<" after performing c1=c2+5 operation: "<<c1.getCount()<<endl;
    cout<<"c2 Count after incrementing c1 by step value="<<step_val<<" after performing c1=c2+5 operation: "<<c2.getCount()<<endl;
    c1=5+c2;
    cout<<"c1 Count after performing c1=5+c2 operation: "<<c1.getCount()<<endl;
    cout<<"c2 Count after performing c1=5+c2 operation: "<<c2.getCount()<<endl;
    c1.increment();
    cout<<"c1 Count after incrementing c1 by step value="<<step_val<<" after performing c1=5+c2 operation: "<<c1.getCount()<<endl;
    cout<<"c2 Count after incrementing c1 by step value="<<step_val<<" after performing c1=5+c2 operation: "<<c2.getCount()<<endl;
    c1+=c2;
    cout<<"c1 Count after performing c1+=c2 operation: "<<c1.getCount()<<endl;
    cout<<"c2 Count after performing c1+=c2 operation: "<<c2.getCount()<<endl;
    c1.increment();
    cout<<"c1 Count after incrementing c1 by step value="<<step_val<<" after performing c1+=c2 operation: "<<c1.getCount()<<endl;
    cout<<"c2 Count after incrementing c1 by step value="<<step_val<<" after performing c1+=c2 operation: "<<c2.getCount()<<endl;
    c1=c2++;
    cout<<"c1 Count after performing c1=c2++ operation: "<<c1.getCount()<<endl;
    cout<<"c2 Count after performing c1=c2++ operation: "<<c2.getCount()<<endl;
    c1.increment();
    cout<<"c1 Count after incrementing c1 by step value="<<step_val<<" after performing c1=c2++ operation: "<<c1.getCount()<<endl;
    cout<<"c2 Count after incrementing c1 by step value="<<step_val<<" after performing c1=c2++ operation: "<<c2.getCount()<<endl;
    c1=++c2;
    cout<<"c1 Count after performing c1=++c2 operation: "<<c1.getCount()<<endl;
    cout<<"c2 Count after performing c1=++c2 operation: "<<c2.getCount()<<endl;
    c1.increment();
    cout<<"c1 Count after incrementing c1 by step value="<<step_val<<" after performing c1=++c2 operation: "<<c1.getCount()<<endl;
    cout<<"c2 Count after incrementing c1 by step value="<<step_val<<" after performing c1=++c2 operation: "<<c2.getCount()<<endl;
    return 0;
}
