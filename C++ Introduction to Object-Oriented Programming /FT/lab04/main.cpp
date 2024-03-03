#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cmath>

bool isNumber(const std::string& str);
void switches(char& tekstura, int& liczba_binow, int& wysokosc, float& x_min, float& x_max, int& N, int argc, char* argv[]);
void histogram(const char& tekstura, const int& liczba_binow, const int& wysokosc, const float& x_min, const float& x_max, const int& N);

int main(int argc, char* argv[]){
    char tekstura = '|';    // znak reprezentujący histogram
    int liczba_binow = 50;  // ilość binów
    int wysokosc = 20;      // wysokość histogramu
    float x_min = 0;        // dolny zakres losowania
    float x_max = 1;        // górny zakres losowania
    int N = 2;              // ilość liczb z których wyliczana jest średnia

    
    if(argc > 1)
        switches(tekstura, liczba_binow, wysokosc, x_min, x_max, N, argc, argv);
    else
        std::cout << "Nie podano argumentów. Użyto wartości domyślnych.\n";
    
    histogram(tekstura, liczba_binow, wysokosc, x_min, x_max, N);

    return 0;
}

void histogram(const char& tekstura, const int& liczba_binow, const int& wysokosc, const float& x_min, const float& x_max, const int& N) {
    srand(time(NULL));

    float* tab = new float[1000]{0};
    float* data = new float[liczba_binow]{0};
    float h_max = 0;
    float suma = 0;
    float suma_kwadratow = 0;

    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j < N; ++j) 
            tab[i] += static_cast<float>(rand()) / (RAND_MAX + 1.0); // Zakres [0, 1)
        tab[i] /= N;
        suma += tab[i];
        suma_kwadratow += tab[i] * tab[i];

        int bin_index = static_cast<int>((tab[i] - x_min) / (x_max - x_min) * liczba_binow);
        if (bin_index >= 0 && bin_index < liczba_binow)
            data[bin_index]++;
    }
    delete[] tab;

    float srednia = suma / 1000;
    float wariancja = (suma_kwadratow - (suma * suma) / 1000) / (1000 - 1);
    float odchylenie = sqrt(wariancja);

    for (int i = 0; i < liczba_binow; ++i)
        if (data[i] > h_max)
            h_max = data[i];

    float delta = h_max / (wysokosc + 1);

    for (int i = 0; i < liczba_binow; ++i)
        std::cout << "-";
    std::cout << std::endl;

    for (int i = wysokosc; i >= 0; --i) {
        for (int j = 0; j < liczba_binow; ++j) {
            if (data[j] > delta * i)
                std::cout << tekstura;
            else
                std::cout << ' ';
        }
        std::cout << "     " << delta * i << std::endl;
    }

    for (int i = 0; i < liczba_binow; ++i)
        std::cout << "-";
    std::cout << std::endl;

    delete[] data;
    std::cout << "Średnia: " << srednia << std::endl;
    std::cout << "Odchylenie standardowe: " << odchylenie << std::endl;
}


bool isNumber(const std::string& str) {
    std::istringstream iss(str);
    double d;
    iss >> d;
    return !iss.fail() && iss.eof();
}

void switches(char& tekstura, int& liczba_binow, int& wysokosc, float& x_min, float& x_max, int& N, int argc, char* argv[]){
    std::string argument = argv[1];
    switch (argc-1){
        case 6:
            if (isNumber(argv[6]) == false){
                std::cout << "Argument reprezentujący N nie jest liczbą.\n";
                exit(1);
            }
            else if (std::atoi(argv[6]) < 1 || std::atoi(argv[6]) > 100){
                std::cout << "Argument reprezentujący N powinien być w zakresie od 1 do 100.\n";
                exit(1);
            }
            else
                N = std::atoi(argv[6]);
        
        case 5:
            if (isNumber(argv[5]) == false){
                std::cout << "Argument reprezentujący x_max nie jest liczbą.\n";
                exit(1);
            }
            else if (std::atof(argv[5]) < 0 || std::atof(argv[5]) > 1){
                std::cout << "Argument reprezentujący x_max powinien być w zakresie od 0 do 1.\n";
                exit(1);
            }
            else{
                if (std::atof(argv[4]) > x_max){
                    std::cout << "Argument reprezentujący x_min jest większy od x_max.\n";
                    exit(1);
                }
                else if (std::atof(argv[4]) == x_max){
                    std::cout << "Argument reprezentujący x_min jest równy x_max.\n";
                    exit(1);
                }
                else
                    x_max = std::atof(argv[5]);
            }
            
        case 4:
            if (isNumber(argv[4]) == false){
                std::cout << "Argument reprezentujący x_min nie jest liczbą.\n";
                exit(1);
            }
            else if (std::atof(argv[4]) < 0 || std::atof(argv[4]) > 1){
                std::cout << "Argument reprezentujący x_min powinien być w zakresie od 0 do 1.\n";
                exit(1);
            }
            else{
                if (x_min > x_max){
                    std::cout << "Argument reprezentujący x_min jest większy od x_max.\n";
                    exit(1);
                }
                else if (x_min == x_max){
                    std::cout << "Argument reprezentujący x_min jest równy x_max.\n";
                    exit(1);
                }
                else
                    x_min = std::atof(argv[4]);
            }

        case 3:
            if(isNumber(argv[3]) == false){
                std::cout << "Argument reprezentujący wysokosc nie jest liczbą.\n";
                exit(1);
            }
            else if (std::atoi(argv[3]) < 1 || std::atoi(argv[3]) > 100){
                std::cout << "Argument reprezentujący wysokosc powinien być w zakresie od 1 do 100.\n";
                exit(1);
            }
            else
                wysokosc = std::atoi(argv[3]);

        case 2:
            if (isNumber(argv[2]) == false){
                std::cout << "Argument reprezentujący ilość binów nie jest liczbą.\n";
                exit(1);
            }
            else if (std::atoi(argv[2]) < 1 || std::atoi(argv[2]) > 100){
                std::cout << "Argument reprezentujący ilość binów powinien być w zakresie od 1 do 100.\n";
                exit(1);
            }
            else
                liczba_binow = std::atoi(argv[2]);

        case 1:
            if (argument.length() == 1){
                tekstura = argument[0];
            }
            else{
                std::cout << "Podałeś łańuch znaków, za teksturę przyjmuję pierwszy jego znak." << std::endl;
                tekstura = argument[0];
            }
            break;
        default:
            std::cout << "Podano za dużo argumentów." << std::endl;
            exit(1);
    }
}