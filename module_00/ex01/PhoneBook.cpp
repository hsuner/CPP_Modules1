#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->index = 0;
	this->total = 0;
}

int	PhoneBook::add()
{
	std::string info[5];

	std::cout << "First Name\t: ";
	std::getline(std::cin, info[0]);
	if (info[0].empty())
		return (-1);
	std::cout << "Last Name\t: ";
	std::getline(std::cin, info[1]);
	if (info[1].empty())
		return (-1);
	std::cout << "Nick Name\t: ";
	std::getline(std::cin, info[2]);
	if (info[2].empty())
		return (-1);
	std::cout << "Phone Number\t: ";
	std::getline(std::cin, info[3]);
	if (info[3].empty())
		return (-1);
	std::cout << "Darkest Secret\t: ";
	std::getline(std::cin, info[4]);
	if (info[4].empty())
		return (-1);
	this->Person[this->index].setType("firstName", info[0]);
	this->Person[this->index].setType("lastName", info[1]);
	this->Person[this->index].setType("nickName", info[2]);
	this->Person[this->index].setType("phoneNumber", info[3]);
	this->Person[this->index].setType("darkestSecret", info[4]);
	this->index = (this->index + 1) % 8;
	if (this->total < 8)
		this->total++;
	return (0);
}

bool isBetween0And7(const std::string& str)
{
    if (str.length() != 1)
        return (0);
    char c = str[0];
    return (c >= '0' && c <= '7');
}

int	PhoneBook::search()
{
	std::string indexInput;
	int	index;

	system("clear");
	index = 0;
	std::cout << "o------o----------o----------o----------o" << std::endl;
	std::cout << "| Index|      Name|   SurName|  UserName|" << std::endl;
	std::cout << "o------o----------o----------o----------o" << std::endl;
	while (index < this->total)
	{
		std::cout << "|     " << index << "|";
		if (this->Person[index].getType("firstName").length() > 10)
			std::cout << std::right << std::setw(10) << this->Person[index].getType("firstName").substr(0, 9) + "." << "|";
		else
			std::cout << std::right << std::setw(10) << this->Person[index].getType("firstName") << "|";
		if (this->Person[index].getType("lastName").length() > 10)
			std::cout << std::right << std::setw(10) << this->Person[index].getType("lastName").substr(0, 9) + "." << "|";
		else
			std::cout << std::right << std::setw(10) << this->Person[index].getType("lastName") << "|";
		if (this->Person[index].getType("nickName").length() > 10)
			std::cout << std::right << std::setw(10) << this->Person[index].getType("nickName").substr(0, 9) + "." << "|";
		else
			std::cout << std::right << std::setw(10) << this->Person[index].getType("nickName") << "|";
		std::cout << std::endl;
		index++;
	}
	std::cout << "o------o----------o----------o----------o" << std::endl;
	std::cout << "Please select the index to display the details: ";
	std::getline(std::cin, indexInput);
    if (!isBetween0And7(indexInput))
        return (-1);
	int num = std::stoi(indexInput);
	if (num >= 0 && num < total)
	{
		std::cout << "First Name\t: " << this->Person[num].getType("firstName") << std::endl;
		std::cout << "Last Name\t: " << this->Person[num].getType("lastName") << std::endl;
		std::cout << "Nick Name\t: " << this->Person[num].getType("nickName") << std::endl;
		std::cout << "Phone Number\t: "<< this->Person[num].getType("phoneNumber") << std::endl;
		std::cout << "Darkest Secret\t: "<< this->Person[num].getType("darkestSecret") << std::endl;
	}
	else
		return (-1);
	return (0);
}