#ifndef WELL1D_HPP
#define WELL1D_HPP

#include <string>

struct well_geom
{
    double Lenght;
    int NumDiv;
    double dx;
};

class Well1D
{
private:
    well_geom mWell_geom{};
    double *mpV;
    double *mpWF;
    void normalizeWF();

public:
    Well1D(double L, int N);
    ~Well1D();

    void setPointBarierV(double V0, int idx);
    void resetV();

    void calcWF(const double E, bool normalize = false);
    void resetWF();
    void printWF(const std::string &filename);

    double *getpWF() const { return mpWF; }
    double *getpWF(const double E, bool normalize = false);

    double getWF_N() const { return mpWF[mWell_geom.NumDiv]; }
    double getWF_N(const double E, bool normalize = false);
    
    const well_geom &getWellGeom() const { return mWell_geom; }
};

#endif // WELL1D_HPP