#include<iostream>
using namespace std;

void cubo(float height, float width, float depth){
    float area;
     area=height*width*depth;
     cout<<"The area of cuboid is : ";
     cout<<area<<endl;
}

void rect(float height, float width){
    float area;
     area=height*width;
     cout<<"The area of rectangle is : ";
     cout<<area<<endl;
}

void circle(float radius){
    float area;
    cout<<"The area of circle is : ";
    area=3.14*radius*radius;
    cout<< area<<endl;
    }

int main()
{
    float radius;
    float height,width,depth;
    cout<<"Enter the radius of circle : ";
    cin>>radius;
    circle(radius);

    cout<<"Enter height of rectangle : ";
    cin>>height;

    cout<<"Enter the width of rectangle: ";
    cin>>width;
    rect(height, width);

    cout<<"Enter height of cuboid : ";
    cin>>height;

    cout<<"Enter width of cuboid: ";
    cin>>width;

    cout<<"Enter depth of cuboid: ";
    cin>>depth;
    cubo(height, width, depth);

return 0;
}
