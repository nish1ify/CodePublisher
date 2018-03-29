

#include "NoSqlDataBase.h"
#include <iostream>

using StrData = std::string;
using intData = int;
//using Key = NoSqlDb::Key;
//using Keys = NoSqlDb::Keys;


using namespace CodeAnalysis;

//using Key = NoSqlDb::Key;
//using Keys = NoSqlDb::Keys;

int main()
{
	std::cout << "\n  Demonstrating NoSql Helper Code";
	std::cout << "\n =================================\n";

	std::cout << "\n  Creating and saving NoSqlDb elements with string data";
	std::cout << "\n -------------------------------------------------------\n";


	/*

	//Element Decleration
	NoSqlDb db;

	Element elem1;
	elem1.name = "elem1";                    
	elem1.category = "test";
	elem1.description = "elem1-desc";
	elem1.childrenList = { "elem2" , "elem3" };
	elem1.data = "elem1's StrData";

	db.save(elem1.name, elem1);

	Element elem2;
	elem2.name = "elem2";
	elem2.category = "test";
	elem2.data = "elem2's StrData";
	elem2.description = "elem2-desc";
	elem2.childrenList = { "elem1" ,"elem4" };

	db.save(elem2.name, elem2);

	Element elem3;
	elem3.name = "elem3";
	elem3.category = "test";
	elem3.data = "elem3's StrData";
	elem3.description = "elem3-desc";
	elem3.childrenList = { "elem1" , "elem2" };

	db.save(elem3.name, elem3);

	Element elem4;
	elem4.name = "elem4";
	elem4.category = "test";
	elem3.data = "elem3's StrData";
	elem4.description = "elem3-desc";
	elem4.childrenList = { "elem1" , "elem2" };

	db.save(elem4.name, elem4);

	


	std::cout << "\n  Retrieving elements from NoSqlDb<string>";
	std::cout << "\n ------------------------------------------\n";

	std::cout << "\n  size of db = " << db.count() << "\n";
	Keys keys = db.keys();
	for (Key key : keys)
	{
		std::cout << "\n  " << key << ":";
		std::cout << db.value(key).show();
	}
	std::cout << "\n\n";

	//Updating and Deleting Values in the Databse
	std::cout << "Delteting operation performed \n\n\n\n";


	db.updateElement(elem2.name, "Name", "Nishu");
	db.updateElementChild(elem1.name, "children",{ "elem1" , "elem2", "elem3" });
	db.updateElementData(elem3.name, "Data", "Nishu---data");

	db.deleteElement(elem4.name);

	//Displaying all Elements after updating
	std::cout << "\n  size of db = " << db.count() << "\n";

	std::cout << "\n";

	keys = db.keys();

	for (Key key : keys)
	{
		std::cout << "\n  " << key << ":";
		std::cout << db.value(key).show();
	}
	std::cout << "\n\n";



	//Creating int DataBase


	std::cout << "\n  Creating and saving NoSqlDb elements with int data";
	std::cout << "\n ----------------------------------------------------\n";

	NoSqlDb<intData> idb;

	Element<intData> ielem1;
	ielem1.name = "elem1";
	ielem1.category = "test";
	ielem1.data = 1;

	idb.save(ielem1.name, ielem1);

	idb.updateElementData(ielem1.name, "Data", 3);

	

	Keys keyss = idb.keys();
	for (Key key : keyss)
	{
		std::cout << "\n  " << key << ":";
		std::cout << idb.value(key).show();
	}
	std::cout << "\n\n";

	
	*/

}