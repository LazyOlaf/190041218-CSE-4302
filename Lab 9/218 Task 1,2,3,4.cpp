#include <iostream>
#include <string>
using namespace std;

enum class Material {Wood,Board,Steel,foam};
class Furniture
{
protected:
    double price;
    double discount;
    Material madeof;
public:

    Furniture(double p,double d,Material m):price(0),discount(0),madeof(Material::Wood)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
    }
    void setPrice(double val)
    {
        if(val>0)
            price=val;
    }
    void setDiscount(double val)
    {
        if(val<=price)
            discount=val;
    }
    void setMadeof(Material val)
    {
        madeof=val;
    }
    void setDiscountPercentage(double p)
    {
        discount=p*price/100;
    }
    string getMadeof()
    {
        if(madeof==Material::Wood)
            return string("Wood");
        else if(madeof==Material::Board)
            return string("Board");
        else if(madeof==Material::Steel)
            return string("Steel");
        else
            return string("");
    }
    double getDiscountedPrice()
    {
        return price-discount;
    }
    virtual void productDetails()=0;
};

enum class BedSize {Single,SemiDouble,Double};

class Bed:public Furniture
{
protected:
    BedSize Size;
public:
    Bed():Furniture(0,0,Material::Wood),Size(BedSize::Single)
    {

    }
    Bed(double p,double d,Material m,BedSize s):Furniture(p,d,m)
    {
        Size=s;
    }
    ~Bed()
    {

    }
    string getSize()
    {
        if(Size==BedSize::Single)
            return string("Single");
        else if(Size==BedSize::SemiDouble)
            return string("Semi Double");
        else if(Size==BedSize::Double)
            return string("Double");
        else
            return string("");
    }
    void productDetails()
    {
        cout<<"---------------------------------------------\n";
        cout<<"Product name: Bed\n";
        cout<<"Regular Price: "<<price<<endl;
        cout<<"Discounted Price: "<<price-discount<<endl;
        cout<<"Material: "<<getMadeof()<<endl;
        cout<<"Bed Size: "<<getSize()<<endl;
        cout<<"###################################################\n";
    }
};

enum class SofaSize {One,Two,Three,Four,Five};

class Sofa:public Furniture
{
private:
    Furniture *f;
protected:
    SofaSize seat;
public:
    void a()
    {
        f = new Bed();
    }
    Sofa(double p,double d,Material m, SofaSize s):Furniture(p,d,m)
    {
        seat=s;
    }
    ~Sofa()
    {
        delete f;
    }
    string getSize()
    {
        if(seat==SofaSize::One)
            return string("One");
        else if(seat==SofaSize::Two)
            return string("Two");
        else if(seat==SofaSize::Three)
            return string("Three");
        else if(seat==SofaSize::Four)
            return string("Four");
        else if(seat==SofaSize::Five)
            return string("Five");
        else
            return string("");
    }
    void productDetails()
    {
        cout<<"---------------------------------------------\n";
        cout<<"Product name: Sofa\n";
        cout<<"Regular Price: "<<price<<endl;
        cout<<"Discounted Price: "<<price-discount<<endl;
        cout<<"Material: "<<getMadeof()<<endl;
        cout<<"Seat Number: "<<getSize()<<endl;
        cout<<"###################################################\n";
    }
};

enum class ChairCount {Two,Four,Six};

class DiningTable:public Furniture
{
protected:
    ChairCount chair;
public:
    DiningTable():Furniture(0,0,Material::Wood),chair(ChairCount::Six)
    {

    }
    DiningTable(double p,double d,Material m,ChairCount c):Furniture(p,d,m)
    {
        chair=c;
    }
    ~DiningTable()
    {

    }
    string getCount()
    {
        if(chair==ChairCount::Two)
            return string("Two");
        else if(chair==ChairCount::Four)
            return string("Four");
        else if(chair==ChairCount::Six)
            return string("Six");
        else
            return string("");
    }
    void productDetails()
    {
        cout<<"---------------------------------------------\n";
        cout<<"Product name: Dining Table\n";
        cout<<"Regular Price: "<<price<<endl;
        cout<<"Discounted Price: "<<price-discount<<endl;
        cout<<"Material: "<<getMadeof()<<endl;
        cout<<"Number of chairs: "<<getCount()<<endl;
        cout<<"###################################################\n";
    }
};

/**task 4
sort_furniture_discount will sort the array in descending order based on their discount price.
You may need to add some member functions
**/

void order(Furniture ** f1, Furniture ** f2)
{
    if((*f1)->getDiscountedPrice()<(*f2)->getDiscountedPrice())
    {
        Furniture *temp=*f1;
        *f1=*f2;
        *f2=temp;
    }
}

void sort_furniture_discount(Furniture *furnitures[],int no_of_furnitures)
{
    int i, j;
    for(i=0; i<no_of_furnitures-1; i++)
    {
        for(j=i+1; j<no_of_furnitures; j++)
        {
            order(furnitures+i,furnitures+j);
        }
    }
}

int main()
{
    Furniture* f_list[100];

    /**
        task 1
        So that following lines can be executed without error
    */
    f_list[0] = new Bed(10000,123,Material::Wood,BedSize::Single);
    f_list[1] = new Sofa(11000,234,Material::Steel,SofaSize::Five);
    f_list[2] = new DiningTable(13000,345,Material::Wood,ChairCount::Two);
    f_list[3] = new Bed(10090,123,Material::Wood,BedSize::Single);

    /**task 1 ends here*/

    /**
        task 2
        So that following lines can be executed without error

        task 3 (Modify productDetails)
    */
    f_list[2]->setDiscountPercentage(30);
    for(int i=0; i<4; i++)
    {
        f_list[i]->productDetails();
    }

    /**task 2 ends here*/
    /**task 3 ends here*/

    /**task 4
    So that following lines can be executed without error
    */
    sort_furniture_discount(f_list,4);
    for(int i=0; i<4; i++)
    {
        f_list[i]->productDetails();
    }
    /**task 4 ends here*/

}
