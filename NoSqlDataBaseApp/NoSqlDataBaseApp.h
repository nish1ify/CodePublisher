#pragma once
/////////////////////////////////////////////////////////////////////
//  NoSqlDataBaseApp.h -  Class for Dependency Table               //
//  ver 1.0                                                        //
//                                                                 //
//  Language:      Visual C++ 2008, SP1                            //
//  Platform:      Dell Inspiron, Windows 8.1			           //
//  Application:   CodeAnalyzerEx - CIS 687 Project 3             //
//  Author:        Nishanth Chandrasekaran SUID:215242434		   //
/////////////////////////////////////////////////////////////////////
/*
Module Operations:
==================
This module defines a Dependency class 
* - The functions defined in this class are used for,
> Storing Dependency relationships
Public Interface:
=================
Element Class > ---- >        nchildrenList;
Dependency Class
Build Process:
==============
Required files
-CppProperties
-Tokenizer
-TypeTable
Maintenance History:
====================
ver 1.0 : 4 Apl 2017
- first release
*/
#include <sstream>
#include <vector>
#include <iomanip>
#include <iostream>
#include <ctime>
#include "../CppProperties/CppProperties.h"
#include "../Tokenizer/Tokenizer.h"
#include "../TypeTable/TypeTable.h"
#include "../Utilities/Utilities.h"

using Key = std::string;
using Keys = std::vector<Key>;
using File = std::string;
using Files = std::vector<File>;
using Pattern = std::string;
using Ext = std::string;
using FileMap = std::unordered_map<Pattern, Files>;


using Helper = Utilities::StringHelper;
using namespace Utilities;

/////////////////////////////////////////////////////////////////////
// Element class represents a data record in our NoSql database
// - in our NoSql database that is just the value in a key/value pair
// - it needs to store child data
//
class ElementItem
{
public:
	using Name = std::string;

	std::vector<std::string> childrenList;

	std::string showelement();

};

//Function to print all the files
std::string ElementItem::showelement()
{
	std::ostringstream out;
	out.setf(std::ios::adjustfield, std::ios::left);

	out << "\n    " << std::setw(8) << "Children are   " << " : ";
	std::vector<std::string> c = childrenList;
	for (Key k : c)
	{
		out << "  ";
		out << k;

	}
	out << "\n";
	return out.str();
}


/////////////////////////////////////////////////////////////////////
// NoSqlDb class is a key/value pair in-memory database
// - stores and retrieves elements
//

class Dependency
{
public:
	using Key = std::string;
	using Keys = std::vector<Key>;
	Keys keys();
	bool save(Key key, ElementItem elem);
	std::vector<ElementItem> value(Key key);
	size_t count();


	void Dependency::showKeys(Keys list);
private:
	using Item = std::pair<Key,std::vector<ElementItem>>;
	std::unordered_map<Key,std::vector<ElementItem>> store;
};

//Returns the keys of the DataBase

typename Dependency::Keys Dependency::keys()
{
	Keys keys;
	for (Item item : store)
	{
		keys.push_back(item.first);
	}
	return keys;
}


//Saves new ElementItem to the Database

bool Dependency::save(Key key, ElementItem elem)
{
	std::vector<ElementItem> vec;
	vec.push_back(elem);


	if (store.find(key) != store.end())
		return false;
	store[key] = vec;
	return true;
}



//Returns the ElementItem of a certain key in the Database

std::vector<ElementItem> Dependency::value(Key key)
{
	ElementItem elem;
	std::vector<ElementItem> vec;
	if (store.find(key) == store.end())
	{
				return vec;

	}
		return store[key];

}

//Returns count of the DataBase

size_t Dependency::count()
{
	return store.size();
}

//Displays all keys in the Database

void Dependency::showKeys(Keys list)
{
	for (Key k : list)
	{
		std::cout << "\t" << k << "\n";
	}
	return;
}




