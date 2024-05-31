#include "FragTrap.hpp"

void setPoints(FragTrap *Frag, FragTrap *Trap, FragTrap *hiFiveGuards)
{
    if(Frag->getHitPoints() < Trap->getHitPoints())
		hiFiveGuards->setHitPoints(Frag->getHitPoints());
    else
        hiFiveGuards->setHitPoints(Trap->getHitPoints());
	if(Frag->getEnergyPoints() < Trap->getEnergyPoints())
		hiFiveGuards->setEnergyPoints(Frag->getEnergyPoints());
	else
		hiFiveGuards->setEnergyPoints(Trap->getEnergyPoints());
}

int main(int a, char **av)
{
	int entry_f;
	int entry_s;
	std::string name1;
	std::string name2;

	std::cout << "Enter a nick name for the first person: ";
	std::getline(std::cin, name1);
	std::cout << "Enter a name for the second person: ";
	std::getline(std::cin, name2);
	FragTrap *Frag = new FragTrap(name1);
	FragTrap *Trap = new FragTrap(name2);
	FragTrap *hiFiveGhost = new FragTrap("hiFiveGhost");
	while (1)
	{
		std::cout << "Enter the amount of damage from "<< name1 << " to " << name2 << " (int): ";
		std::cin >> entry_f;
		if (std::cin.fail() || std::cin.peek() != '\n' || entry_f < 0){
			std::cout << "Invalid input. Exiting." << std::endl;
			break;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter the amount of damage from "<< name2 << " to " << name1 << " (int): ";
		std::cin >> entry_s;	
		if (std::cin.fail() || std::cin.peek() != '\n' || entry_s < 0){
			std::cout << "Invalid input. Exiting." << std::endl;
			break;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		Frag->setAttackDamage(entry_f);
		Trap->setAttackDamage(entry_s);
		Frag->attack(name2);
		Trap->attack(name1);
		Frag->takeDamage(entry_s);
		Trap->takeDamage(entry_f);
		Frag->beRepaired(entry_s / 2 + entry_s % 2);
		Trap->beRepaired(entry_f / 2 + entry_f % 2);
		std::cout << name1 << "'s energy: " << Frag->getEnergyPoints() << std::endl
			<< name2 << "'s energy: " << Trap->getEnergyPoints() << std::endl;
		std::cout << name1 << "'s hit points: " << Frag->getHitPoints() << std::endl
			<< name2 << "'s hit points: " << Trap->getHitPoints() << std::endl;
		setPoints(Frag, Trap, hiFiveGhost);
		if(Frag->getEnergyPoints() == 0 || Trap->getEnergyPoints() == 0) {
			std::cout << Frag->getName() << " or " << Trap->getName() << " no energy!" << std::endl;
			break;
		}
		if(Frag->getHitPoints() == 0 || Trap->getHitPoints() == 0) {
			std::cout << Frag->getName() << " or " << Trap->getName() << " is destroyed!" << std::endl;
			break;
		}
		hiFiveGhost->highFivesGuys();
	}
	hiFiveGhost->highFivesGuys();
    delete Frag;
    delete Trap;
    delete hiFiveGhost;
	return 0;
}