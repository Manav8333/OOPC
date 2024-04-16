#include<iostream>
using namespace std;

class construct{

    public: 
    float r,area;

    construct(){
    cout<<"Enter the radius of circle : ";
     cin>>r;
     area=3.14*r*r;
    }

};

int main()
{
    construct c;
    cout<<"area= "<<c.area<<endl;

    

return 0;
}