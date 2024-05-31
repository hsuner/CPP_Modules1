#include <iostream>
#include "PhoneBook.hpp"

int main()
{
    PhoneBook myPhone;
    std::string entry;

    while(1)
    {
        std::cout << "Your Command: ";
        std::getline(std::cin, entry);
        if(entry == "ADD")
        {
            if (myPhone.add() == -1)
				std::cout << "Make sure all the information is entered correctly. The person could not be saved." << std::endl;
        }
        else if(entry == "SEARCH")
        {
            if (myPhone.search() == -1)
				std::cout << "Make sure all the information is entered correctly." << std::endl;
        }
        else if(entry == "EXIT")
        {
            std::cout << "Program terminated!" << std::endl;
            break;
        }
        else
            std::cout << "Please use ADD, SEARCH or EXIT." << std::endl;
	}
    return (0);
}