#include<iostream>
using namespace std;

class literature{
    
    int id;
    string title;

    public:
    void getdata(){

        cout<<"ENter unquie id : ";
        cin>>id;

        cout<<"Enter the title of book : ";
        cin>>title;

    }

    void display(){
        cout<<" ID : "<<id<<endl;
        cout<<"title : "<<title<<endl;
    } 
};

class eliterature : public virtual literature{

    string doi;
    
    public:
    void getdata(){
        cout<<"Enter DOI : ";
        cin>>doi;
    }
    void display(){
        cout<<"DOI : "<<doi<<endl;
    }

};

class hardbound : public virtual literature{

    int copies;
    char ch,e,h;
    public:
    void getdata(){
        cout<<"In stock copies : ";
        cin>>copies;   
    }
    void display(){
        cout<<"Copies : "<<copies<<endl;
    }
};

class book : public hardbound, public eliterature {

    int isbn;
    char ch;

    public:
    void getdata(){
        literature::getdata();
        cout<<"Enter ISBN : ";
        cin>>isbn;
        cout<<"Enter (E)copy and or (H)hardbound : ";
        cin>>ch;
        if(ch=='E'){
            hardbound::getdata();
        }
        else if(ch=='H'){
            eliterature::getdata();
        }
    }
    void display(){
        literature::display();
        if(ch=='E'){
        hardbound::display();
        }
        else if(ch=='H'){
            eliterature::display();
        }
        cout<<"ISBN : "<<isbn<<endl;
    }

};

class magazine : public hardbound, public eliterature{

    int issn;
    char ch;
    public: 
    void getadta(){
        literature::getdata();
        cout<<"ENter ISSN : ";
        cin>>issn;
        cout<<"Enter (E)copy and or (H)hardbound";
        cin>>ch;
        if(ch=='E'){
            hardbound::getdata();
        }
        else if(ch=='H'){
            eliterature::getdata();
        }
    }
    void display(){
        literature::display();
        if(ch=='E'){
        hardbound::display();
        }
        else if(ch=='H'){
            eliterature::display();
        }
        cout<<"ISSN : "<<issn<<endl;
    }

};

int main()
{
    int n;
    char ch;
    book b1;
    magazine m1;

    do{
    cout<<"ENter 1 : Add book data"<<endl;
    cout<<"ENter 2 : Add magazine data"<<endl;
    cout<<"ENter 3 : List of all boks"<<endl;
    cout<<"ENter 4 : List of all magazines"<<endl;
    cout<<"Enter Your choice : ";
    cin>>n;

    switch (n)
    {
    case 1 : 
    b1.getdata();
    break;

    case 2 :
    m1.getadta();
    break;

    case 3 :
    cout<<"Books : "<<endl; 
    b1.display();
    break;

    case 4:
    cout<<"Magazines : "<<endl;
    m1.display();
    break;

    default:
    cout<<"Invalid Choice";
    break;
    }
    cout<<"Enter M to goto new menu or press any key to exit : ";
    cin>>ch;
    }while(ch=='M');

return 0;
}                                               