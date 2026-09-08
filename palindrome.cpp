#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cout<<"Enter a Word:";
    cin>>s;
    cout<<"the given string is:"<<s<<endl;
    for(char &c:s)
    {
        cout<<(char)toupper(c);

    bool pal=true;
    }
    for(size_t i=0,j=s.size()-1;i<j;++i;--j)
    {
        if(s[i]!=s[j])
        {
            pal=false;
            cout<<"the string is not a palindrome"<<endl;
            break;
        }
    else
    {
        cout<<"the string is a palindrome\n"<<;
    }
}
   size_t pos =s.find("ad");
    if(pos==1)
    {
    cout<<"substring is found in given string"<<endl;
    }
    else
    {
    cout<<"substring is not found in given string"<<endl;
    }
}
    return 0;

