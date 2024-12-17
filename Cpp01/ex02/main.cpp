
#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "ADDRESSES:" << std::endl;
	std::cout << "The address of str is			" << &str << std::endl;
	std::cout << "The memory str_prt is pointing to is	" << stringPTR << std::endl;
	std::cout << "The stringREF memory address is		" << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "VALUES:" << std::endl;
	std::cout << "str is 					" << str << std::endl;
	std::cout << "The value stringPTR points to is 	" << *stringPTR << std::endl;
	std::cout << "The value inside stringREF 		" << stringREF << std::endl;

	return (0);
}