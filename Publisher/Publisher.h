#pragma once
/////////////////////////////////////////////////////////////////////
//  NoSqlDataBaseApp.h -  Class for Publisher                      //
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
This module defines a Dependency class
* - The functions defined in this class are used for,
> Storing Dependency relationships
Public Interface:
=================
Publisher Class > ---- >    nchildrenList;  void printDependency;void closeBrace;void openBrace
Build Process:
==============
Required files
-TypeTable
-Utilities
-Publisher
Maintenance History:
====================
ver 2.0 : 6 April 2017
- first release
*/

#include<fstream>
#include<iostream>
#include<vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <iostream>
#include <ctime>
#include "../Tokenizer/Tokenizer.h"
#include "../NoSqlDataBaseApp/NoSqlDatabaseApp.h"
#include "../TypeTable/TypeTable.h"
#include "../Utilities/Utilities.h"
#include "../Publisher/Publisher.h"
using Key = std::string;
using Keys = std::vector<std::string>;
using File = std::string;
using Files = std::vector<File>;
using Pattern = std::string;
using Ext = std::string;
using FileMap = std::unordered_map<Pattern, Files>;
using Helper = Utilities::StringHelper;
using databasetable = std::unordered_map<std::string, std::vector<std::unordered_map<std::string, std::string>>>;
using File = std::string;
using Files = std::vector<File>;

/////////////////////////////////////////////////////////////////////
// Publisher class represents a all packages in an HTML Pages
// -Replace all characters and Display only functions and classes
// - it needs to store child data
//
class Publisher
{

private:
	std::unordered_map<File, std::vector<size_t>> startFile;
	std::unordered_map<File, std::vector<size_t>> endFile;
public:

	void publish(File file, ElementItem elem, std::unordered_map<std::string, std::unordered_map<size_t,size_t>> cob, std::ofstream& jssout);
	std::string Publisher::charReplace(std::string str);


	void printDependency(ElementItem elem, std::ofstream& out);
	void closeBrace(std::ofstream& out);
	void openBrace(std::ofstream& out, int i , int a, std::ofstream& jssout);

};


//Function to Publish files as HTML Files
void Publisher::publish(File file1, ElementItem elem, std::unordered_map<std::string, std::unordered_map<size_t, size_t>> cob, std::ofstream& jssout)
{std::unordered_map<size_t, size_t> localMap;
std::string file = FileSystem::Path::getName(file1);
std::string path = FileSystem::Path::getPath(file1);
std::vector<size_t> vclose;


for (auto kv : cob[file])
{
localMap[kv.first] = kv.second;
vclose.push_back(kv.second);
}


File newfile = "../PublishedFiles/" + file + ".htm";
std::ofstream out(newfile);
if (!out.is_open())
{std::cout << "failed to open file " << newfile; exit(6);
}std::string line, alLine;
std::ifstream in(file1);
size_t linecount = 1;
int i = 1,a =999;
if (!in.is_open())
	std::cout << "failed to open file ";
	else
	{char c;
		out << "<html><head><link rel=\"" << "stylesheet\"" << " type = \"text/css\"" << "  href=\""<<"Publisher.css\"/>"<<"<script type=\"text/javascript\" src = \"jssPublisher.js\"></script></head><body><pre><br><br><br>";
        printDependency(elem, out);
        out << "<br><br>";



        while (std::getline(in, alLine))
		{
		alLine = charReplace(alLine);
        for (char& line : alLine)
        {
       if ((std::find(vclose.begin(), vclose.end(), linecount) != vclose.end()) && line == '}')
        closeBrace(out);
        else if ((localMap.find(linecount) != localMap.end()) && line == '{')
       {openBrace(out, i, a,jssout);
		  i++;
		  a--;
	   }
        else 
            out << line;
        } linecount++;
         out << "<br>";
		 out << "\n";
         }
		 } out << "<//pre><//body><//html>";
		in.close();
		out.close();}

//Function to print dependencies in the HTML File
	void Publisher::printDependency(ElementItem elem, std::ofstream& out)
	{
		for (File filename : elem.childrenList)
		{
			std::string name = FileSystem::Path::getName(filename);

			std::string finalpath = name + ".htm";
			out << "<a href = \"" << finalpath << "\"" << ">" << name << " - " << "</a><br>";

		}

}

	//Function to perform functions when close brace is detected
	void Publisher::closeBrace(std::ofstream& out)
	{

		out << "}";

		out << "</div>";


	}

		//Function to perform functions when close brace is detected
 void Publisher::openBrace(std::ofstream& out, int i, int a, std::ofstream& jssout)
	{
        out << "{";
        out << "<button id =\"" << a << "\"" << "onclick=\"myFunction";
        out << i;
		out << "();";
		out << "toggleText" << i << "(this." << "id" << "); " << "\">-</button>";
        jssout << "function myFunction";
		jssout << i;
		jssout << "() {";
		jssout << "var x = document.getElementById('myDIV";
		jssout << i;
		jssout << "');";
        jssout << "if (x.style.display == 'none') {";
		jssout << "x.style.display = 'block';";
		jssout << "}";
		jssout << "else {";
		jssout << "x.style.display = 'none';";
        jssout << "}}";
		jssout << "function toggleText" << i << "(" << "buttonid" << ") {var el = document.getElementById(" << "buttonid" << ");if (el.firstChild.data == \"-\"){el.firstChild.data = \"+\";}else{el.firstChild.data = \"-\";}}";
		out << "<div id = \"myDIV";
		out << i;
		out << "\">";
}



	




 //Function to replace characters in a line
std::string Publisher::charReplace(std::string str)
{

	std::string returnString;

	for (char& c : str)
	{
		if (c == '<')
			returnString = returnString + "&lt;";
		else if (c == '>')
			returnString = returnString + "&gt;";
		else
			returnString = returnString + c;


	}

	return returnString;

}




