#include "combined.h"


int main() {
    // Parametry kół
    double RA = 1;
    double RB = std::sqrt(2) * RA;

    // Zadanie 1: Obliczanie wspólnej powierzchni kół
    double xA = 0.5 * RA; // Wartość xA do zmiany
    double common_area = calculate_common_area(xA, RA, RB);
    std::cout << "Wspólna powierzchnia kół: " << common_area << std::endl;

    // Zadanie 2: Generowanie punktów w kole KA i KB
    const int N = 10000;
    double xA_KA = RA + RB;
    double xA_KB = 0;
    auto points_KA = generate_points_in_circle(xA_KA, 0, RA, N);
    auto points_KB = generate_points_in_circle(xA_KB, 0, RB, N);

    // Przykład wyświetlenia wygenerowanych punktów w kole KA
    std::cout << "Wygenerowane punkty w kole KA:" << std::endl;
    for (const auto& point : points_KA) {
        std::cout << "(" << point.x << ", " << point.y << ")" << std::endl;
    }

    // Zadanie 3: Generowanie punktów wewnątrz koła Kα
    int n_values[] = {10000, 100000, 1000000, 10000000, 100000000, 1000000000};
    for (int n : n_values) {
        auto points_within_circle = generate_points_in_circle(RB + 0.5 * RA, 0, RA, n);
        // Obliczanie wartości S̄α,β i σS̄α,β
        // ...
    }

    return 0;
}