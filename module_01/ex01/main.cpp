#include "Zombie.hpp"

int main(){
	int numZombies = 5;
	Zombie *zombie = zombieHorde(numZombies, "HordeZombie");
	for (int i = 0; i < numZombies; ++i) {
        zombie[i].announce();
    }
	delete[] zombie;

	return 0;
}