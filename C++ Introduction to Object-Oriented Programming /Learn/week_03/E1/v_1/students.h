#ifndef STUDENTS_H
#define STUDENTS_H

class Student {
public:
    Student(const char* name, const char* surname, int semester);
    ~Student();

    const char* getName() const;
    const char* getSurname() const;
    int getSemester() const;

private:
    char* name;
    char* surname;
    int semester;
};

class StudentList {
public:
    StudentList();
    ~StudentList();

    void addStudent(const char* name, const char* surname, int semester);
    void printStudents() const;
    void deleteStudent(int index);
    void clearStudents();

private:
    Student** students;
    int size;
    int capacity;

    void resize();
};

#endif