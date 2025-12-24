#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Person {
protected:
    string name;
    int id;
public:
    Person(string n, int i) : name(n), id(i) {}
    virtual void markAttendance() = 0;
    virtual ~Person() {}
};
class Student : public Person {
    int rollNo;
    string className;
public:
    Student(string n, int i, int r, string c)
        : Person(n, i), rollNo(r), className(c) {}
	void markAttendance() override {
        ofstream file("attendance.txt", ios::app);
        file << "Student | Name: " << name
             << " | ID: " << id
             << " | Roll No: " << rollNo
             << " | Class: " << className
             << " | Attendance: Present\n";
        file.close();
        cout << "Student attendance marked successfully.\n";
    }
};
class Teacher : public Person {
    string subject;
    string department;
public:
    Teacher(string n, int i, string s, string d)
        : Person(n, i), subject(s), department(d) {}
    void markAttendance() override {
        ofstream file("attendance.txt", ios::app);
        file << "Teacher | Name: " << name
             << " | ID: " << id
             << " | Subject: " << subject
             << " | Department: " << department
             << " | Attendance: Present\n";
        file.close();
        cout << "Teacher attendance marked successfully.\n";
    }
};
void displayAttendance() {
    ifstream file("attendance.txt");
    string line;
	cout << "\n--- Attendance Report ---\n";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}
int main() {
    int choice;
    do {
        cout << "\n--- School Attendance Tracker ---\n";
        cout << "1. Mark Student Attendance\n";
        cout << "2. Mark Teacher Attendance\n";
        cout << "3. Display Attendance Report\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
		if (choice == 1) {
            string name, className;
            int id, rollNo;
			cout << "Enter student name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Roll No: ";
            cin >> rollNo;
            cout << "Enter Class: ";
            cin.ignore();
            getline(cin, className);
			Person* p = new Student(name, id, rollNo, className);
            p->markAttendance();
            delete p;
			} else if (choice == 2) {
            string name, subject, department;
            int id;
			cout << "Enter teacher name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Subject: ";
            cin.ignore();
            getline(cin, subject);
            cout << "Enter Department: ";
            getline(cin, department);
			Person* p = new Teacher(name, id, subject, department);
            p->markAttendance();
            delete p;
			} else if (choice == 3) {
            displayAttendance();
        }
		} while (choice != 4);
	cout << "Exiting system...\n";
    return 0;
}
