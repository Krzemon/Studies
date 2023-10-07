#include <iostream>
#include <iomanip>

#define maxFieldWidth 1

void pascal(int n);
int wartosc(int a, int b);
bool isEven(int number);
void sierpinski(int n);

int main()
{
    int n;
    std::cout << "Podaj ilość wierszy trójkąta Pascala do wypisania: ";
    std::cin >> n;
    sierpinski(n);
    return 0;
}

int wartosc(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    else
        return wartosc(n - 1, k - 1) + wartosc(n - 1, k);
}
/*
void pascal(int n)
{
    int fieldWidth = 2 * maxFieldWidth;
    for (int i = 0; i < n; i++)
    {
        int spacesBefore = (n - i - 1) * maxFieldWidth;

        std::cout << std::setw(spacesBefore) << "";

        for (int j = 0; j <= i; ++j)
        {
            int value = wartosc(i, j);
            std::cout << std::setw(fieldWidth) << std::right << value;
        }

        std::cout << std::endl;
    }
}
*/
bool isEven(int k)
{
    return k % 2 == 0;
}

void sierpinski(int n)
{
    int fieldWidth = 2 * maxFieldWidth;
    for (int i = 0; i < n; i++)
    {
        int spacesBefore = (n - i - 1) * maxFieldWidth;

        std::cout << std::setw(spacesBefore) << "";

        for (int j = 0; j <= i; ++j)
        {
            int value = wartosc(i, j);
            if(isEven(value))
            {
                std::cout << std::setw(fieldWidth) << std::right << ".";
            }
            else
            {
                std::cout << std::setw(fieldWidth) << std::right << " ";
            }
        }

        std::cout << std::endl;
    }
}