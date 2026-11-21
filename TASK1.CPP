#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Account;
class Auditor { public: void show(const Account &a); };            // friend class
class Register { unsigned char v; public:                           // 8-bit register
    void write(unsigned char x){ v=x; } unsigned char read() const { return v; } void reset(){ v=0; } };
class Account {
    string owner; double balance; int id; char *tag; static int count;
    friend class Auditor;
public:
    Account(string o, double b=0) : owner(o), balance(b>=0?b:0), id(++count)   // default argument
    { tag=new char[o.size()+1]; strcpy(tag,o.c_str()); cout<<"Created A"<<id<<endl; }
    Account() : Account("Guest") {}                                 // delegating constructor
    Account(const Account &a) : owner(a.owner), balance(a.balance), id(++count)  // deep copy
    { tag=new char[strlen(a.tag)+1]; strcpy(tag,a.tag); }
    ~Account() { delete[] tag; cout<<"Destroyed A"<<id<<endl; }
    Account& deposit(double a) { if(a>0) this->balance+=a; return *this; }  // method chaining
    bool withdraw(double a) { if(a>0 && a<=balance){ balance-=a; return true; } return false; }
    double getBalance() const { return balance; }
    string getOwner() const { return owner; }
    static int created() { return count; }                          // static function
};
int Account::count=0;
void Auditor::show(const Account &a) { cout<<"Audit A"<<a.id<<" "<<a.owner<<" Rs."<<a.balance<<endl; }
inline double charge(double amt) { return amt*0.01; }               // inline + overloading
double charge(double amt,int n) { return charge(amt)*n; }
void swapv(double *x,double *y) { double t=*x; *x=*y; *y=t; }       // pass by pointer
void minMax(const double a[],int n,double &mn,double &mx)           // pass by reference
{ mn=mx=a[0]; for(int i=1;i<n;i++){ if(a[i]<mn) mn=a[i]; if(a[i]>mx) mx=a[i]; } }
void bonus(Account &a) { a.deposit(100); }                          // changes original
void tryBonus(Account a) { a.deposit(100); }                        // copy only
void nameInfo(const string &s) {                                    // string handling
    cout<<"Name: "; for(char c:s) cout<<(char)toupper(c);
    bool pal=true;
    for(int i=0,j=(int)s.size()-1;i<j;++i,--j) if(tolower(s[i])!=tolower(s[j])){ pal=false; break; }
    cout<<" (length "<<s.length()<<", "<<(pal?"palindrome":"not palindrome")<<", "
        <<(s.find("an")!=string::npos?"contains 'an'":"no 'an'")<<")"<<endl;
}
int main() {
    string name; double init, dep, wd;
    cout<<"Enter name and initial deposit: "; cin>>name>>init;
    Account a(name,init), g;
    { Account temp("Temp",5); cout<<"...block scope...\n"; }         // destructor on scope exit
    cout<<"Enter deposit and withdraw amounts: "; cin>>dep>>wd;
    a.deposit(dep).deposit(10);
    cout<<(a.withdraw(wd)?"Withdrawal OK":"Insufficient funds")<<endl;
    bonus(a); tryBonus(a);
    Auditor().show(a);
    nameInfo(a.getOwner());
    Register log[4]; for(int i=0;i<4;i++) log[i].reset();           // array of objects
    log[0].write(0xAB); log[3].write(0x10);
    for(int i=0;i<4;i++) cout<<"R"<<i<<"="<<(int)log[i].read()<<" ";
    double v[]={a.getBalance(), g.getBalance(), charge(1000,3)}, lo, hi;
    minMax(v,3,lo,hi); swapv(&lo,&hi);
    cout<<"\nmin="<<hi<<" max="<<lo<<" accounts created="<<Account::created()<<endl;
    return 0;
}