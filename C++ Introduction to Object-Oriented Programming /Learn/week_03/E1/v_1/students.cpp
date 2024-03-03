#include "students.h"
#include <iostream>
#include <cstring>

Student::Student(const char* name, const char* surname, int semester) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->surname = new char[strlen(surname) + 1];
    strcpy(this->surname, surname);
    this->semester = semester;
}

Student::~Student() {
    delete[] name;
    delete[] surname;
}

const char* Student::getName() const {
    return name;
}

const char* Student::getSurname() const {
    return surname;
}

int Student::getSemester() const {
    return semester;
}

StudentList::StudentList() {
    size = 0;
    capacity = 1;
    students = new Student*[capacity];
}

StudentList::~StudentList() {
    clearStudents();
}

void StudentList::addStudent(const char* name, const char* surname, int semester) {
    if (size == capacity) {
        resize();
    }

    students[size] = new Student(name, surname, semester);
    size++;
}

void StudentList::resize() {
    capacity *= 2;
    Student** newStudents = new Student*[capacity];
    for (int i = 0; i < size; i++) {
        newStudents[i] = students[i];
    }
    delete[] students;
    students = newStudents;
}

void StudentList::printStudents() const {
    for (int i = 0; i < size; i++) {
        std::cout << students[i]->getSurname() << ", " << students[i]->getName() << " - semestr " << students[i]->getSemester() << std::endl;
    }
}

void StudentList::deleteStudent(int index) {
    if (index < 0 || index >= size) {
        return; // Invalid index
    }

    delete students[index];
    for (int i = index; i < size - 1; i++) {
        students[i] = students[i + 1];
    }
    size--;
}

void StudentList::clearStudents() {
    for (int i = 0; i < size; i++) {
        delete students[i];
    }
    delete[] students;
    size = 0;
    capacity = 1;
    students = new Student*[capacity];
}