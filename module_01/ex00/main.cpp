#include "Zombie.hpp"

int main() {
	Zombie b("Stack");
	b.announce();
	Zombie *a = newZombie("Heap");
	a->announce();
	delete a;
	return 0;
}