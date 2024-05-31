#include "ScavTrap.hpp"

void setPoints(ScavTrap *scav, ScavTrap *trap, ScavTrap *stupidGuard)
{
    if(scav->getHitPoints() < trap->getHitPoints())
		stupidGuard->setHitPoints(scav->getHitPoints());
    else
        stupidGuard->setHitPoints(trap->getHitPoints());
	if(scav->getEnergyPoints() < trap->getEnergyPoints())
		stupidGuard->setEnergyPoints(scav->getEnergyPoints());
	else
		stupidGuard->setEnergyPoints(trap->getEnergyPoints());
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
	ScavTrap *scav = new ScavTrap(name1);
	ScavTrap *trap = new ScavTrap(name2);
	ScavTrap *stupidGuard = new ScavTrap("stupidGuard");
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
		scav->setAttackDamage(entry_f);
		trap->setAttackDamage(entry_s);
		scav->attack(name2);
		trap->attack(name1);
		scav->takeDamage(entry_s);
		trap->takeDamage(entry_f);
		scav->beRepaired(entry_s / 2 + entry_s % 2);
		trap->beRepaired(entry_f / 2 + entry_f % 2);
		std::cout << name1 << "'s energy: " << scav->getEnergyPoints() << std::endl
			<< name2 << "'s energy: " << trap->getEnergyPoints() << std::endl;
		std::cout << name1 << "'s hit points: " << scav->getHitPoints() << std::endl
			<< name2 << "'s hit points: " << trap->getHitPoints() << std::endl;
		setPoints(scav, trap, stupidGuard);
		if(scav->getEnergyPoints() == 0 || trap->getEnergyPoints() == 0) {
			std::cout << scav->getName() << " or " << trap->getName() << " no energy!" << std::endl;
			break;
		}
		if(scav->getHitPoints() == 0 || trap->getHitPoints() == 0) {
			std::cout << scav->getName() << " or " << trap->getName() << " is destroyed!" << std::endl;
			break;
		}
		stupidGuard->guardGate();
	}
	stupidGuard->guardGate();
    delete scav;
    delete trap;
    delete stupidGuard;
	return 0;
}