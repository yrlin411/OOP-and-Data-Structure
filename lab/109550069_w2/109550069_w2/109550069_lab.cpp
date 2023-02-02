#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Student {
public:
    Student( ) { }
    void generate_address(){
        cout << dormitory << ", (";
        cout << ID << ") ";
        cout << first_name << " " << last_name <<endl;
    }
    void set_first_name();
    void set_last_name();
    void set_dormitory();
    void set_ID();
    
private:
    string first_name;
    string last_name;
    string dormitory;
    string ID;
};


int main() {
      Student mStudent;
      mStudent.set_first_name();
      mStudent.set_last_name();
      mStudent.set_dormitory();
      mStudent.set_ID();
      cout << "1001 University Road, Hsinchu, Taiwan 300, ROC, dorm ";
      mStudent.generate_address();
    return 0;
}

void Student::set_first_name()
{
    cin >> first_name;
}
void Student::set_last_name()
{
    cin >> last_name;
}
void Student::set_dormitory()
{
    cin >> dormitory;
}
void Student::set_ID()
{
    cin >> ID;
}
