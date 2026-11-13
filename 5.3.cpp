#include<iostream>
using namespace std;
class Car
{
    int speed=0;
    friend class Dashboard;
    public:
    void acclerate()

{
    speed +=10;
}
};
class Dashboard 
{
    public:
    void display(const Car &c)
    {
        cout<<"speed="<<c.speed<<"km/h"<<endl;
    }
};
int main()
{
    Car c;
    c.acclerate();
    c.acclerate();
    Dashboard().display(c);
    return 0;
}