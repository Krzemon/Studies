#include "students.h"

void AddStudent(int* numberOfStudents, char*** namesList, char*** surnamesList, int** semesterList, const char* names, const char* surname, int semester) {
    int newStudentsCount = *numberOfStudents + 1;

    char** newNamesList = new char*[newStudentsCount];
    char** newSurnamesList = new char*[newStudentsCount];
    int* newSemesterList = new int[newStudentsCount];

    for (int i = 0; i < *numberOfStudents; ++i) {
        newNamesList[i] = new char[strlen((*namesList)[i]) + 1];
        newSurnamesList[i] = new char[strlen((*surnamesList)[i]) + 1];

        strcpy(newNamesList[i], (*namesList)[i]);
        strcpy(newSurnamesList[i], (*surnamesList)[i]);

        newSemesterList[i] = (*semesterList)[i];
    }

    newNamesList[newStudentsCount - 1] = new char[strlen(names) + 1];
    newSurnamesList[newStudentsCount - 1] = new char[strlen(surname) + 1];

    strcpy(newNamesList[newStudentsCount - 1], names);
    strcpy(newSurnamesList[newStudentsCount - 1], surname);
    newSemesterList[newStudentsCount - 1] = semester;

    if (*numberOfStudents > 0) {
        delete[] *namesList;
        delete[] *surnamesList;
        delete[] *semesterList;
    }

    *namesList = newNamesList;
    *surnamesList = newSurnamesList;
    *semesterList = newSemesterList;
    *numberOfStudents = newStudentsCount;
}


void PrintListContent(int numberOfStudents, char** surnameList) {
    for (int i = 0; i < numberOfStudents; ++i) {
        std::cout << surnameList[i] << std::endl;
    }
}

void PrintListContent(int numberOfStudents, int* semesterList) {
    for (int i = 0; i < numberOfStudents; ++i) {
        std::cout << semesterList[i] << std::endl;
    }
}

void PrintListContent(int numberOfStudents, char** namesList, char** surnamesList) {
    for (int i = 0; i < numberOfStudents; ++i) {
        std::cout << namesList[i] << " " << surnamesList[i] << std::endl;
    }
}

void PrintListContent(int numberOfStudents, char** namesList, char** surnamesList, int* semesterList) {
    for (int i = 0; i < numberOfStudents; ++i) {
        std::cout << namesList[i] << " " << surnamesList[i] << " " << semesterList[i] << std::endl;
    }
}


void DeleteStudent(int* numberOfStudents, char*** namesList, char*** surnamesList, int** semesterList, int index) {
    if (index >= 0 && index < *numberOfStudents) {
        int newStudentsCount = *numberOfStudents - 1;

        char** newNamesList = new char*[newStudentsCount];
        char** newSurnamesList = new char*[newStudentsCount];
        int* newSemesterList = new int[newStudentsCount];

        for (int i = 0, j = 0; i < *numberOfStudents; ++i) {
            if (i != index) {
                newNamesList[j] = new char[strlen((*namesList)[i]) + 1];
                newSurnamesList[j] = new char[strlen((*surnamesList)[i]) + 1];

                strcpy(newNamesList[j], (*namesList)[i]);
                strcpy(newSurnamesList[j], (*surnamesList)[i]);

                newSemesterList[j] = (*semesterList)[i];
                ++j;
            }
        }

        delete[] *namesList;
        delete[] *surnamesList;
        delete[] *semesterList;

        *namesList = newNamesList;
        *surnamesList = newSurnamesList;
        *semesterList = newSemesterList;
        *numberOfStudents = newStudentsCount;
    }
}

void ClearStudents(int* numberOfStudents, char*** namesList, char*** surnamesList, int** semesterList) {
    for (int i = 0; i < *numberOfStudents; ++i) {
        delete[] (*namesList)[i];
        delete[] (*surnamesList)[i];
    }

    delete[] *namesList;
    delete[] *surnamesList;
    delete[] *semesterList;

    *namesList = nullptr;
    *surnamesList = nullptr;
    *semesterList = nullptr;
    *numberOfStudents = 0;
}