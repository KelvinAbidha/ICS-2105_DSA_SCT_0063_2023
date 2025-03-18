#include <iostream>
#include <string>
using namespace std;

/*main tasks
*Class for grade used to assign, display and give the student a grade/scores.
*Class for students to modify and display students
*method to add students and give marks
*Main to show how the program works.
*/

class Course {
public:
    string code, name;
};

class Grade {
private:
    int score;
    char letter;
    bool locked = false; 

    void figureOutGrade() {
        letter = (score > 69) ? 'A' : (score > 59) ? 'B' : (score > 49) ? 'C' : (score > 39) ? 'D' : 'E';
    }

public:
    Grade() { score = -1; }

    void setScore(int s) {
        if (locked) {
            cout << "Nah, grade's locked! Can't change it.\n";
            return;
        }
        if (s < 0 || s > 100) {
            cout << "That score ain't right! (Must be 0-100)\n";
            return;
        }
        score = s;
        figureOutGrade();
        locked = true;
    }

    void displayGrade() {
        cout << "Marks: " << (score == -1 ? "Not given yet" : to_string(score) + " | Grade: " + letter) << endl;
    }
};

class Student {
public:
    string regNum, fullName;
    int yearsOld;
    Course subject;
    Grade myGrade;

    void fillDetails() {
        cout << "Enter Reg No, Name, Age, Course Code, Course Name: ";
        cin >> regNum >> fullName >> yearsOld >> subject.code;
        cin.ignore();
        getline(cin, subject.name);
    }

    void displayStudent() {  
        cout << "\n📌 " << regNum << " | " << fullName << " (" << yearsOld << " years)\n";
        cout << "🎓 Studying: " << subject.name << " [" << subject.code << "]\n";
        myGrade.displayGrade();
    }
};

Student studentList[40]; 
int studentCount = 0;

void newStudent() {
    if (studentCount < 40) studentList[studentCount++].fillDetails();
    else cout << "Whoa! We got too many students.\n";
}

void giveMarks() {
    string reg; int marks;
    cout << "Whose marks? (Enter Reg No): ";
    cin >> reg;
    for (int i = 0; i < studentCount; i++)
        if (studentList[i].regNum == reg) {
            cout << "Enter Score: ";
            cin >> marks;
            studentList[i].myGrade.setScore(marks);
            return;
        }
    cout << "Hmmm... can't find that student!\n";
}

void displayAllStudents() {
    if (studentCount == 0) cout << "Nobody here yet!\n";
    for (int i = 0; i < studentCount; i++) studentList[i].displayStudent();
}

int main() {
    int pick;
    do {
        cout << "\n1️⃣ Add Student  2️⃣ Give Marks  3️⃣ Show All  4️⃣ Exit\n👉 Pick one: ";
        cin >> pick;
        if (pick == 1) newStudent();
        else if (pick == 2) giveMarks();
        else if (pick == 3) displayAllStudents();
    } while (pick != 4);
    cout << "👋 Bye!\n";
    return 0;
}
