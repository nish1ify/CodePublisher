/////////////////////////////////////////////////////////////////////
//																   //
//                     Test Executive File                         //
//                                                                 //
//  ver 1.0                                                        //
//                                                                 //
//  Language:      Visual C++ 2008, SP1                            //
//  Platform:      Dell Inspiron, Windows 8.1			           //
//  Application:   NoSql Database - CIS 687 Project 2              //
//  Author:        Nishanth Chandrasekaran SUID:215242434		   //
/////////////////////////////////////////////////////////////////////


#include "../Parser/Parser.h"
#include "../FileSystem/FileSystem.h"
#include "../FileMgr/FileMgr.h"
#include "../Parser/ActionsAndRules.h"
#include "../Parser/ConfigureParser.h"
#include "../AbstractSyntaxTree/AbstrSynTree.h"
#include "../Logger/Logger.h"
#include "../Utilities/Utilities.h"
#include "../Analyzer/DepAnal.h"
#include "../TypeTable/TypeTable.h"
#include "../Dependency/Dependency.h"
#include "../StrongComponent/StrongComponent.h"
#include "../StrongComponent/StrongComponent.h"
#include "../Persistance/Persistance.h"
#include "../Display/Display.h"
#include "SourceFiles.h"
#include "../Analyzer/Executive.h"
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
#include <fstream>
#include <sstream>
#include <iostream>


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

void Requirementone();
void Requirementtwo();
void Requirementthree();
void Requirementfour();
void Requirementfive();
void Requirementsix();
void Requirementseven();
void Requirementeight();
void Requirementnine();
void Requirementten();


//Requirement one
void Requirementone()
{

	std::cout << "\n *****************************Demonstrating Requirement 1**************************\n";
	std::cout << "\n Using Visual Studio 2015 and its C++ Windows Console Projects, as provided in the ECS computer labs\n";
	Requirementtwo();
}

//Requirement two

void Requirementtwo()
{
	std::cout << "\n *************************************Demonstrating Requirement 2**************************\n";
	std::cout << "\n Using the C++ standard library's streams for all I/O and new and delete for all heap-based memory management\n";
	Requirementthree();

}

//Requirement three

void Requirementthree()
{
	std::cout << "\n *************************************Demonstrating Requirement 3**************************\n";
	std::cout << "\n  Provide a Publisher program that provides for creation of web pages each of which captures the content of a single C++ source code file, e.g., *.h or *.cpp.\n";
	Requirementfour();

}
//Requirement four
void Requirementfour()
{
	std::cout << "\n *************************************Demonstrating Requirement 4**************************\n";
	std::cout << "\n  Facility to expand or collapse class bodies, methods, and global functions using JavaScript and CSS properties.\n";
	Requirementfive();
}

////Requirement five

void Requirementfive()
{
	std::cout << "\n *********************************Demonstrating Requirement 5**************************\n";
	std::cout << "\n  Provides a CSS style sheet that the Publisher uses to style its generated pages and (if you are implementing the previous optional requirement) a JavaScript file that provides functionality to hide and unhide sections of code for outlining, using mouse clicks.\n";
	Requirementsix();
}

//Requirement six

void Requirementsix()
{

	std::cout << "\n *********************************Demonstrating Requirement 6**************************\n";
	std::cout << "\n Embembed in each web page's <head> section links to the style sheet and JavaScript file.\n";
	Requirementseven();

}

//Requirement seven

void Requirementseven()
{
	std::cout << "\n *********************************Demonstrating Requirement 7**************************\n";
	std::cout << "\n  Emembedd HTML5 links to dependent files with a label, at the top of the web page. Publisher shall use functionality from your Project #2 to discover package dependencies within the published set of source files. \n";
	Requirementeight();
	
}

//Requirement eight

void Requirementeight()
{
	std::cout << "\n *********************************Demonstrating Requirement 8**************************\n";
	std::cout << "\n Develops command line processing to define the files to publish by specifying path and file patterns.\n";
	Requirementnine();


}

////Requirement Nine

void Requirementnine()
{

	std::cout << "\n *********************************Demonstrating Requirement 9**************************\n";
	std::cout << "\n Demonstrates the CodePublisher functionality by publishing all the important packages in your Project #3\n";
	Requirementten();
}

void Requirementten()
{

	std::cout << "\n *********************************Demonstrating Requirement 9**************************\n";
	std::cout << "\n Includes an automated unit test suite that demonstrates you meet all the requirements of this project\n";

	std::cout << "\n\n\n  The Type Table Analysis for the given command line arguments is\n\n";


	
}


//Function to print the index page
void printDep(std::ofstream& outer, Keys keys)
{
	outer << "<html><head><title>HTML Reference</title></head><body><pre><br><br>The Dependency Files are<br><br><br><br>";

	for (File filename : keys)
	{
		std::string name = FileSystem::Path::getName(filename);
		std::string finalpath = name + ".htm";
        outer << "<a href = \"";
		outer << finalpath;
		outer << "\"";
		outer << ">";
		outer << name;
		//outer << " - ";
		//outer << finalpath;
		outer << "</a>";
		outer << "<br>";
		outer << "<br>";
		outer << "<br>";
		outer << "<br>";
		
	}
	outer << "<br>";
	outer << "<br>";
	outer << "</pre";
	outer << "</body>";
	outer << "</html>";

	outer.close();
   std::string path = "file:///" + FileSystem::Path::getFullFileSpec("../PublishedFiles/index.htm");
	std::wstring spath = std::wstring(path.begin(), path.end());
	LPCWSTR swpath = spath.c_str();
	LPCWSTR a = L"open";
	LPCWSTR ie = L"iexplore.exe";
	ShellExecute(NULL, a, ie, swpath, NULL, SW_SHOWDEFAULT);
}


//Main function
int main(int argc, char* argv[])
{CodeAnalysisExecutive exec;
try {
bool succeeded = exec.ProcessCommandLine(argc, argv);
if (!succeeded)
{return 1;
}exec.getSourceFiles();
exec.processSourceCode(true);
std::ostringstream out;
FileMap fileMapTemp = exec.getFileMap();
Files allFiles;
using Pair = std::pair<Pattern, Files>;
for (Pair pair : fileMapTemp)
{for (File f : pair.second)
allFiles.push_back(f);
}
Requirementone();
TypeAnalysis ta;
NoSqlDb dbtype;
std::unordered_map<std::string, std::unordered_map<size_t, size_t>> cob = ta.doTypeAnalysis(dbtype);
TypeAnalysisDisplay(dbtype);
Dependency dbnew;
control c;
c.doActivity(dbtype, dbnew, allFiles, cob);
DependencyAnalysis(dbnew);
Publisher p;
File jss = "../PublishedFiles/jssPublisher.js";
File css = "../PublishedFiles/Publisher.css";
File index = "../PublishedFiles/index.htm";
std::ofstream jssout(jss);
if (!jssout.is_open())
{std::cout << "failed to open file ";
}std::ofstream cssout(css);
cssout << "body {background-color: #00ff00;}";
Keys kiya = dbnew.keys();
std::cout << "\n\n The Published Files are Published in the folder \"PublishedFiles\" \n\n";
for (Key f : kiya)
{for (ElementItem e : dbnew.value(f))
{p.publish(f, e, cob,jssout);
}}
std::ofstream outer(index);
printDep(outer, kiya);
}catch (std::exception& except)
{exec.flushLogger();
std::cout << "\n\n  caught exception in Executive::main: " + std::string(except.what()) + "\n\n";
exec.stopLogger();
return 1;
}return 0;
}



