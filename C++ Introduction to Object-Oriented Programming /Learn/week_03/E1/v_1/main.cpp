#include "students.h"
#include <iostream>

int main() {
    StudentList studentList;

    studentList.addStudent("Adam Klaudiusz", "Nowak", 1);
    studentList.addStudent("Piotr Marek", "Kowalski", 3);
    studentList.addStudent("Brunon Marcel", "Jankowski", 7);

    std::cout << "Same nazwiska:\n";
    studentList.printStudents();

    std::cout << "\nSame semestry:\n";
    studentList.printStudents();

    std::cout << "\nImiona i nazwiska:\n";
    studentList.printStudents();

    std::cout << "\nWszystko:\n";
    studentList.printStudents();

    studentList.deleteStudent(0);
    std::cout << "\nPo usunięciu pierwszego:\n";
    studentList.printStudents();

    studentList.clearStudents();
    std::cout << "\nPo usunięciu wszystkich:\n";
    studentList.printStudents();

    return 0;
}