#include <iostream>

using namespace std;

class Emp {
private:
  int yrs;
  int month;

public:
  Emp() : yrs(0), month(0) {}  // Default constructor

  Emp(int y, int m) : yrs(y), month(m) {}  // Parameterized constructor

  operator float() {
    return yrs + float(month) / 12.0f;  // Overloaded operator float()
  }

  void displayExperience() {
    cout << yrs << " years " << month << " months" << endl;  // Display experience
  }
};

int main() {
  int years, months;

  cout << "Enter years of experience: ";
  cin >> years;
  cout << "Enter months of experience: ";
  cin >> months;

  Emp emp(years, months);  // Create Employee object

  cout << "Employee Experience: ";
  emp.displayExperience();

  float total_experience = emp;  // Convert Employee object to float using overloading

  cout << "Total Experience (years): " << total_experience << endl;

  return 0;
}