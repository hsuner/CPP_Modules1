#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact Person[8];
		int		index;
		int		total;
	public:
		PhoneBook();
		int	add();
		int	search();
};

#endif