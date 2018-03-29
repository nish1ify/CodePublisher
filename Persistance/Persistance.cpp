//Implementation file for Persistance

#ifdef PERSISTANCE_STUB


#include "../Persistance/Persistance.h"

int main()
{
	
	

	std::cout << "\n  Demonstrating Test Exeecutive";
	std::cout << "\n =================================\n";

	std::cout << "\n  Creating and saving NoSqlDb elements with string data";
	std::cout << "\n -------------------------------------------------------\n";

	Dependency db;
	std::vector<std::vector<int>> dbr;
	std::unordered_map<int, File> rev;

	toXml(db);
	toXmlscc(dbr,rev);

}

#endif