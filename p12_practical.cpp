#include <iostream>
#include <iomanip>
using namespace std;

class result; // Forward declaration of the result class

class student 
{
private:
    string stud_id;
    string stud_name;
    int sem;
public:
    void getdata_student();
    void putdata_student();
    void get_result(result &r); // Pass result object by reference
    void put_result(result &r); // Pass result object by reference
};

void student :: getdata_student()
{
    cout << "Enter student id  :";
    cin >> stud_id;
    cout << "Enter student name :";
    cin >> stud_name;
    cout << "Enter student semester :";
    cin >> sem;
}

void student :: putdata_student()
{
    cout << left << setw(20) << "Student ID" << left << ":" << stud_id << endl;
    cout << left << setw(20) << "Student Name" << left << ":" << stud_name << endl;
    cout << left << setw(20) << "Student Semester" << left << ":" << sem << endl;
}

class result
{
private:
    string subject_name[3];
    int theo_credit[3];
    int prac_credit[3];
    int theo_marks[3];
    int prac_marks[3];
    string theo_grade[3];
    string prac_grade[3];
    int theo_gp[3];
    int prac_gp[3];
    int sum;
    int total_credit;
    float sgpa;
public:
    void sgpa_call();
    string convert_to_grade(int marks);
    int convert_to_grade_point(int marks);
    // Add getter functions
    string get_subject_name(int i) const { return subject_name[i]; }
    int get_th_marks(int i) const { return theo_marks[i]; }
    int get_pr_marks(int i) const { return prac_marks[i]; }
    string get_th_grade(int i) const { return theo_grade[i]; }
    string get_pr_grade(int i) const { return prac_grade[i]; }
    int get_th_credit(int i) const { return theo_credit[i]; }
    int get_pr_credit(int i) const { return prac_credit[i]; }
    float get_sgpa() const { return sgpa; }
    friend void student::get_result(result &r); // Declare friend function to access private members
};

void student :: get_result(result &r)
{
    cout << "Enter 3 subject names and credits:\n";
    for (int i = 0; i < 3; i++) {
        cout << "Subject " << i + 1 << ": ";
        cin >> r.subject_name[i]; // Access result object's members

        cout << "Enter theory and practical marks of " << r.subject_name[i] << "\n";
        cout << "Theory: ";
        cin >> r.theo_marks[i];
        cout << "Practical: ";
        cin >> r.prac_marks[i];

        cout << "Enter theory and practical credit of " << r.subject_name[i] << "\n";
        cout << "Theory: ";
        cin >> r.theo_credit[i];
        cout << "Practical: ";
        cin >> r.prac_credit[i];

        r.theo_grade[i] = r.convert_to_grade(r.theo_marks[i]);
        r.prac_grade[i] = r.convert_to_grade(r.prac_marks[i]);

        r.theo_gp[i] = r.convert_to_grade_point(r.theo_marks[i]);
        r.prac_gp[i] = r.convert_to_grade_point(r.prac_marks[i]);
    }
}

void result :: sgpa_call()
{
    sum = 0;
    total_credit = 0;
    for (int i = 0; i < 3; i++) 
    {
        sum += theo_gp[i] * theo_credit[i] + prac_gp[i] * prac_credit[i];
        total_credit += theo_credit[i] + prac_credit[i];
    }
    sgpa = static_cast<float>(sum) / total_credit; // Type cast the sum to float
}

string result :: convert_to_grade(int marks) {
    if (marks >= 80) {
        return "AA";
    } else if (marks >= 73 && marks < 80) {
        return "AB";
    } else if (marks >= 66 && marks < 73) {
        return "BB";
    } else if (marks >= 60 && marks < 66) {
        return "BC";
    } else if (marks >= 55 && marks < 60) {
        return "CC";
    } else if (marks >= 50 && marks < 55) {
        return "CD";
    } else if (marks >= 45 && marks < 50) {
        return "DD";
    } else {
        return "FF";
    }
}

int result :: convert_to_grade_point(int marks) {
    if (marks >= 80) {
        return 10;
    } else if (marks >= 73 && marks < 80) {
        return 9;
    } else if (marks >= 66 && marks < 73) {
        return 8;
    } else if (marks >= 60 && marks < 66) {
        return 7;
    } else if (marks >= 55 && marks < 60) {
        return 6;
    } else if (marks >= 50 && marks < 55) {
        return 5;
    } else if (marks >= 45 && marks < 50) {
        return 4;
    } else {
        return 0;
    }
}

void student :: put_result(result &r)
{
    system("CLS");
    cout << "\nMark Sheet:\n";
    cout << setw(20) << "Subject Name" << setw(20) << "Theory Grade" << setw(20) << "Practical Grade" << endl;
    for (int i = 0; i < 3; i++) {
        cout << setw(20) << r.get_subject_name(i) << setw(20) << r.get_th_grade(i) << setw(20) << r.get_pr_grade(i) << endl;
    }
    cout << "\nSGPA: " << fixed << setprecision(2) << r.get_sgpa() << endl;
}

int main ()
{
    student s;
    result r;
    s.getdata_student();
    s.get_result(r);
    r.sgpa_call();
    s.putdata_student();
    s.put_result(r);
    return 0;
}
