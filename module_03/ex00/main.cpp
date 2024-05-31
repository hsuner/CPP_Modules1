#include "ClapTrap.hpp"

int main(int a, char **av)
{
	int entry_f;
	int entry_s;
	std::string name1;
	std::string name2;

	std::cout << "Enter a name for the first person: ";
	std::getline(std::cin, name1);
	std::cout << "Enter a name for the second person: ";
	std::getline(std::cin, name2);
	ClapTrap *clap = new ClapTrap(name1);
	ClapTrap *trap = new ClapTrap(name2);
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
		clap->setAttackDamage(entry_f);
		trap->setAttackDamage(entry_s);
		clap->attack(name2);
		trap->attack(name1);
		clap->takeDamage(entry_s);
		trap->takeDamage(entry_f);
		clap->beRepaired(entry_s / 2 + entry_s % 2);
		trap->beRepaired(entry_f / 2 + entry_f % 2);
		std::cout << name1 << "'s energy: " << clap->getEnergyPoints() << std::endl
			<< name2 << "'s energy: " << trap->getEnergyPoints() << std::endl;
		std::cout << name1 << "'s hit points: " << clap->getHitPoints() << std::endl
			<< name2 << "'s hit points: " << trap->getHitPoints() << std::endl;
		if(clap->getEnergyPoints() == 0 || trap->getEnergyPoints() == 0) {
			std::cout << clap->getName() << " or " << trap->getName() << " no energy!" << std::endl;
			break;
		}
		if(clap->getHitPoints() == 0 || trap->getHitPoints() == 0) {
			std::cout << clap->getName() << " or " << trap->getName() << " is destroyed!" << std::endl;
			break;
		}
	}
	delete clap;
	delete trap;
	return 0;
}