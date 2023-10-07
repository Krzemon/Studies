#include <iostream>

//napisał sam Sikora

#define SIZE 10

namespace Statki {

  enum TypStatku {  CZTEROMASZTOWIEC=1,
                    TROJMASZTOWIEC=2,
                    DWUMASZTOWIEC=3,
                    JEDNOMASZTOWIEC=4,
                    liczbaTypowStatkow };

  struct Pozycja{
    int x = 0;
    int y = 0;
  };

  struct Statek{
    int n;
    Pozycja *koordynaty = nullptr;
  };

  struct Plansza{
    Statek *jeden[JEDNOMASZTOWIEC] = {nullptr};
    Statek *dwa[DWUMASZTOWIEC] = {nullptr};
    Statek *trzy[TROJMASZTOWIEC] = {nullptr};
    Statek *cztery[CZTEROMASZTOWIEC] = {nullptr};
  };

  bool dodajStatek(Plansza &, Pozycja, TypStatku);


  bool dodajStatek(Plansza & plansza, Pozycja pozycja, TypStatku typ){
    Statek **tab;
    switch(typ){
      case JEDNOMASZTOWIEC: tab = plansza.jeden; break;
      case DWUMASZTOWIEC: tab = plansza.dwa; break;
      case TROJMASZTOWIEC: tab = plansza.trzy; break;
      case CZTEROMASZTOWIEC: tab = plansza.cztery; break;
      default: break;
    }
    int j = typ-1;
    while(j>=0){
      if(tab[j])
        --j;
      else break;
    }
    if(j<0)
      return false;
    
    int shipSize = liczbaTypowStatkow - typ;
    Statek *statek = new Statek;
    statek->n = shipSize;
    statek->koordynaty = new Pozycja[shipSize];
    for(int i=0; i<shipSize; ++i){
      statek->koordynaty[i].x = pozycja.x + i;
      statek->koordynaty[i].y = pozycja.y;
    }
    tab[j] = statek;
    return true;
  }

}

namespace Grafika {

  void rysujPlansze(Statki::Plansza &);

  void rysujPlansze(Statki::Plansza & plansza){
    bool grid[SIZE][SIZE] = {{false}};
    
    Statki::Statek **tab;
    for(int i=1; i<Statki::liczbaTypowStatkow; ++i){
      switch(i){
        case Statki::JEDNOMASZTOWIEC: tab = plansza.jeden; break;
        case Statki::DWUMASZTOWIEC: tab = plansza.dwa; break;
        case Statki::TROJMASZTOWIEC: tab = plansza.trzy; break;
        case Statki::CZTEROMASZTOWIEC: tab = plansza.cztery; break;
        default: break;
      }
      for(int j=0; j<i; ++j){
        Statki::Statek *st = tab[j];
        if(st){
          for(int k=0; k<st->n; ++k)
            grid[st->koordynaty[k].x][st->koordynaty[k].y] = true;
        }
      }
    }
  
    for(int i=0; i<SIZE; ++i){
      for(int j=0; j<SIZE; ++j)
        std::cout << (grid[i][j] ? " X " : " . ");
      std::cout <<  std::endl;
    }
  }

}


void wyczyscPlansze(Statki::Plansza plansza){
  Statki::Statek **tab;
  for(int i=1; i<Statki::liczbaTypowStatkow; ++i){
    switch(i){
      case Statki::JEDNOMASZTOWIEC: tab = plansza.jeden; break;
      case Statki::DWUMASZTOWIEC: tab = plansza.dwa; break;
      case Statki::TROJMASZTOWIEC: tab = plansza.trzy; break;
      case Statki::CZTEROMASZTOWIEC: tab = plansza.cztery; break;
      default: break;
    }
    for(int j=0; j<i; ++j){
      Statki::Statek *st = tab[j];
      if(st){
        if(st->koordynaty)
          delete [] st->koordynaty;
        delete st;
      }
    }
  }
}




int main() {

  Statki::Plansza mojaGra;

  Statki::Pozycja pozycja; 

  pozycja.x = 0; pozycja.y = 0;
  Statki::dodajStatek(mojaGra, pozycja, Statki::JEDNOMASZTOWIEC);
  pozycja.x = 4; pozycja.y = 4;
  Statki::dodajStatek(mojaGra, pozycja, Statki::JEDNOMASZTOWIEC);
  pozycja.x = 6; pozycja.y = 6;
  Statki::dodajStatek(mojaGra, pozycja, Statki::JEDNOMASZTOWIEC);
  pozycja.x = 8; pozycja.y = 8;
  Statki::dodajStatek(mojaGra, pozycja, Statki::JEDNOMASZTOWIEC);

  pozycja.x = 8; pozycja.y = 0;
  Statki::dodajStatek(mojaGra, pozycja, Statki::DWUMASZTOWIEC);
  pozycja.x = 5; pozycja.y = 0;
  Statki::dodajStatek(mojaGra, pozycja, Statki::DWUMASZTOWIEC);
  pozycja.x = 0; pozycja.y = 8;
  Statki::dodajStatek(mojaGra, pozycja, Statki::DWUMASZTOWIEC);

  pozycja.x = 2; pozycja.y = 2;
  Statki::dodajStatek(mojaGra, pozycja, Statki::TROJMASZTOWIEC);
  pozycja.x = 7; pozycja.y = 2;
  Statki::dodajStatek(mojaGra, pozycja, Statki::TROJMASZTOWIEC);

  pozycja.x = 0; pozycja.y = 6;
  Statki::dodajStatek(mojaGra, pozycja, Statki::CZTEROMASZTOWIEC);

  Grafika::rysujPlansze(mojaGra);

  wyczyscPlansze(mojaGra);
}