#include<bits/stdc++.h>
using namespace std;

class Seat
{
private:
    string comfortability;
    string seat_warmer;
public:
    Seat():comfortability("No information available!"), seat_warmer("No information available!")
    {

    }
    Seat(string s1, string s2):comfortability(s1), seat_warmer(s2)
    {

    }
    ~Seat()
    {

    }
    void set_seat(string s1, string s2)
    {
        comfortability=s1;
        seat_warmer=s2;
    }
    string get_comfortability()
    {
        return comfortability;
    }
    string get_seat_warmer()
    {
        return seat_warmer;
    }
    Seat get_seat()
    {
        Seat temp;
        temp.comfortability=comfortability;
        temp.seat_warmer=seat_warmer;
        return temp;
    }
};

class Wheel
{
private:
    float radius;
public:
    Wheel():radius(1)
    {

    }
    Wheel(float r):radius(r)
    {

    }
    ~Wheel()
    {

    }
    void set_radius(float f)
    {
        radius=f;
    }
    float get_radius()
    {
        return radius;
    }
};

class Engine
{
private:
    float maximum_fuel_consumption_rate;
    float maximum_energy_production_rate;
    float avarage_rpm;
public:
    Engine():maximum_fuel_consumption_rate(0), maximum_energy_production_rate(0), avarage_rpm(0)
    {

    }
    Engine(float fc, float ep, float rpm):maximum_fuel_consumption_rate(fc), maximum_energy_production_rate(ep), avarage_rpm(rpm)
    {

    }
    ~Engine()
    {

    }
    void set_engine(float con, float pro, float rpm)
    {
        maximum_fuel_consumption_rate=con;
        maximum_energy_production_rate=pro;
        avarage_rpm=rpm;
    }
    float get_max_fc()
    {
        return maximum_fuel_consumption_rate;
    }
    float get_max_ep()
    {
        return maximum_energy_production_rate;
    }
    float get_avg_rpm()
    {
        return avarage_rpm;
    }
    Engine get_engine()
    {
        Engine temp;
        temp.maximum_fuel_consumption_rate=maximum_fuel_consumption_rate;
        temp.maximum_energy_production_rate=maximum_energy_production_rate;
        temp.avarage_rpm=avarage_rpm;
        return temp;
    }
};

class Door
{
private:
    string opening_mode;
public:
    Door():opening_mode("No information available!")
    {

    }
    Door(string s):opening_mode(s)
    {

    }
    ~Door()
    {

    }
    void set_door(string s)
    {
        opening_mode=s;
    }
    string get_door()
    {
        return opening_mode;
    }
};

class Truck
{
private:
    Seat s[2];
    Wheel w[6];
    Engine e;
    Door d[2];
    float maximum_acceleration, fuel_capacity, load_capacity;
public:
    Truck()
    {

    }
    Truck(string s1, string s2, string s3, string s4, float f1, float f2, float f3, float f4, float f5, float f6, float f7, float f8, float f9, string s5, string s6, float f10, float f11, float f12): e(f7,f8,f9),maximum_acceleration(f10), fuel_capacity(f11), load_capacity(f12)
    {
        s[0].set_seat(s1, s2);
        s[1].set_seat(s3, s4);
        w[0].set_radius(f1);
        w[1].set_radius(f2);
        w[2].set_radius(f3);
        w[3].set_radius(f4);
        w[4].set_radius(f5);
        w[5].set_radius(f6);
        d[0].set_door(s5);
        d[1].set_door(s6);
    }
    ~Truck()
    {

    }
    void set_truck(string s1, string s2, string s3, string s4, float f1, float f2, float f3, float f4, float f5, float f6, float f7, float f8, float f9, string s5, string s6, float ac, float fc, float lc)
    {
        s[0].set_seat(s1,s2);
        s[1].set_seat(s3,s4);
        w[0].set_radius(f1);
        w[1].set_radius(f2);
        w[2].set_radius(f3);
        w[3].set_radius(f4);
        w[4].set_radius(f5);
        w[5].set_radius(f6);
        e.set_engine(f7,f8,f9);
        d[0].set_door(s5);
        d[1].set_door(s6);
        maximum_acceleration=ac;
        fuel_capacity=fc;
        load_capacity=lc;
    }
    Truck get_truck()
    {
        Truck temp;
        temp.s[0]=s[0].get_seat();
        temp.s[1]=s[1].get_seat();
        temp.w[0]=w[0].get_radius();
        temp.w[1]=w[1].get_radius();
        temp.w[2]=w[2].get_radius();
        temp.w[3]=w[3].get_radius();
        temp.w[4]=w[4].get_radius();
        temp.w[5]=w[5].get_radius();
        temp.e=e.get_engine();
        temp.d[0]=d[0].get_door();
        temp.d[1]=d[1].get_door();
        temp.maximum_acceleration=maximum_acceleration;
        temp.fuel_capacity=fuel_capacity;
        temp.load_capacity=load_capacity;
        return temp;
    }
    void display()
    {
        cout<<endl<<"Displaying truck information...\n";
        cout<<"The truck has 2 seats.\n1st seat is "<<s[0].get_comfortability()<<".\nDoes it have seat warmers? "<<s[0].get_seat_warmer()<<endl;
        cout<<"2nd seat is "<<s[1].get_comfortability()<<".\nDoes it have seat warmers? "<<s[1].get_seat_warmer()<<endl;
        cout<<"The truck has 6 wheels.\nThe radius of the wheels are: "<<w[0].get_radius()<<" inches, "<<w[1].get_radius()<<" inches, "<<w[2].get_radius()<<" inches, "<<w[3].get_radius()<<" inches, "<<w[4].get_radius()<<" inches, "<<w[5].get_radius()<<" inches."<<endl;
        cout<<"The truck has 1 engine.\nMaximum fuel consumption rate of the engine: "<<e.get_max_fc()<<endl<<"Maximum energy production rate: "<<e.get_max_ep()<<endl<<"Average RPM: "<<e.get_avg_rpm()<<endl;
        cout<<"The truck has 2 doors.\n1 of the doors opens in "<<d[0].get_door()<<endl<<"The other one opens in "<<d[1].get_door()<<endl;
        cout<<"Maximum acceleration of the car: "<<maximum_acceleration<<endl;
        cout<<"Fuel capacity :"<<fuel_capacity<<endl<<"Load capacity: "<<load_capacity<<endl;
    }
};

int main()
{
    Truck t("Comfy","Yes","uncomfortable","NO", 15, 15, 15, 15, 18, 18, 78, 83, 10, "Side ways!", "upward ways!", 10, 200, 50);
    t.display();
    Truck t1, t3;
    t1.set_truck("Pleasant","Yes","uncomfortable","NO", 18, 18, 18, 18, 20, 20, 76, 85, 14, "Side ways!", "upward ways!", 13, 155, 35);
    t3=t1.get_truck();
    t3.display();
    return 0;
}
