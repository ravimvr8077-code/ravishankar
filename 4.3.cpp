#include<iostream.h>
using namespace std;
class Box
{
int w,h,d;
public:
Box(int w, int h, int d)
{
this->w = w;
this->h = h;
this->d = d;
}
Box()
{
w = 1;
h = 1;
d = 1;
}
Box(int s):
{
    Box(s,s,s);
}
int getVolume()
{
return w * h * d;
}
};
int main()
{
    Box a;
    Box b(3);
    Box c(2,3,4);
    cout << "Volume of box a: " << a.getVolume() << endl;
    cout << "Volume of box b: " << b.getVolume() << endl;
    cout << "Volume of box c: " << c.getVolume() << endl;
    return 0;
}