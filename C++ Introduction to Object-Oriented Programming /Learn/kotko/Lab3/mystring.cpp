#include "mystring.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

const int STRINGS_AMOUNT = 5;
const MyString *strings[STRINGS_AMOUNT];
int StoredStrings = 0;

/// Funkcja tworzaca nowy obiekt zawierajacy podany w argumencie tekst oraz jego dlugosc
MyString* CreateString(const char* text){
    if(text == NULL){
        printf("CreateString: NULL pointer passed. No object created.\n");
        return NULL;
    }
    if(StoredStrings >= STRINGS_AMOUNT){
        printf("CreateString: Maximum no of strings has been reached.\n");
        return NULL;
    }
    const int len = strlen(text)+1;
    if(len > 13){
        printf("CreateString: String is too long.\n");
        return NULL;
    }
    MyString *ret = new MyString;
    ret->str = text;
    ret->length = len;
    strings[StoredStrings++] = ret;
    return ret;
}
/// Funkcja wyswietlajaca na ekranie tekst zawarty w obiekcie podanym jako argument
void PrintMyString(MyString *str){
    if(str == NULL){
        printf("PrintMyString: NULL pointer passed.\n");
        return;
    }
    printf("%s\n", str->str);
}
/// Funkcja kasujaca wszystkie przechowywane obiekty typu MyString
void ClearStrings(){
    for(int i = 0; i< StoredStrings; i++){
        delete strings[i];
    }
    StoredStrings = 0;
}

