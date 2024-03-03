#include <iostream>
#include "../include/particle.h"


/// Funkcja wpisuje dane do podanego obiektu typu Particle
/// (pierwszy argument przekazany przez referencje). 
void SetParticle(Particle &particle, const char* name, double mass){
	particle.name = name;
	particle.mass = mass;
}
