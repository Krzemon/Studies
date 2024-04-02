//Prosze dopisac kod, w razie potrzeby dodac nowe pliki, tak aby program wykonywal się,
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku. Proszę nie modyfikować pliku main.cpp !
//
//Rozwijamy kod napisany na ostatnich zajęciach.
//
//Szczegóły:
//1. Uzupełnij klasę Series o konstruktor przenoszący i przypisanie przenoszące (oba w wersji głośnej).
//2. Operator << klasy Series przepisz tak by wypisywał: "nazwa serii: [wartości w wierszach]."
//3. Klasę Histogram uzupełnij o operator()(string name,unsigned row) umożliwiający dostęp (odczyt i zapis) do dowolnego wiersza w dowolnej Serii (tradycyjnie sięganie poza zakres ma się kończyć wyjątkiem).
//4. Klasę Series uzupełnij o metodę vector<double> get_series_view(function<bool(double)>) przyjmującą jako parametr predykat (czyli obiekt klasy function<bool(double)>) i zwracającą vector elementów, dla których predykat jest prawdziwy. Działanie przetestuj na dwóch warunkach:
//    - elementy serii >10
//    - elementy serii >10 i <20.

#include <iostream>
#include "Histogram.hpp"
#include "predicates.h"

int main(int argc, const char * argv[]) {
    
    Series s1=Series("Test",2);
    s1[0]=1.2;
    s1[1]=1.3;
    std::cout<<s1<<"\n";
    Series s2=std::move(s1);
    std::cout<<s2<<"\n";
    Series s3;
    s3=std::move(s2);
    s3.append(12);
    s3.append(13);
    s3.append(22);
    std::cout<<s3<<"\n";
    std::cout<<"------------------\n";
    
    Histogram h1=Histogram();
    h1.add_series("liczby dodatnie");
    h1["liczby dodatnie"].append(1.5);
    h1["liczby dodatnie"].append(11.5);
    h1["liczby dodatnie"].append(12.5);
    std::cout<<h1["liczby dodatnie"]<<"\n";
    h1("liczby dodatnie",2)=22.5;
    std::cout<<h1["liczby dodatnie"]<<"\n";
    h1["liczby dodatnie"].append(22.5);
    h1["liczby dodatnie"].append(32.5);
    h1["liczby dodatnie"].append(17.5);
    std::cout<<h1("liczby dodatnie",4)<<"\n";
    
    std::cout<<"-------------------\n";
    std::vector<double> gt10=h1["liczby dodatnie"].get_series_view(value_gt_10);
    std::vector<double> btwn10and20=h1["liczby dodatnie"].get_series_view(value_between_10_and_20);
    std::cout<<">10\n";
    for(auto x: gt10)
        std::cout<<x<<"\n";
    std::cout<<">10 <20\n";
    for(auto x: btwn10and20)
        std::cout<<x<<"\n";
    return 0;
}

//Test: [1.2,1.3]
//Konstruktor przenoszący klasy Series
//Test: [1.2,1.3]
//Przenoszący operator przypisania klasy Series
//Test: [1.2,1.3,12,13,22]
//------------------
//Konstruktor klasy Histogram
//Przenoszący operator przypisania klasy Series
//Destruktor klasy Series
//liczby dodatnie: [1.5,11.5,12.5]
//liczby dodatnie: [1.5,11.5,22.5]
//32.5
//-------------------
//>10
//11.5
//22.5
//22.5
//32.5
//17.5
//>10 <20
//11.5
//17.5
//Destruktor klasy Histogram
//Destruktor klasy Series
//Destruktor klasy Series
//Destruktor klasy Series
//Destruktor klasy Series
//Program ended with exit code: 0
