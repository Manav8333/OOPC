#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class employee {
    static int cnt;
    static float average;
    int employee_id;
    string employee_name;
    string qualification;
    float experience;
    long long int contact;

protected:
    void getempdata() {
        cnt = cnt + 1;
        cout << "Enter Employee id : ";
        cin >> employee_id;
        cin.ignore(); // ignore newline character

        cout << "Enter Employee Name : ";
        getline(cin, employee_name);

        cout << "Enter Qualification : ";
        getline(cin, qualification);

        cout << "Enter Experience : ";
        cin >> experience;
        average += experience;

        cout << "Enter Contact :";
        cin >> contact;
    }

    void putempdata() {
        cout << "---------------------------------" << endl;
        cout.width(20);
        cout << left << "Employee Name " << ":" << employee_name << endl;
        cout.width(20);
        cout << left << "Qualification " << ":" << qualification << endl;
        cout.width(20);
        cout << left << "Experience " << ":" << experience << endl;
        cout.width(20);
        cout << left << "Contact Number " << ":" << contact << endl;
        cout << "---------------------------------" << endl;
    }

    int searchemp(int eid) {
        if (employee_id == eid)
            return 1;
        else
            return 0;
    }

public:
    static void avgexp() {
        cout << "\nAverage Experience =" << average / cnt;
    }
};

int employee ::cnt = 0;
float employee::average = 0;

class teaching : public employee {
    string designation;
    string specialization;
    string pay_scale;

public:
    void getempdata1() {
        getempdata();
        cout << "Enter Designation : ";
        cin >> designation;

        cout << "Enter Specialization : ";
        cin >> specialization;

        cout << "Enter Pay Scale : ";
        cin >> pay_scale;
    }

    void putempdata1() {
        putempdata();
        cout.width(20);
        cout << left << "Designation " << ":" << designation << endl;
        cout.width(20);
        cout << left << "Specialization " << ":" << specialization << endl;
        cout.width(20);
        cout << left << "Pay Scale " << ":" << pay_scale << endl;
        cout << "---------------------------------" << endl;
    }

    int searchemp1(int eid) {
        return searchemp(eid);
    }
};

class non_teaching : public employee {
    int salary;

public:
    void getempdata1() {
        getempdata();
        cout << "Enter Salary :";
        cin >> salary;
    }

    void putempdata1() {
        putempdata();
        cout.width(20);
        cout << left << "Salary " << ":" << salary << endl;
        cout << "---------------------------------" << endl;
    }

    int searchemp1(int eid) {
        return searchemp(eid);
    }
};

int main() {
    int n_teaching, n_non_teaching;
    cout << "Enter no of Teaching Employees : ";
    cin >> n_teaching;

    teaching e[n_teaching];
    for (int i = 0; i < n_teaching; i++) {
        e[i].getempdata1();
    }

    cout << "Enter no of Non Teaching Employees : ";
    cin >> n_non_teaching;

    non_teaching n[n_non_teaching];
    for (int i = 0; i < n_non_teaching; i++) {
        n[i].getempdata1();
    }

    int e_id;
    char choice;
    do {
        cout << "Enter an employee id: ";
        cin >> e_id;
        int i;
        int flag = 0;
        for (i = 0; i < n_teaching; i++) {
            int a = e[i].searchemp1(e_id);
            if (a == 1) {
                e[i].putempdata1();
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            for (i = 0; i < n_non_teaching; i++) {
                int a = n[i].searchemp1(e_id);
                if (a == 1) {
                    n[i].putempdata1();
                    flag = 1;
                    break;
                }
            }
        }

        if (flag == 0) {
            cout << "*" << endl;
            cout << "ERROR: ENTERED EMPLOYEE ID DOES NOT EXIST" << endl;
            cout << "*" << endl;
        }

        cout << "Press Y to get another employee detail, press N to exit: ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    return 0;
}
