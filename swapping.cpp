#include<iostream>
using namespace std;
int main()
{
    int a=10,b=20;
    cout<<"before swapping a="<<a<<" b="<<b<<endl;
    swap(a,b);
    cout<<"after swapping :"<<"a="<<a<<" b="<<b<<endl;
}
void swap(int &x,int &y)
{
    int temp;
    temp=x;
    x=y;
    y=temp;
}