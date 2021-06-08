#include<iostream>
using namespace std;

class Medicine
{
private:
    char * Name;
    char * genericName;
    double discountPercent;
    double unitPrice;
public:
    Medicine() :discountPercent(5), unitPrice(0)
    {

    }
    void assignName(char* name, char* genName)
    {
        Name=name;
        genericName=genName;
    }
    void assignPrice(double price)
    {
        unitPrice=price;
    }
    void setDiscountPercent(double percent)
    {
        discountPercent=percent;
    }
    double getSellingPrice(int nos)
    {
        return nos*(unitPrice-(unitPrice*discountPercent/100));
    }
    void display()
    {
        cout<<Name<<" ("<<genericName<<") has a unit price BDT "<<unitPrice<<". Current discount "<<discountPercent<<"%. ";
    }
};

int main()
{
    Medicine M;
    char * name= new char[20];
    char * genName= new char[20];
    double price, percent;
    int nos;
    cout<<"Enter the name of the medicine: ";
    cin>>name;
    cout<<"Enter the generic name of the medicine: ";
    cin>>genName;
    M.assignName(name,genName);
    M.display();
    cout<<"The selling price is BDT "<<M.getSellingPrice(nos)<<endl;
    while(1)
    {
        cout<<"Enter the unit price of the medicine (Cannot be a negative value): ";
        cin>>price;
        if(price>=0)
            break;
    }
    while(1)
    {
        cout<<"Enter the discount percent of the medicine (range:0-45%): ";
        cin>>percent;
        if(percent<=45 && percent>=0)
            break;
    }
    cout<<"Enter number of sales: ";
    cin>>nos;
    M.assignName(name,genName);
    M.assignPrice(price);
    M.setDiscountPercent(percent);
    M.display();
    cout<<"The selling price is "<<M.getSellingPrice(nos);
    return 0;
}
