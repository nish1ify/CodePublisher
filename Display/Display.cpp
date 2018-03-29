//Implementation file for Display.cpp

#ifdef DISPLAY_STUB

#include "Display.h"

namespace CodeAnalysis
{
	int main()
	{
		control c;
		Dependency dbnew;
		NoSqlDb db;
		std::vector<std::string> allfiles;
		std::vector<vector<int>> revfileMap;
		std::unordered_map<int, File> rev;


		TypeAnalysisDisplay(db);
		DependencyAnalysis(dbnew);
		SCCAnalysis(revfileMap,rev);

		return 0;

	}
}
#endif