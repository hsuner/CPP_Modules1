#include "Contact.hpp"

void	Contact::setType(std::string Type, std::string set)
{
	if (Type.empty() || set.empty())
		return ;
	else if (Type == "firstName")		this->firstName = set;
	else if (Type == "lastName")		this->lastName = set;
	else if (Type == "nickName")        this->nickName = set;
	else if (Type == "phoneNumber")		this->phoneNumber = set;
	else if (Type == "darkestSecret")	this->darkestSecret = set;
}

std::string	Contact::getType(std::string Type)
{
	if (Type.empty())
		return "";
	else if (Type == "firstName")		return (this->firstName);
	else if (Type == "lastName")		return (this->lastName);
	else if (Type == "nickName")	    return (this->nickName);
	else if (Type == "phoneNumber")		return (this->phoneNumber);
	else if (Type == "darkestSecret")	return (this->darkestSecret);
	return "";
}