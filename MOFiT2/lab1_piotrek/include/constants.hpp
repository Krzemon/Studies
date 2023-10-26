#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

const double m = .067;    // mass of electron in a.u. in GaAs
const double h_bar = 1.0; // h_bar in a.u.
const double Ha_to_meV_CF = 27211.386245; // Hartree to meV CF.
constexpr double ab_to_nm_CF = 0.05292; // Bohr to nm

inline double Ha_to_meV(double E)
{
    return E * Ha_to_meV_CF;
}

inline double meV_to_Ha(double E)
{
    return E / Ha_to_meV_CF;
}

inline double ab_to_nm(double L)
{
    return L * ab_to_nm_CF;
}

inline double nm_to_ab(double L)
{
    return L / ab_to_nm_CF;
}

#endif // CONSTANTS_HPP