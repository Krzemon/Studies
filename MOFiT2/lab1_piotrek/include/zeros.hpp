#ifndef ZEROS_HPP
#define ZEROS_HPP

#include "well1D.hpp"

#include <cmath>

double bisection(Well1D &well, double E_left, double E_right, const double eps_E)
{
    double E_mid = (E_left + E_right) / 2.0;

    double WF_N_left = well.getWF_N(E_left);
    double WF_N_mid = well.getWF_N(E_mid);
    double WF_N_right = well.getWF_N(E_right);

    while (true)
    {
        if ((WF_N_left > 0 && WF_N_mid > 0) || (WF_N_left < 0 && WF_N_mid < 0))
        {
            E_left = E_mid;
            WF_N_left = WF_N_mid;
        }
        else
        {
            E_right = E_mid;
            WF_N_right = WF_N_mid;
        }

        E_mid = (E_left + E_right) / 2.0;
        WF_N_mid = well.getWF_N(E_mid);

        if (std::fabs(E_right - E_left) < eps_E)
        {
            break;
        }
    }

    return E_mid;
};

std::vector<double> findZerosWF_N(Well1D &well, const double x_min, const double x_max, const double dx, const double eps_x)
{
    std::vector<double> zeros{};

    double x_left = x_min;
    double x_right = x_min + dx;

    double WF_N_left = well.getWF_N(x_left);
    double WF_N_right = well.getWF_N(x_right);

    while (x_right <= x_max)
    {
        if ((WF_N_left > 0 && WF_N_right < 0) || (WF_N_left < 0 && WF_N_right > 0))
        {
            zeros.push_back(bisection(well, x_left, x_right, eps_x));
        }

        x_left = x_right;
        x_right += dx;

        WF_N_left = WF_N_right;
        WF_N_right = well.getWF_N(x_right);
    }

    return zeros;
};

std::vector<double> findZerosWF_N(Well1D &well, const double x_min, const double x_max, const double dx, const double eps_x, int k)
{
    std::vector<double> zeros(k, 0.0);

    double x_left = x_min;
    double x_right = x_min + dx;

    double WF_N_left = well.getWF_N(x_left);
    double WF_N_right = well.getWF_N(x_right);

    for (int i = 0; i < k && x_right <= x_max;)
    {
        if ((WF_N_left > 0 && WF_N_right < 0) || (WF_N_left < 0 && WF_N_right > 0))
        {
            zeros[i] = bisection(well, x_left, x_right, eps_x);
            i++;
        }

        x_left = x_right;
        x_right += dx;

        WF_N_left = WF_N_right;
        WF_N_right = well.getWF_N(x_right);
    }

    return zeros;
};

#endif // ZEROS_HPP