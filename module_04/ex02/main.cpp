#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const AAnimal *j = new Dog();
    const AAnimal *i = new Cat();
	//AAnimal a; *

    j->makeSound();
    i->makeSound();
    Cat c;
    Dog d;
	c.setBrainIdea(0, "I am a cat");
	c.setBrainIdea(99, "I am 100. cat");
	d.setBrainIdea(0, "I am not a cat");
	std::cout << c.getBrainIdea(0) << std::endl;
	std::cout << c.getBrainIdea(99) << std::endl;
	std::cout << d.getBrainIdea(0) << std::endl;

    delete j; // should not create a leak
    delete i;

	// Dog basic;
    // basic.setBrainIdea(0, "Idea 1");
    // basic.setBrainIdea(99, "Idea 100");

    // {
    //     Dog tmp = basic;
    //     std::cout << "Tmp's idea at 0: " << tmp.getBrainIdea(0) << std::endl;
    //     std::cout << "Tmp's idea at 99: " << tmp.getBrainIdea(99) << std::endl;
    // }

    // std::cout << "Basic's idea at 0: " << basic.getBrainIdea(0) << std::endl;
    // std::cout << "Basic's idea at 99: " << basic.getBrainIdea(99) << std::endl;

    return 0;
}