#ifndef h_mystring
#define h_mystring

const int STRING_LENGTH = 13;

struct MyString{
    const char *str;
    int length;
};

/// Funkcja tworzaca nowy obiekt zawierajacy podany w argumencie tekst oraz jego dlugosc
MyString* CreateString(const char* text);
/// Funkcja wyswietlajaca na ekranie tekst zawarty w obiekcie podanym jako argument
void PrintMyString(MyString *str);
/// Funkcja kasujaca wszystkie przechowywane obiekty typu MyString
void ClearStrings();
#endif
