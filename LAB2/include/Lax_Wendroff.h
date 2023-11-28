#include "Includes.h"



class Lax_Wendroff{
public:
    
    void U_x();
    void U_y();
    void U_1();
private:
    //definicja puntktu plaszczyzny przy pomocy mapy
    //stworz singleton tej klasy
    Lax_Wendroff();
    ~Lax_Wendroff();


    //X Y WARTOSC dla plikow U F G
    // te mapy maja byc 3d. albo 2d z uprzednim zapisem do plikow
    std::map<int, int> U;
    std::map<int, int> F;
    std::map<int, int> G;  
};



