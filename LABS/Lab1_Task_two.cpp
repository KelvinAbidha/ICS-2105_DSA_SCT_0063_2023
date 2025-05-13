#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Structure to represent a course.
struct Course {
    string code; 
    string name; 
};

// Structure to represent a grade.
struct Grade {
    int mark = -1;
    char letter = ' '; 
    bool locked = false; // prevents grade modification
};

// Structure to represent a student.
struct Student {
    string reg;    
    string name;   
    int age;       
    Course course; 
    Grade grade;  
};

// Vector to store student records (max 40 students).
vector<Student> students;

// Function to determine the letter grade from the mark.
char getGrade(int m) {
    if (m > 69) return 'A';
    if (m > 59) return 'B';
    if (m > 49) return 'C';
    if (m > 39) return 'D';
    return 'E';
}

// Function to add a new student.
void addStudent() {
    if (students.size() < 40) { // Add at most 40 students
        Student newStudent;
        cout << "Enter registration number: ";
        cin >> newStudent.reg;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, newStudent.name);
        cout << "Enter age: ";
        cin >> newStudent.age;
        cout << "Enter course code: ";
        cin >> newStudent.course.code;
        cout << "Enter course name: ";
        cin.ignore();
        getline(cin, newStudent.course.name);
        students.push_back(newStudent);
        cout << "Student added.\n";
    } else {
        cout << "Maximum number of students reached.\n";
    }
}

// Function to edit an existing student's details.
void editStudent() {
    string regToEdit;
    cout << "Enter registration number of student to edit: ";
    cin >> regToEdit;
    for (auto& s : students) {
        if (s.reg == regToEdit) { // Edit a student’s details
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, s.name);
            cout << "Enter new age: ";
            cin >> s.age;
            cout << "Student details updated.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

// Function to add a grade for a student.
void addGrade() {
    string regToAddGrade;
    cout << "Enter registration number of student to add grade for: ";
    cin >> regToAddGrade;
    for (auto& s : students) {
        if (s.reg == regToAddGrade) {
            if (!s.grade.locked) { // Ensure grades, once calculated, cannot be altered.
                int mark;
                cout << "Enter mark (0-100): ";
                cin >> mark;
                if (mark >= 0 && mark <= 100) {
                    s.grade.mark = mark;
                    s.grade.letter = getGrade(mark); // Add marks and calculate grades.
                    s.grade.locked = true;
                    cout << "Grade added: " << s.grade.letter << "\n";
                } else {
                    cout << "Invalid mark.\n";
                }
            } else {
                cout << "Grade for this student is already locked.\n";
            }
            return;
        }
    }
    cout << "Student not found.\n";
}

// Function to display all students and their details.
void showStudents() {
    cout << "\n--- Student List ---\n";
    if (students.empty()) {
        cout << "No students in the system.\n";
    } else {
        for (const auto& s : students) {
            cout << "Reg: " << s.reg << ", Name: " << s.name << ", Age: " << s.age
                 << ", Course: " << s.course.code << " (" << s.course.name << ")";
            if (s.grade.locked) {
                cout << ", Grade: " << s.grade.letter << " (" << s.grade.mark << ")";
            } else {
                cout << ", Grade: Not yet added";
            }
            cout << endl;
        }
    }
    cout << "--------------------\n";
}

int main() {
    int choice;
    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add New Student\n";
        cout << "2. Edit Student Details\n";
        cout << "3. Add Marks and Calculate Grade\n";
        cout << "4. Display All Students\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                editStudent();
                break;
            case 3:
                addGrade();
                break;
            case 4:
                showStudents();
                break;
            case 0:
                cout << "Exiting system.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
