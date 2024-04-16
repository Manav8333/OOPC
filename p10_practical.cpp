#include <iostream>

using namespace std;

class Employee {
private:
  int yrs;
  int month;

public:
  Employee() : yrs(0), month(0) {}

  Employee(float experience) {
    yrs = int(experience);
    month = int((experience - yrs) * 12);
  }

  void displayExperience() {
    cout << yrs << " years " << month << " months" << endl;
  }
};

int main() {
  float exp_in_year;

  cout << "Enter years of experience (float): ";
  cin >> exp_in_year;

  Employee emp(exp_in_year);

  cout << "Employee Experience: ";
  emp.displayExperience();

  return 0;
}