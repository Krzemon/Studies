#ifndef STUDENTS_H
#define STUDENTS_H

#include <iostream>
#include <cstring>

void AddStudent(int* numberOfStudents, char*** namesList, char*** surnamesList, int** semesterList, const char* names, const char* surname, int semester);
void PrintListContent(int numberOfStudents, char** surnameList);
void PrintListContent(int numberOfStudents, int* semesterList);
void PrintListContent(int numberOfStudents, char** namesList, char** surnamesList);
void PrintListContent(int numberOfStudents, char** namesList, char** surnamesList, int* semesterList);

void DeleteStudent(int* numberOfStudents, char*** namesList, char*** surnamesList, int** semesterList, int index);
void ClearStudents(int* numberOfStudents, char*** namesList, char*** surnamesList, int** semesterList);

#endif