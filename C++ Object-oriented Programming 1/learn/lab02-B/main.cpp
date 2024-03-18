// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się,
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.
//
//Szczegóły:
//W tym zadaniu zaprogramujemy operatory indeksowania [] działające na indeksach całkowitych i typu string.
//Zaprogramuj klasę do operowania na histogramach. Histogram będzie zbiorem obiektów klasy Series mających nazwę
//i zawierających dynamicznie alokowaną tablicę wartości double.
//Do pustego histogramu hist dodajemy serię metodą hist.add_series("nazwa"). Z kolei do serii w histogramie
//dodajemy wiersz metodą hist["nazwa"].apppend(3.1415). Wreszcie, wartość konkretnego wiersza możemy zmodyfikować np.
//wywołaniem hist["nazwa"][3]=2.71 i pobrać np. wywołaniem double x=hist["nazwa"][3]. Ponadto dla obiektów Series
//zaimplementuj operator += umożliwiający dodawanie do siebie zawartości obiektów Series w zaktesie elementów ograniczonym
//mniejszą z nich, tzn. min(hist["seria1"].size(),hist["seria2"].size()).
//Próby sięgania poza zakres Serii lub wierszy powinny się kończyć wyrzuceniem odpowiednich wyjątków. W oparciu o
//pliki nagłówkowe Histogram.h i Series.h zaprogramuj odpowiednie klasy i wykonaj ciąg poniższych operacji tak by uzyskać podany niżej wynik.

//Program (tylko kod źródłowy plus ewentualny skrypt kompilujący) należy umieścić w folderze i spakować przy pomocy zip lub tar.gz.
//Pamiętaj o dokumentacji.
//Powodzenia!

#include <iostream>
#include "Histogram.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout<<"Test"<<std::endl;
    Histogram h1=Histogram();
    h1.add_series("liczby dodatnie");
    h1["liczby dodatnie"].append(10.5);
    h1["liczby dodatnie"].append(11.5);
    h1["liczby dodatnie"].append(12.5);
    std::cout<<"Seria dodatnia"<<std::endl;
    std::cout<<h1["liczby dodatnie"]<<std::endl;
    
    h1.add_series("liczby ujemne");
    h1["liczby ujemne"].append(-10.5);
    h1["liczby ujemne"].append(-11.5);
    h1["liczby ujemne"].append(-12.5);
    std::cout<<"Seria ujemna"<<std::endl;
    std::cout<<h1["liczby ujemne"]<<std::endl;
    std::cout<<"Ustawiam pierwszy element ujemnych na -10.5"<<std::endl;
    h1["liczby ujemne"][1]=-10.5;
    
    
    std::cout<<"Seria dodatnia"<<std::endl;
    std::cout<<h1["liczby dodatnie"]<<std::endl;
    std::cout<<"Seria ujemna"<<std::endl;
    std::cout<<h1["liczby ujemne"]<<std::endl;
    std::cout<<"Nagłówki serii:"<<std::endl;
    for(auto x: h1.get_series_names())
        std::cout<<x<<std::endl;
    std::cout<<"Dodaję serię ujemną do dodatniej"<<std::endl;
    h1["liczby dodatnie"]+=h1["liczby ujemne"];
    std::cout<<h1["liczby dodatnie"]<<std::endl;
    std::cout<<"Dodaję serię dodatnią do ujemnej"<<std::endl;
    h1["liczby ujemne"]+=h1["liczby dodatnie"];
    std::cout<<h1["liczby ujemne"]<<std::endl;
    return 0;
}
/* ---Program powinie
 Konstruktor klasy Histogram
 Kopiujący operator przypisania klasy Series
 Destruktor klasy Series
 Seria dodatnia
 [10.5,11.5,12.5]
 Kopiujący operator przypisania klasy Series
 Kopiujący operator przypisania klasy Series
 Destruktor klasy Series
 Destruktor klasy Series
 Seria ujemna
 [-10.5,-11.5,-12.5]
 Ustawiam pierwszy element ujemnych na -10.5
 Seria dodatnia
 [10.5,11.5,12.5]
 Seria ujemna
 [-10.5,-10.5,-12.5]
 Nagłówki serii:
 liczby dodatnie
 liczby ujemne
 Dodaję serię ujemną do dodatniej
 [0,1,0]
 Dodaję serię dodatnią do ujemnej
 [-10.5,-9.5,-12.5]
 Destruktor klasy Histogram
 Destruktor klasy Series
 Destruktor klasy Series
 */
