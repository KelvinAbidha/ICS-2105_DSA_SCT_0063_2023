#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures for Course and Grade
typedef struct {
    char* courseCode;
    char* courseName;
} Course;

typedef struct {
    int marks;
    char grade;
} Grade;

// Define structure for Student
typedef struct Student {
    char* regNumber;
    char* name;
    int age;
    Course course;
    Grade grade;
    struct Student* next; // Pointer to next student in the list
} Student;

// Function to calculate grade
void calculateGrade(Grade* grade, int marks) {
    grade->marks = marks;
    if (marks >= 69) {
        grade->grade = 'A';
    } else if (marks >= 59) {
        grade->grade = 'B';
    } else if (marks >= 49) {
        grade->grade = 'C';
    } else if (marks >= 39) {
        grade->grade = 'D';
    } else {
        grade->grade = 'E';
    }
}

// Function to create a new student node
Student* createStudent(char* regNumber, char* name, int age, Course course) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    
    newStudent->regNumber = (char*)malloc(strlen(regNumber) + 1);
    strcpy(newStudent->regNumber, regNumber);

    newStudent->name = (char*)malloc(strlen(name) + 1);
    strcpy(newStudent->name, name);

    newStudent->age = age;
    newStudent->course = course;
    newStudent->next = NULL;

    return newStudent;
}
Course createCourse(char* code, char* name) {
    Course newCourse;
    newCourse.courseCode = (char*)malloc(strlen(code) + 1);
    strcpy(newCourse.courseCode, code);

    newCourse.courseName = (char*)malloc(strlen(name) + 1);
    strcpy(newCourse.courseName, name);

    return newCourse;
}

// Function to add a student to the linked list
void addStudent(Student** head, char* regNumber, char* name, int age, Course course, int marks) {
    Student* newStudent = createStudent(regNumber, name, age, course);
    calculateGrade(&newStudent->grade, marks);

    if (*head == NULL) {
        *head = newStudent;
    } else {
        Student* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
}
void displayAllStudents(Student* head) {
    Student* temp = head;
    int studentCount = 1;
    while (temp != NULL) {
        printf("\nStudent %d:\n", studentCount++);
        printf("Reg Number: %s\n", temp->regNumber);
        printf("Name: %s\n", temp->name);
        printf("Age: %d\n", temp->age);
        printf("Course: %s - %s\n", temp->course.courseCode, temp->course.courseName);
        printf("Marks: %d Grade: %c\n", temp->grade.marks, temp->grade.grade);
        temp = temp->next;
    }
}

// Function to remove a student based on registration number
void removeStudent(Student** head, char* regNumber) {
    Student* temp = *head;
    Student* prev = NULL;

    // If the student to be removed is the head
    if (temp != NULL && strcmp(temp->regNumber, regNumber) == 0) {
        *head = temp->next;
        free(temp->regNumber);
        free(temp->name);
        free(temp->course.courseCode);
        free(temp->course.courseName);
        free(temp);
        return;
    }

    // Search for the student to be removed
    while (temp != NULL && strcmp(temp->regNumber, regNumber) != 0) {
        prev = temp;
        temp = temp->next;
    }

    // If student was not found
    if (temp == NULL) {
        printf("Student not found.\n");
        return;
    }

    // Unlink the student from the linked list
    prev->next = temp->next;
    free(temp->regNumber);
    free(temp->name);
    free(temp->course.courseCode);
    free(temp->course.courseName);
    free(temp);
}

// Function to destroy the entire list and free memory
void destroyList(Student* head) {
    Student* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp->regNumber);
        free(temp->name);
        free(temp->course.courseCode);
        free(temp->course.courseName);
        free(temp);
    }
}

// Main driver function
int main() {
    Student* studentList = NULL;

    // Create and add students
    Course course1 = createCourse("ICS2301", "Data Structures");
    addStudent(&studentList, "SCT212-101", "Mark Otieno", 21, course1, 78);

    Course course2 = createCourse("ICS2302", "Algorithms");
    addStudent(&studentList, "SCT212-102", "John Wanjala", 22, course2, 67);

    Course course3 = createCourse("ICS2303", "Databases");
    addStudent(&studentList, "SCT212-103", "Cathy Naliaka", 20, course3, 58);

    Course course4 = createCourse("ICS2304", "Networking");
    addStudent(&studentList, "SCT212-104", "Dan Musyoka", 23, course4, 49);

    Course course5 = createCourse("ICS2305", "Operating Systems");
    addStudent(&studentList, "SCT212-105", "Eva Wambui", 21, course5, 35);
    displayAllStudents(studentList);
    printf("\nRemoving student SCT212-103 (Cathy Naliaka)\n");
    removeStudent(&studentList, "SCT212-103");
    displayAllStudents(studentList);
    destroyList(studentList);

    return 0;
}
