#include "well1D.hpp"
#include "constants.hpp"

#include <cmath>
#include <fstream>

Well1D::Well1D(double L, int N)
{
    mWell_geom.Lenght = L;
    mWell_geom.NumDiv = N;
    mWell_geom.dx = L / N;

    mpV = new double[N + 1]{};
    mpWF = new double[N + 1]{};

    mpWF[1] = 1.0;
}

Well1D::~Well1D()
{
    delete[] mpV;
    delete[] mpWF;
}

void Well1D::normalizeWF()
{
    double norm_factor{};
    for (int i = 1; i < mWell_geom.NumDiv + 1; ++i)
    {
        norm_factor += mpWF[i] * mpWF[i];
    }

    norm_factor = std::sqrt(norm_factor * ab_to_nm(mWell_geom.dx));

    for (int i = 1; i < mWell_geom.NumDiv + 1; ++i)
    {
        mpWF[i] /= norm_factor;
    }
}

void Well1D::setPointBarierV(double V0, int idx)
{
    mpV[idx] = V0;
}

void Well1D::resetV()
{
    for (int i = 0; i < mWell_geom.NumDiv + 1; ++i)
    {
        mpV[i] = 0.0;
    }
}

void Well1D::calcWF(const double E, bool normalize)
{
    mpWF[0] = 0.0;
    mpWF[1] = 1.0;

    for (int i = 1; i < mWell_geom.NumDiv; ++i)
    {
        mpWF[i + 1] = -2.0 * m / h_bar / h_bar * (E - mpV[i]) * mWell_geom.dx * mWell_geom.dx * mpWF[i] + 2.0 * mpWF[i] - mpWF[i - 1];
    }

    if (normalize)
    {
        normalizeWF();
    }
}

void Well1D::resetWF()
{
    for (int i = 0; i < mWell_geom.NumDiv + 1; ++i)
    {
        mpWF[i] = 0.0;
    }

    mpWF[1] = 1.0;
}

void Well1D::printWF(const std::string &filename)
{
    std::fstream WF_file(filename, std::ios::out);

    for (size_t i = 0; i < mWell_geom.NumDiv + 1; ++i)
    {
        WF_file << ab_to_nm(mWell_geom.dx * i) << " " << mpWF[i] << std::endl;
    }

    WF_file.close();
}

double *Well1D::getpWF(const double E, bool normalize)
{
    calcWF(E, normalize);

    return mpWF;
}

double Well1D::getWF_N(const double E, bool normalize)
{
    calcWF(E, normalize);
    return mpWF[mWell_geom.NumDiv];
}
