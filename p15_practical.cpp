#include<iostream>
#include<string.h>
using namespace std;
class product
{
protected:
    int product_id;
    string product_name, product_manufacturer;
    float product_price;
public:
    product(int id, string name, string manufacturer, float price)
    {
        product_id = id;
        product_name = name;
        product_manufacturer = manufacturer;
        product_price = price;
    }
    virtual void putdata()=0;
};
class smartwatch : public product
{
protected:
    float dial_size;
public:
    smartwatch(int id, string name, string manufacturer, float price, float DialSize) : product(id, name, manufacturer, price)
    {
        dial_size = DialSize;
    }
    void putdata()
    {
        cout << "-----------------------------------------------------------------";
        cout << endl << product_id << " : " << product_name << " : " << product_manufacturer << " : " << product_price << " : " << dial_size << endl;
        cout << "-----------------------------------------------------------------";
    }
};
class bedsheet : public product
{
protected:
    float width, height;
public:
    bedsheet(int id, string name, string manufacturer, float price, float Width , float Height) : product(id, name, manufacturer, price)
    {
        width = Width;
        height = Height;
    }
    void putdata()
    {
        cout << "-----------------------------------------------------------------";
        cout << endl << product_id << " : " << product_name << " : " << product_manufacturer << " : " << product_price << " : " << width << " : " << height << endl;
        cout << "-----------------------------------------------------------------";
    }
};
int main()
{
    int id, choice;
    string name, manufacturer;
    float price, DialSize, Width, Height;
    cout << "Enter 1 : Smart watch menu\nEnter 2 : Bedsheet menu\n";
    cin >> choice;
    switch(choice)
    {
    case 1:
        {
            smartwatch *s;
            cout << "***** Enter Smart Watch Data *****" << endl;
            cout << "\nEnter product id : ";
            cin >> id;
            cout << "Enter product name : ";
            cin >> name;
            fflush(stdin);
            cout << "Enter product manufacturer : ";
            cin >> manufacturer;
            cout << "Enter product price : ";
            cin >> price;
            cout << "Enter dial size : ";
            cin >> DialSize;
            s= new smartwatch(id, name, manufacturer, price, DialSize);
            s->putdata();
            delete s;
            break;
        }
    case 2:
        {
            bedsheet *b;
            cout << "***** Enter Bedsheet Data *****" << endl;
            cout << "\nEnter product id : ";
            cin >> id;
            cout << "Enter product name : ";
            cin >> name;
            fflush(stdin);
            cout << "Enter product manufacturer : ";
            cin >> manufacturer;
            cout << "Enter product price : ";
            cin >> price;
            cout << "Enter bedsheet width : ";
            cin >> Width;
            cout << "Enter bedsheet height : ";
            cin >> Height;
            b= new bedsheet(id, name, manufacturer, price, Width, Height);
            b->putdata();
            delete b;
            break;
        }
    }
    return 0;
}
