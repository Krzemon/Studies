#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <iomanip>

double uniform() {
    return (double)rand() / RAND_MAX;
}

double Bernoulli(double p) {
    if (uniform() <= p)
        return 1;
    else
        return 0;
}

void toFile(std::ofstream &file, int k, double relative_EX, double relative_var) {
    const int DISPLAY_PRECISION = 7;
    file << std::fixed << std::setprecision(DISPLAY_PRECISION);
    file << k << '\t' << relative_EX << '\t' << relative_var << std::endl;
}

void parametres(double p, double &EX, double &EXsquare, double &var, std::ofstream &file) {
    const int N = 1e7;
    int k = 2;
    double x;

    for (int i = 1; i < N + 1; ++i) {
        x = Bernoulli(p);
        EX += x;
        EXsquare += (x * x);

        if (i == std::pow(10, k)) {
            EX /= i;
            EXsquare /= i;
            var = (EXsquare - EX * EX);

            double relative_EX = 0.0;
            if (std::abs(p * (1 - p)) > 1e-9) {
                relative_EX = std::fabs(EX - p) / p;
            }

            double relative_var = 0.0;
            if (std::abs(p * (1 - p)) > 1e-9) {
                // Handle division by zero
                if (p * (1 - p) != 0) {
                    relative_var = std::abs(var - p * (1 - p)) / (p * (1 - p));
                } else {
                    relative_var = 0.0;
                }
            }
            toFile(file, k, relative_EX, relative_var);
            ++k;
        }
    }
}

int main() {
    double tab[] = {0.1, 0.5, 0.9};

    double X1, X2, X3;
    double EXsquare1, EXsquare2, EXsquare3;
    double var1, var2, var3;

    std::ofstream file_p01("../data/p01.dat", std::ios::out);
    std::ofstream file_p05("../data/p05.dat", std::ios::out);
    std::ofstream file_p09("../data/p09.dat", std::ios::out);

    parametres(tab[0], X1, EXsquare1, var1, file_p01);
    parametres(tab[1], X2, EXsquare2, var2, file_p05);
    parametres(tab[2], X3, EXsquare3, var3, file_p09);

    file_p01.close();
    file_p05.close();
    file_p09.close();

    return 0;
}
