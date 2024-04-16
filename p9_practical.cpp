#include<iostream>
using namespace std;

class cm_convert;

class mm_convert{
    float cm, mm;
public:
    float get_cm() {
        return cm;
    }
    mm_convert() {
        cm = 0;
    }
    mm_convert(float a) {
        cm = a / 10.0;
    }
    mm_convert(cm_convert &k);
    void display() {
        cout << "Measurement in mm:" << mm;
    }
};

class cm_convert{
    float mm, cm;
public:
    cm_convert(float a) {
        mm = a * 10;
    }
    float get_mm() {
        return mm;
    }
    cm_convert(mm_convert &y);
    void display() {
        cout << "Measurement in cm:" << cm;
    }
};

mm_convert::mm_convert(cm_convert &k) {
    mm = k.get_mm();
}

cm_convert::cm_convert(mm_convert &y) {
    cm = y.get_cm();
}

int main() {
    int y;
    cout << "Enter 1: mm to cm converter" << endl;
    cout << "Enter 2: cm to mm converter" << endl;

    cin >> y;
    if (y == 1) {
        float v;
        cout << "Enter the mm:" << endl;
        cin >> v;
        mm_convert mm1(v);
        cm_convert cm1(mm1);
        cm1.display();
    } else if (y == 2) {
        cout << "Enter the cm:" << endl;
        float u;
        cin >> u;
        cm_convert cm2(u);
        mm_convert mm2(cm2);
        mm2.display();
    }
    else {
        cout << "Invalid choice" << endl;
    }
    return 0;
}