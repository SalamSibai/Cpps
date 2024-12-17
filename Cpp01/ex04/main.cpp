
/*
	Psudocode:

1) 	read entire file std::ifstream -> into a string (stringstream)
2) 	search for s1: use find function to locate positions of s1 within the stringstream
3) 	loop through the string to add the contents of that string, then when we get to where the positions
	of s1 are, we add s2 and skip over the number of characters in s1.
4)	write the the modified string to filename.replace using std::ofstream
*/

#include <iostream>
#include <fstream>
#include <string>

bool	validate_files(std::ifstream &infile, std::ofstream &outfile, std::string& file_name)
{
	infile.open(file_name.c_str());
	if (!infile.is_open())
	{
		std::cout << "Couldn't open input file " << file_name << std::endl;
		return (false);
	}

	outfile.open((file_name + ".replace").c_str());
	if (outfile.fail())
	{
		std::cout << "couldn't open outfile" << std::endl;
		return (false);
	}

	return (true);
}

void	replace(std::ifstream& infile, std::ofstream& outfile, char **av)
{
	std::string cont;
	std::string str1 = av[2];
	std::string str2 = av[3];

	while (std::getline(infile, cont))
	{
		std::string result;
		size_t start = 0;
		size_t end = cont.find(str1);

		while (end != std::string::npos)
		{
			result.append(cont, start, end - start);
			result.append(str2);
			start = end + str1.length();
			end = cont.find(str1, start);
		}
		result.append(cont, start, std::string::npos);
		outfile << result << std::endl;
	}
}

int main(int ac, char **av)
{
	std::ifstream	infile;
	std::string		filename;
	std::ofstream	outfile;

	if (ac != 4)
	{
		std::cout << "Wrong number of arguments!" << std::endl;
		return (0);
	}
	filename = av[1];
	if (!validate_files(infile, outfile , filename))
		return (0);

	replace(infile, outfile, av);
	outfile.close();
	infile.close();
	return (0);
}
