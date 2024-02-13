#include<iostream>
using namespace std;

class cars{
    public:
    string mode,transmission,airbag;
    int fuel,seat;
    float show_price,mileage,tank_cap;

    void getdata(){
        cout<<"Enter model name : ";
        cin>>mode;

        cout<<"ENter the fuel type"<<"[1]petrol [2]diesel [3]EV [4]CNG : ";
        cin>>fuel;

        cout<<"Enter showroom price : ";
        cin>>show_price;

        cout<<"ENter mileage of car : ";
        cin>>mileage;

        cout<<"Enter transmission type : ";
        cin>>transmission;

        cout<<"ENter tank capacity : ";
        cin>>tank_cap;

        cout<<"ENter the no. of seating : ";
        cin>>seat;

        cout<<"Enter the airbags : ";
        cin>>airbag;
    }

    void putdata(){
    cout<<endl<<"Model"<<"\t"<<"Fuel"<<"\t"<<"Price(Lakhs)"<<"\t"<<"Mileage"<<"\t"<<"Transmission"<<"\t"<<"Tank Capacity"<<"\t"<<"Seats"<<"\t"<<"Airbags";
    cout<<endl<<mode<<"\t"<<fuel<<"\t"<<show_price<<"\t\t"<<mileage<<"\t"<<transmission<<"\t\t"<<tank_cap<<"\t\t"<<seat<<"\t"<<airbag;    
    }

};

int main()
{
    int car;
    int choice,m_ch,f_ch,p_ch;
    cars a[7];
    cout<<"enter number of cars"<<endl;
    cin>>car;

    for(int i=0;i<car;i++){
        a[i].getdata();
    }   
    cout<<endl<<"WELCOME TO TATA MOTORS";
    cout<<endl<<"Get the car details as per your preference";
    cout<<endl<<"(1)Model Name (2)Fuel Type (3)Price Range"<<endl<<"enter your option : ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        cout<<endl<<"List of TATA cars"<<endl;
        cout<<"[1] Tiago [2]Punch [3] Altroz [4]Tigor [5]Nexon [6]Harrier [7]Safari";
        for(int i=0;i<car;i++)
        {
            cout<<"("<<i<<")"<<a[i].mode<<endl;
        }
        cout<<"Choose your dream car to get details : ";
        cin>>m_ch;
        a[m_ch].putdata();
        break;

    case 2:
        cout<<endl<<"TATA motors are available with these fuel options"<<endl;
        cout<<"[1]Petrol [2]Diesel [3]EV [4]CNG"<<endl;
        cout<<"Choose your fuel preference to get details : ";
        cin>>m_ch;
        for(int i=0;i<car;i++)
        {
            if(m_ch==a[i].fuel)
            {
                cout<<endl;
                a[i].putdata();
            }
            else
            {
                cout<<endl<<"select valid fuel type";
            }
        }
        break;
    case 3:
        cout<<endl<<"Enter your maximum affordable price(in lakhs) : "<<endl;
        cin>>p_ch;
        for(int i=0;i<car;i++)
        {
            if(p_ch==a[i].show_price)
            {
                cout<<endl;
                a[i].putdata();
            }
            else
            {
                cout<<endl<<"select valid price";
            }
        }
        break;
    }
return 0;
}