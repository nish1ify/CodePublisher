#pragma once
/////////////////////////////////////////////////////////////////////
//  Dependency.h -  Class analysing dependencies between Fil       //
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
This module defines a control class class
* - The functions defined in this class are used for,
> Finding out dependencies by matching typetabl keys
ublic Interface:
=================
doActivity
Build Process:
==============
Required files
-CppProperties
-Tokenizer
-TypeTable
-Utilities
-NoSQLDataBaseApp
Maintenance History:
====================
ver 2.0 : 4 Apl 2017
- first release
*/

#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <iostream>
#include <ctime>
#include "../CppProperties/CppProperties.h"
#include "../Tokenizer/Tokenizer.h"
#include "../TypeTable/TypeTable.h"
#include "../Utilities/Utilities.h"
#include "../NoSqlDataBaseApp/NoSqlDataBaseApp.h"
#include "../Publisher/Publisher.h"

using Key = std::string;
using Keys = std::vector<Key>;
using File = std::string;
using Files = std::vector<File>;
using Pattern = std::string;
using Ext = std::string;
using FileMap = std::unordered_map<Pattern, Files>;

/////////////////////////////////////////////////////////////////////
// Control class represents control flow to obtain Dependency

namespace CodeAnalysis
	{
        class control
		{

		public:
			int doActivity(NoSqlDb& db, Dependency& dbnew, Files allfiles, std::unordered_map<std::string, std::unordered_map<size_t, size_t>> cob);

		};


//Function to Obtain and store Dependencies Between Files
int control::doActivity(NoSqlDb& db, Dependency& dbnew, Files allfiles, std::unordered_map<std::string, std::unordered_map<size_t, size_t>> cob)
{
std::cout << "\n\n The Dependency Analysis for the given command line arguments is\n\n";
   Keys keys = db.keys();
std:: vector<ElementItem> veci;
for (File f : allfiles)
{ElementItem elemitem;
try
{std::string file = FileSystem::Path::getName(f);
std::ifstream in(f);
if (!in.good())
{
std::cout << "\n  can't open " << file << "\n\n";
return 1;
}
Scanner::Toker toker;
toker.returnComments(false);
toker.attach(&in);
do
{
std::string tok = toker.getTok();
for (std::string key : keys)
{if (key == tok)
{for (Element vec : db.value(key))
{elemitem.childrenList.push_back(vec.filename);
std::sort(elemitem.childrenList.begin(), elemitem.childrenList.end());
elemitem.childrenList.erase(std::unique(elemitem.childrenList.begin(), elemitem.childrenList.end()), elemitem.childrenList.end());
}}}} while (in.good());
dbnew.save(f, elemitem);
}
catch (std::logic_error& ex){
std::cout << "\n  " << ex.what();
}}
return 0;
}
}
	





