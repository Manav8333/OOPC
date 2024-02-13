#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

struct employee
{
    int emp_id;
    string emp_name,emp_quli;
    long long int number;

    void getdata() 
    {
        cout << "Enter employee id: ";
        cin >> emp_id;
        cout << "Enter employee name: ";
        cin >> emp_name;
        cout << "Enter employee qualification: \n";
        cin >> emp_quli;
        cout << "Enter employee contact number: \n";
        cin >> number;
    }

    void displaydata()
    {   
        for(int i=0;i<30;i++){
            cout<<"*";
        }
        cout <<left<< setw(31)<<"\nEmployee id" <<":"<< emp_id << endl;
        cout <<left<< setw(30)<<"Employee name " <<":"<<emp_name << endl;
        cout <<left<< setw(30)<<"Employee qualification " <<":"<< emp_quli << endl;
        cout <<left<< setw(30)<<"Employee contact number " <<":"<<number << endl;

    }
    
};

int main()
{
    int n, eid;
    cout <<"\nEnter the number of employees: ";
    cin >> n;

    employee e[n];

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter data for employee " << i + 1 << ":\n";
        e[i].getdata();
    }

    char ch;
    do
    {
        for(int i=0;i<30;i++)
        cout<<"*";
        cout <<"\nEnter employee id for information: ";
        cin >> eid;

        for(int i=0;i<30;i++){

            cout<<"*";

        }
        int j;
        for (j = 0; j < n; j++)
        {
            if (eid == e[j].emp_id)
            {
                cout << "\nData for employee " << j + 1 << ":\n";
                e[j].displaydata();
                break;
            }
        }

        if (j == n)
        {
            cout <<"\nEmployee id is not valid." << endl;
        } 
        for(int i=0;i<30;i++){

            cout<<"*";

        }
        cout <<"\nIf you want other information press y and for exit press n: ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    return 0;
}
