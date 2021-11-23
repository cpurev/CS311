// countwords.cpp
// Chuluunbat Purev
// 2021-11-23
//
// Project 8, Exercise A
// C++ STL Table implementation that counts words from txt infile.
// Requires countwords_test.txt

//Includes
#include <iostream>	//For std::cout, std::cin, std::endl
#include <fstream>	//For std::ifstream
#include <map>		//For std::map
#include <sstream>	//For std::istringstream
#include <string>	//For std::string, str::getline

//Main program
int main(){

	std::string line;
	std::map<std::string, int> m;

	//Get input from user
    while (true)
    {
        bool founderror = false;
        std::cout << "Text file name with file format (0 to quit?) ";
        std::string str;
        std::getline(std::cin, str);
        if (!std::cin)
        {
            if (std::cin.eof())      // End of file
                return 1;   // Fatal error
            std::cin.clear();
            std::cin.ignore();
            founderror = true;  // Bad input; retry
        }
        else
        {
            std::istringstream is(str);
            is >> line;
            if (!is)
                founderror = true;  // Bad read from string; retry
        }

        if (!founderror)
            break;
        std::cout << std::endl;
        std::cout << "Try again;" << std::endl;
    }

    //Open file
	std::ifstream infile (line);
	if (infile)
	{
		while ( infile >> line) 
		{
	  		++m[line];
		}

	}
	else{
		std::cout << "File reading error." << std::endl;
		infile.close();
		return 1;
	}

	if(infile.eof()){
		std::cout << "Number of distinct words: " << m.size() << std::endl << std::endl;
		for (const auto & kvpair : m){
			std::cout << kvpair.first << ": " << kvpair.second << std::endl;
		}
	}

	else{
		std::cout << "File has not been read throught fully." << std::endl;
	}

	infile.close();
	return 1;
}