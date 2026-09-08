#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    cout<<"Enter a string:";
    cin>>str;
    cout<<"you entered string is:"<<str<<endl;
    cout<<"length of string is:"<<str.length()<<endl;
cout<<"upper :";
for(char &c:str)
{
    cout<<(char)toupper(c);
}
cout<<endl;
}