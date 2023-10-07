#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>
#include <cmath>
#include <complex>
#include <sstream>
#include <string>

bool isNumber(const std::string& str) {
    std::istringstream iss(str);
    double d;
    iss >> d;
    return !iss.fail() && iss.eof();
}

int main(int argc, char* argv[])
{
    float a,b,c;
    switch (argc)
    {
    case 1:
        std::cout << "No arguments provided.\n";
        return 0;
    case 2:
        if (isNumber(argv[1]) == false)
        {
            std::cout << "Argument 1 is not a number.\n";
            return 1;
        }
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        a = std::atof(argv[1]);
        b = static_cast<int>(b);
        b = std::rand() % static_cast<int>(a);

        std::cout << "Do programu podano liczbę " << a << ". Wylosowano liczbę " << b << ". Wszystkie liczby nieparzyste naturalne mniejsze lub równe " << a << ":" << std::endl;

        for (int i = 1; i <= static_cast<int>(a); i++) {
            if (i % 2 == 1) {
                std::cout << i << " ";
            }
        }

        std::cout << std::endl;
        break;
    case 3:
        if (isNumber(argv[1]) == false || isNumber(argv[2]) == false)
        {
            std::cout << "Argument 1 or 2 is not a number.\n";
            return 1;
        }
        a = std::atof(argv[1]);
        b = std::atof(argv[2]);

        if(!(std::abs(a) < 1e-7))
        {
            if (std::abs(b) < 1e-7)
                std::cout << "Do programu podano funkcję f(x) = " << a << "*x. Rozwiązaniem równania f(x) = 0 jest x = 0" << std::endl;
            else
                std::cout << "Do programu podano funkcję f(x) = " << a << "*x + " << b << ". Rozwiązaniem równania f(x) = 0 jest x = " << -b/a <<std::endl;
        }
        else
        {
            std::cout << "Do programu podano funkcję f(x) = " << b << std::endl;
            std::cout << "Funkcja jest stała, nie ma rozwiązania równania f(x) = 0." << std::endl;
        }
        break;
    case 4:
        if (isNumber(argv[1]) == false || isNumber(argv[2]) == false || isNumber(argv[3]) == false)
        {
            std::cout << "Argument 1, 2 or 3 is not a number.\n";
            return 1;
        }
        a = std::atof(argv[1]);
        b = std::atof(argv[2]);
        c = std::atof(argv[3]);
        if ((std::abs(a) < 1e-7))
        {
            if (std::abs(b) < 1e-7)
            {
                if (std::abs(c) < 1e-7)
                    std::cout << "Do programu podano funkcję f(x) = " << c << ". Rozwiązaniem równania f(x) = 0 jest x każde x należące do dziedziny." << std::endl;
                else
                    std::cout << "Do programu podano funkcję f(x) = " << c << ". Funkcja jest stała, nie ma rozwiązania równania f(x) = 0." << std::endl;
            }
            else
                std::cout << "Do programu podano funkcję f(x) = " << b << "*x + " << c << ". Rozwiązaniem równania f(x) = 0 jest x = " << -c/b << std::endl;
            break;
        }
        else
        {
            if (b*b - 4*a*c > 0) // delta > 0
            {
                std::cout << "Do programu podano funkcję f(x) = " << a << "*x^2 + " << b << "*x + " << c << ". Rozwiązaniem równania f(x) = 0 są x1 = " << (-b + std::sqrt(b*b - 4*a*c))/(2*a) << " oraz x2 = " << (-b - std::sqrt(b*b - 4*a*c))/(2*a) << std::endl;
            }
            else if (std::abs(b*b - 4*a*c) < 1e-7) // delta = 0
            {
                std::cout << "Do programu podano funkcję f(x) = " << a << "*x^2 + " << b << "*x + " << c << ". Rozwiązaniem równania f(x) = 0 jest x = " << -b/(2*a) << std::endl;
            }
            else // delta < 0
            {
                std::complex<float> x1, x2;
                x1 = (-std::complex<float>(b) + std::sqrt(std::complex<float>(b*b - 4*a*c)))/(2*a);
                x2 = (-std::complex<float>(b) - std::sqrt(std::complex<float>(b*b - 4*a*c)))/(2*a);
                std::cout << "Do programu podano funkcję f(x) = " << a << "*x^2 + " << b << "*x + " << c << ". Rozwiązaniem równania f(x) = 0 są x1 = " << x1 << " oraz x2 = " << x2 << std::endl;
            }
        }
        break;
    default:
        std::cout << "Too many arguments provided.\n";
        break;
    }

    return 0;
}