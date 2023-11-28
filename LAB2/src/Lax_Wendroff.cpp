#include "Includes.h"

Lax_Wendroff(Lx, Ly){
    for(int i = 0; i < Lx, ++i){
        for(int j = 0; j < Ly, ++j){
            XY[i][j] = 0;
        }
    }
}

//uzgodnij wymiary map i usprawnij petle
//dla kazdej iteracji czasowej zapisz wartosci tablic do pliku
void Lax_Wendroff::U(int dt, ){
    dt = 1;
    dx = 1;
    for(int t = 0; i < time; ++t){
        for(int i = 0; i < Lx; ++i){
            for(int j = 0; j < Ly; ++j){
                U[t+1][i+1][j] =  0.5 * (U[t][i+2][j] + U[t][i][j] - dt/dx * (F[t][i+2][j] - F[t][i][j]));
                U[t+1][i][j+1] =  0.5 * (U[t][i][j+2] + U[t][i][j] - dt/dy * (G[t][i][j+2] - G[t][i][j]));
                U[t+2][i][j] =  U[t][i][j] - dt/dx * (F[t+1][i+1][j] - F[t+1][i-1][j]) - dt/dy * (G[t+1][i][j+1] - G[t+1][i][j-1]);
            }
        }
    }
}
