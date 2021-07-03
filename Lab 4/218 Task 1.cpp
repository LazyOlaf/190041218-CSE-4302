#include<bits/stdc++.h>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string accountHolderName;
    string accountType;
    float currentBalance;
    float minimumBalance;
public:
    BankAccount()
    {
        cout<<"Set up an account!"<<endl;
    }
    BankAccount(int number, string name, string type, float balance, float minimum): accountNumber(number), accountHolderName(name), accountType(type), currentBalance(balance), minimumBalance(minimum)
    {
        cout<<"Account created!"<<endl;
    }
    ~BankAccount()
    {
        cout<<"Account of "<<accountHolderName<<" with account no "<<accountNumber<<" is destroyed with a balance BDT "<<currentBalance<<endl;

    }
    void getInfo()
    {
        cout<<"Account number: ";
        cin>>accountNumber;
        cout<<"Account holder name: ";
        cin>>accountHolderName;
        cout<<"Account type: ";
        cin>>accountType;
        cout<<"Current Balance: ";
        cin>>currentBalance;
        cout<<"Minimum Balance: ";
        cin>>minimumBalance;
    }
    void showInfo()
    {
        cout<<"Account number: "<<accountNumber<<endl<<"Account holder name: "<<accountHolderName<<endl<<"Account type: "<<accountType<<endl;
        cout<<"Current Balance: "<<currentBalance<<endl<<"Minimum Balance: "<<minimumBalance<<endl;
    }
    void deposit(float amount)
    {
        currentBalance+=amount;
    }
    void withdrawal(float amount)
    {
        if(currentBalance-amount>=minimumBalance)
            currentBalance-=amount;
        else
            cout<<"Not enough balance for withdrawal!"<<endl;
    }
    void giveInterest(float interest=.03)
    {
        int addition=(currentBalance*interest);
        int deduction=addition*.1;
        currentBalance+=(addition-deduction);
    }
};

int main()
{
    BankAccount b1(1234,"abc","saving",29483.5,555.5);
    BankAccount b2;
    b2.getInfo();
    b1.showInfo();
    b2.showInfo();
    b1.deposit(553.3);
    b1.showInfo();
    b2.withdrawal(242.4);
    b2.showInfo();
    b1.giveInterest();
    b1.showInfo();
    b1.giveInterest(.1);
    b1.showInfo();
    return 0;
}
