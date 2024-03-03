#ifndef h_fvector
#define h_fvector

struct FourVector{
    double t;
    double x;
    double y;
    double z;
    double M;
};

/// Funkcja tworzaca obiekt FourVector z podanych danych i zwracajaca wskaznik na nowo stworzony obiekt
FourVector* CreateFourVector(double *cords);
/// Funkcja wyswietlajaca na ekran wskaznik do obiektu FourVector w formacie (t,x,y,z)
void PrintFourVector(FourVector *vec);
/// Funkcja wyswietlajaca na ekran obiekt FourVector w formacie (t,x,y,z)
void PrintFourVector(FourVector vec);
/// Funkcja kasujaca z pamieci obiekt typu FourVector na ktory wskazuje argument
void DeleteFourVector(FourVector *vec);

#endif
