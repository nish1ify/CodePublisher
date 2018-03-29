#pragma once
/////////////////////////////////////////////////////////////////////
//  Display.h -  File to print all requirements                    //
//  ver 1.0                                                        //
//                                                                 //
//  Language:      Visual C++ 2008, SP1                            //
//  Platform:      Dell Inspiron, Windows 8.1			           //
//  Application:   CodeAnalyzerEx - CIS 687 Project 3              //
//  Author:        Nishanth Chandrasekaran SUID:215242434		   //
/////////////////////////////////////////////////////////////////////
/*
Module Operations:
==================
This module defines three display functions
Public Interface:
=================
TypeAnalysisDisplay
DependencyAnalysis
SCCAnalysis
Build Process:
==============
Required files
-StrongComponenent
-Dependency
-TypeTable
-Utilities
Maintenance History:
====================
ver 2.0 : 6 April 2017
- first release
*/

#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <exception>
#include <iomanip>
#include <chrono>
#include <ctime>
#include "../Analyzer/Executive.h"
#include "../Parser/Parser.h"
#include "../FileSystem/FileSystem.h"
#include "../FileMgr/FileMgr.h"
#include "../Parser/ActionsAndRules.h"
#include "../Parser/ConfigureParser.h"
#include "../AbstractSyntaxTree/AbstrSynTree.h"
#include "../Logger/Logger.h"
#include "../Utilities/Utilities.h"
#include "../TypeTable/TypeTable.h"
#include "../Dependency/Dependency.h"
#include "../StrongComponent/StrongComponent.h"
#include "../StrongComponent/StrongComponent.h"
#include "../Persistance/Persistance.h"

using Key = std::string;
using Keys = std::vector<Key>;
using Rslt = Logging::StaticLogger<0>;  
using Demo = Logging::StaticLogger<1>;  
using Dbug = Logging::StaticLogger<2>; 
using Path = std::string;
using File = std::string;
using Files = std::vector<File>;
using Pattern = std::string;
using Ext = std::string;
using FileMap = std::unordered_map<Pattern, Files>;

using namespace CodeAnalysis;

//Function to print TypeTable
void TypeAnalysisDisplay(NoSqlDb db)
{
    TypeAnalysis ta;
	ta.doTypeAnalysis(db);
    Keys keys = db.keys();
	for (std::string key : keys)
	{
	for (Element elem : db.value(key))
		{
			std::cout << "\n  " << key << ":   ";
			std::cout << elem.show();
	}
	}


}
//Function to print Dependency Table
void DependencyAnalysis(Dependency dbnew)
{
	Keys k = dbnew.keys();
	for (std::string key : k)
	{


		for (auto elem : dbnew.value(key))
		{
			std::cout << "\n  " << key << ":   ";
			std::cout << elem.showelement();
		}

	}
}


//Function to print SCC
void SCCAnalysis(std::vector<vector<int>> revfileMap, std::unordered_map<int, File> rev)
{
for (std::vector<int> r : revfileMap)
	{
		for (int a : r)
		{
			cout << " " << rev[a];

		}
		cout << "\n";
	}
}


