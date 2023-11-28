#ifndef h_robots
#define h_robots

#include <stdio.h>
#include <stdlib.h>

struct Position {
  int x;
  int y;
};
struct Robot{
  const char *name;
  Position pos;
};

Robot *robotList[5];
int robotAmount = 0;

/// Metoda sprawdzajaca dostepnosc pola dla robota
/// Zwraca true dla pustego pola i false w przeciwnym przypadku
bool isFreeSpace(int x, int y){
  for(int i = 0; i<robotAmount; i++){
    Position t = robotList[i]->pos;
    if(t.x == x && t.y == y){
      return false;
    }
  }
  return true;
}

/// Tworzy nowa instancje robota o nazwie oraz pozycji z argumentow
/// Funkcja zwraca NULL jezeli ilosc stworzonych robotow wynosi 5 lub pozycja jest juz zajeta
Robot* InitializeRobot(const char *name, Position pos){
  if(robotAmount >= 5){
    printf("InitializeRobot: No space for an additional robot.\n");
    return NULL;
  }
  if(!isFreeSpace(pos.x, pos.y)){
    printf("InitializeRobot: Two robots cannot be placed in the same position.\n");
    return NULL;
  }
  Robot* r = new Robot;
  r->pos = pos;
  r->name = name;
  robotList[robotAmount] = r;
  robotAmount++;
  return r;
}

/// Tworzy nowa instancje robota o nazwie noname oraz pozycji z argumentu
/// Funkcja zwraca NULL jezeli ilosc stworzonych robotow wynosi 5 lub pozycja jest juz zajeta
Robot* InitializeRobot(Position pos){
  return InitializeRobot("noname", pos);
}

/// Przedstawia status robota
void EchoRobot(Robot* robot){
  if(robot == NULL){
    printf("EchoRobot: No such robot.\n");
    return;
  }
  printf("Hello, I'm robot %s at x=%d, y=%d.\n", robot->name, robot->pos.x, robot->pos.y);
}

/// Przesuwa robota o n pol w osi X
void MoveX(Robot *robot, int n){
  if(!isFreeSpace(robot->pos.x + n, robot->pos.y)){
    printf("MoveX: Cannot place robots in the same position.\n");
    return;
  }
  robot->pos.x += n;
}

/// Przesuwa robota o n pol w osi Y
void MoveY(Robot *robot, int n){
  if(!isFreeSpace(robot->pos.x, robot->pos.y+n)){
    printf("MoveY: Cannot place robots in the same position.\n");
    return;
  }
  robot->pos.y += n;
}

/// Kasuje wszystkie roboty :(
void DeleteRobots(){
  for(int i = 0; i<robotAmount; i++){
    delete robotList[i];
  }
}

typedef void(*Operation)(Robot*, int);
//typedef auto Operation;


#endif
