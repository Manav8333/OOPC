#include<iostream>
#include<iomanip>
using namespace std;

class employee {
    int id;
    string name;
    string qua;
    float exp;
    int contact;
    static int aver_exp, total_no;

public:
    int get_id() const {
        return id;
    }

    void getdata() {
        cout << "Enter Employee id :";
        cin >> id;
        total_no++;
        cout << "Enter Employee Name :";
        cin>>name;
        cout << "Enter Qualification :";
        cin>>qua;
        cout << "Enter Experience :";
        cin >> exp;
        aver_exp += exp;
        cout << "Enter Contact :";
        cin >> contact;
    }

    void putdata(int e_id) {
        if (id == e_id) {
            cout << "---------------------------------" << endl;
            cout.width(20); cout << left << "Employee Name " << ":" << name << endl;
            cout.width(20); cout << left << "Qualification " << ":" << qua << endl;
            cout.width(20); cout << left << "Experience " << ":" << exp << endl;
            cout.width(20); cout << left << "Contact Number " << ":" << contact << endl;
            cout << "---------------------------------" << endl;
            expe();
        }
    }

    static void expe() {
        cout << "Average exp=" << aver_exp / total_no;
    }
};

int employee::aver_exp;
int employee::total_no;

int main() {
    int n;
    cout << "Enter no of Employee :";
    cin >> n;
    employee e[n];

    for (int i = 0; i < n; i++) {
        e[i].getdata();
    }
    char x;
    do {
        int e_id;
        cout << "Enter an employee id (or enter -1 to exit): ";
        cin >> e_id;

        if (e_id == -1)
            break;

        int counter = 0; // Counter to track if the entered employee ID exists
        for (int i = 0; i < n; i++) {
            e[i].putdata(e_id);
            if (e[i].get_id() == e_id) { // Using the getter function to access id
                counter++;
            }
        }

        if (counter == 0) {
            cout << "*" << endl;
            cout << "ERROR: ENTERED EMPLOYEE ID DOES NOT EXIST." << endl;
            cout << "*" << endl;
        }

        cout << endl << "Press Y to get another employee detail, press N to exit: ";
        cin >> x;
        cin.ignore(); // Clear input buffer
    } while (x == 'Y' || x == 'y');

    return 0;
}