#include<iostream>
#include <iomanip>
using namespace std;
int main()
{
    string stu_id,stu_name;
    int sem,theory[3],practical[3],gpoint1[3],gpoint2[3],t_credits[3]={2,2,2},p_credits[3]={1,1,1};
    string subject[3],grade1[3],grade2[3];
    float sum=0,total_credit=0,cgpa;

    cout<<"Enter student id : ";
    cin >> stu_id;

    cout<<"Enter student name : ";
    cin >> stu_name;

    cout<<"Enter the semester : ";
    cin>>sem;

    cout<<"Enter three subjects name : ";
    for(int i=0;i<3;i++){
        cout<<"subject "<<i+1<<":";
        cin>>subject[i];
    }

    cout<<"Entered subjects are : ";
    for(int i=0;i<3;i++){
        cout<<"subject"<<i+1<<":"<<subject[i]<<"\n";
    }

    for(int i=0;i<3;i++){
        cout<<"Enter theory and practical marks of "<<subject[i]<<"\n";
        cout<<"Theory : ";
        cin>>theory[i];
        cout<<"Practical : ";
        cin>>practical[i];
    }

    for (int i = 0; i < 3; i++) {
        if (theory[i] >= 80) {
            grade1[i] = "AA";
            gpoint1[i] = 10;
        } else if (theory[i] >= 73 && theory[i] < 80) {
            grade1[i] = "AB";
            gpoint1[i] = 9;
        } else if (theory[i] >= 66 && theory[i] < 73) {
            grade1[i] = "BB";
            gpoint1[i] = 8;
        } else if (theory[i] >= 60 && theory[i] < 66) {
            grade1[i] = "BC";
            gpoint1[i] = 7;
        } else if (theory[i] >= 55 && theory[i] < 60) {
            grade1[i] = "CC";
            gpoint1[i] = 6;
        } else if (theory[i] >= 50 && theory[i] < 55) {
            grade1[i] = "CD";
            gpoint1[i] = 5;
        } else if (theory[i] >= 45 && theory[i] < 50) {
            grade1[i] = "DD";
            gpoint1[i] = 4;
        } else {
            grade1[i] = "FF";
            gpoint1[i] = 0;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (practical[i] >= 80) {
            grade2[i] = "AA";
            gpoint2[i] = 10;
        } else if (practical[i] >= 73 && practical[i] < 80) {
            grade2[i] = "AB";
            gpoint2[i] = 9;
        } else if (practical[i] >= 66 && practical[i] < 73) {
            grade2[i] = "BB";
            gpoint2[i] = 8;
        } else if (practical[i] >= 60 && practical[i] < 66) {
            grade2[i] = "BC";
            gpoint2[i] = 7;
        } else if (practical[i] >= 55 && practical[i] < 60) {
            grade2[i] = "CC";
            gpoint2[i] = 6;
        } else if (practical[i] >= 50 && practical[i] < 55) {
            grade2[i] = "CD";
            gpoint2[i] = 5;
        } else if (practical[i] >= 45 && practical[i] < 50) {
            grade2[i] = "DD";
            gpoint2[i] = 4;
        } else {
            grade2[i] = "FF";
            gpoint2[i] = 0;
        }
    }
    cout << "\nEntered student details" << "\n";
    cout << left << setw(20) << "Student ID" << left << ":" << stu_id << "\n";
    cout << left << setw(20) << "Student Name" << left << ":" << stu_name << "\n";
    cout << left << setw(20) << "Student Semester" << left << ":" << sem << "\n\n";

    cout << "\nGrades for each subject:\n";
    cout << left << setw(20) << "Subject" << setw(15) << "Grade Theory" << setw(15) << "Grade Practical" << "\n";
       for (int i = 0; i < 3; i++)
        {
          cout << left << setw(20) << subject[i] << setw(15) << grade1[i] << setw(15) << grade2[i] << "\n";
        }

      for (int i = 0; i < 3; i++)
        {
          sum += gpoint1[i] * t_credits[i] + gpoint2[i] * p_credits[i];
          total_credit += t_credits[i] + p_credits[i];
        }

     cgpa = sum / total_credit;

    cout << "\nCGPA is: " << setw(20) << setprecision(3)<< cgpa << endl;
    return 0;


    

return 0;
}