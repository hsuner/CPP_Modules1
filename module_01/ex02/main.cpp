#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Address of the string: " << &str << std::endl;
	std::cout << "Address of the string using stringPTR: " << stringPTR << std::endl;
	std::cout << "Address of the string using stringREF: " << &stringREF << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;
	std::cout << "String: " << str << std::endl;
	std::cout << "String using stringPTR: " << *stringPTR << std::endl;
	std::cout << "String using stringREF: " << stringREF << std::endl;

	return 0;
}