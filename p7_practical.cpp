#include<iostream>
#include<iomanip>
using namespace std;

class complex{

    float a,b;
    public:

    void setdata(){
        cout<<"Enter the real part : "<<endl;
        cin>>a;
        cout<<"Enter the imaginary part : "<<endl;
        cin>>b;
    }
    
    void display(){
        cout<<setprecision(3)<<a<< " + " <<setprecision(2)<<b<< " i "<<endl;
    }


    complex operator+ (complex &m){
        complex temp;
        temp.a=a+m.a;
        temp.b=b+m.b;
        return temp;
    }

    complex operator- (complex &m){
        complex temp;
        temp.a=a-m.a;
        temp.b=b-m.b;
        return temp;
    }

    complex operator* (complex &m){
        complex temp;
        temp.a=a*m.a;
        temp.b=b*m.b;
        return temp;
    }

        complex operator /(complex &m){
        complex temp;
        temp.a=((a*m.a)+(b*m.b))/((m.a*m.a)+(m.b*m.b));
        temp.b=((b*m.a)-(a*m.b))/((m.a*m.a)+(m.b*m.b));
        return temp;
        }   

        complex operator !(){
        complex temp;
        temp.a=-a;
        temp.b=-b;
        return temp;
        }   
    
};

int main()
{
    complex c1,c2,c3;
    c1.setdata();
    c2.setdata();
    cout << "Choose operation"<<endl;
    cout <<"("<<"+"<<")"<<"addition"<<endl;
    cout <<"("<<"-"<<")"<<"subtraction"<<endl;
    cout <<"("<<"*"<<")"<<"multiplication"<<endl;
    cout <<"("<<"/"<<")"<<"division"<<endl;
    cout <<"("<<"!"<<")"<<"negation"<<endl;
    cout <<"Enter your Choice : ";
    char symbol;
    cin >>symbol;
    switch(symbol){
        case '+':
         c3=c1+c2;
         c3.display();
         break;

         case '-':
         c3 = c1 - c2;
         c3.display();
         break;

         case '*':
         c3 = c1 * c2;
         c3.display();
         break;

         case '/':
         c3 = c1 / c2;
         c3.display();
         break;

        case '!':
        c3=!c1;
        c3.display();
        c3=!c2;
        c3.display();
        break;
    }

return 0;
}