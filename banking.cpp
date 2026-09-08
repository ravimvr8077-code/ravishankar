#include<iostream>
#include<string>
using namespace std;

class BankAccount
{
    private:
        string owner;
        double balance;
        
public:

       void openAccount(string name, double intial)
        {
            owner = name;
            if (intial >= 0)
            {
                balance = intial;
            }
            else
            {
                balance = 0;
            }
        }

        void deposit(double amount)
        {
            if (amount > 0)
            {
                balance += amount;
            
            }
            
        }
    
bool withdraw(double amount)
        {
            if (amount > 0 && amount <= balance)
            {
                balance -= amount;
                return true;
            }
            else
            {
                return false;
            }
        }
        string getOwner()
        {
            return owner;
        }
        double getBalance()
        {
            return balance;
        }
    };
       int main()
        {
            BankAccount account;
            string name;
            double initialDeposit;
            double depositAmount;
            double withdrawAmount;
            cout<<"enter account holder name: ";
            getline(cin, name);
            cout<<"enter initial deposit amount: ";
            cin>>initialDeposit;
            account.openAccount(name, initialDeposit);
            cout<<"enter amount to deposit: ";
            cin>>depositAmount;
            account.deposit(depositAmount);
            cout<<"enter amount to withdraw: ";
            cin>>withdrawAmount;
            if(account.withdraw(withdrawAmount))
            {
                cout<<"withdrawal successful."<<endl;
            }
            else
            {
                cout<<"withdrawal failed. Insufficient funds."<<endl;
            }
        cout<<"\n ====account details===="<<endl;
        cout<<"account holder name: "<<account.getOwner()<<endl;
        cout<<"final balance: "<<account.getBalance()<<endl;
        return 0;
        }