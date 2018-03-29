#pragma once
/////////////////////////////////////////////////////////////////////
//  TypeTable.h -  Class analysing types                           //
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
This module defines a TypeAnalysis class c
* - The functions defined in this class are used for,
> Type Analysis and buidling a typetable
Public Interface:
=================
doActivity
Build Process:
==============
Required files
-CppProperties
-Tokenizer
-Parser
Maintenance History:
====================
ver 2.0 : 6 April 2017
- first release
*/
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <iostream>
#include "../CppProperties/CppProperties.h"
#include "../Logger/Logger.h"
#include "../Parser/ActionsAndRules.h"
#include <iostream>
#include <functional>
#include<stack>


#pragma warning (disable : 4101)  // disable warning re unused variable x, below


/////////////////////////////////////////////////////////////////////
// Element class represents a data record in our NoSql database
// - in our NoSql database that is just the value in a key/value pair
// - it needs to store filename,typename,using namespace
//
namespace CodeAnalysis
{
	class Element
	{
	public:
		using Type = std::string;
		using Namespace = std::string;
		using Filename = std::string;

		Property<Type> tname;            // metadata
		Property<Namespace> nspace;    // metadata
		Property<Filename> filename;    // metadata

		std::string show();
	};


	std::string Element::show()
	{
		// show children when you've implemented them

		std::ostringstream out;
		out.setf(std::ios::adjustfield, std::ios::left);
		out << "\n";
		out << "    " << std::setw(10) << "TypeName";
		out << "    " << std::setw(20) << "Using NameSpace";
		out << "    " << std::setw(25) << "FileName";

		out << "\n";

		out << "    " << std::setw(10) << "-------";
		out << "    " << std::setw(20) << "-------";
		out << "    " << std::setw(25) << "-------";

		out << "\n";


		out << "    " << std::setw(10) << tname;
		out << "    " << std::setw(20) << nspace;
		out << "    " << std::setw(25) << filename;
		out << "\n";
		return out.str();
	}
	class NoSqlDb
	{
	public:
		using Key = std::string;
		using Keys = std::vector<Key>;
		Keys keys();
		bool save(Key key, Element elem);
		std::vector<Element> NoSqlDb::value(Key key);
		size_t count();
		void NoSqlDb::showKeys(Keys list);
	private:
		using Item = std::pair<Key, std::vector<Element>>;
		std::unordered_map<Key, std::vector<Element>> store;
	};

	//Returns the keys of the DataBase

	typename NoSqlDb::Keys NoSqlDb::keys()
	{
		Keys keys;
		for (Item item : store)
		{
			keys.push_back(item.first);
		}
		return keys;
	}


	//Saves new element to the Database

	bool NoSqlDb::save(Key key, Element elem)
	{
		std::vector<Element> vec;
		vec.push_back(elem);


		if (store.find(key) != store.end())
			return false;
		store[key] = vec;
		return true;
	}




	//Returns the Element of a certain key in the Database

	std::vector<Element> NoSqlDb::value(Key key)
	{
		std::vector<Element> vec;
		if (store.find(key) == store.end())
		{
			return vec;
		}


		return store[key];

	}

	//Returns count of the DataBase

	size_t NoSqlDb::count()
	{
		return store.size();
	}



	//Displays all keys in the Database

	void NoSqlDb::showKeys(Keys list)
	{
		for (Key k : list)
		{
			std::cout << "\t" << k << "\n";
		}
		return;
	}


	



	/////////////////////////////////////////////////////////////////////
	// TypeAnalysis class is a key/value pair in-memory database
	// - stores and retrieves elements from the AST Node
	//

	class TypeAnalysis
	{
	public:
		using SPtr = std::shared_ptr<ASTNode*>;
		std::stack<std::string> stack;

		std::unordered_map<std::string, std::unordered_map<size_t, size_t>> cob;

		TypeAnalysis();
		std::unordered_map<std::string, std::unordered_map<size_t, size_t>> doTypeAnalysis(NoSqlDb& db);
	private:
		void DFSearch(ASTNode* pNode, NoSqlDb& db);
		AbstrSynTree& ASTref_;
		ScopeStack<ASTNode*> scopeStack_;
		Scanner::Toker& toker_;

	};

	//Gets the instances of the ASTNode , ScopeStack,Toker
	inline TypeAnalysis::TypeAnalysis() :
		ASTref_(Repository::getInstance()->AST()),
		scopeStack_(Repository::getInstance()->scopeStack()),
		toker_(*(Repository::getInstance()->Toker()))
	{
		std::function<void()> test = [] { int x; };
	}

	inline bool doDisp(ASTNode* pNode)
	{
		static std::string toDisplay[] = {
			   "lambda", "class", "struct", "enum", "alias", "typedef", };
		
		static std::string toDisplayHtml[] = {
		     "class", "function" };


		for (std::string type : toDisplay)
		{
			if (pNode->type_ == type)
				return true;
		}
		return false;
	}
	inline void TypeAnalysis::DFSearch(ASTNode* pNode, NoSqlDb& db)
	{std::unordered_map<size_t,size_t> htmlBIGvec;
     size_t startLine = 0;
	 size_t endLine = 0;
     std::vector<std::string> vec;
	 Element elem1;
	 static std::string path = "";
	if (pNode->path_ != path)
		{
		path = pNode->path_;
		}
	if (pNode->type_ == "namespace")
		{stack.push(pNode->name_);
		}
    if (pNode->type_ == "class" || pNode->type_ == "function" && (pNode->startLineCount_ != pNode->endLineCount_) && ((pNode->startLineCount_ +1)!= pNode->endLineCount_) )
		{startLine = pNode->startLineCount_;
		endLine = pNode->endLineCount_;
	    htmlBIGvec = cob[pNode->package_];
		htmlBIGvec[startLine] = endLine;
       cob[pNode->package_] = htmlBIGvec;
		}
        if (doDisp(pNode))
		{elem1.tname = pNode->type_;
		elem1.filename = pNode->package_;
		if (stack.size() == 0)
		{elem1.nspace = "Mama";
         }
		else
		{elem1.nspace = stack.top();
        }
		db.save(pNode->name_, elem1);
		}
		if (pNode->type_ == "namespace"  && pNode->name_ == "Global Namespace")
		{for (auto pchild : pNode->children_)
			{if (pchild->type_ == "function" && pchild->name_ != "main")
				{elem1.tname = pchild->type_;
					elem1.filename = pchild->package_;
					elem1.nspace = pNode->name_;
					db.save(pchild->name_, elem1);
				}}}
		for (auto pChild : pNode->children_)
		{if (pChild->parentType_ == "namespace")
			{stack.push(pNode->name_);
			}
			DFSearch(pChild, db);
			if (pChild->parentType_ == "namespace")
			{stack.pop();
			}
		}}

	

	//Function performs TypeAnalysis
	inline std::unordered_map<std::string, std::unordered_map<size_t, size_t>> TypeAnalysis::doTypeAnalysis(NoSqlDb& db)
	{
		
		ASTNode* pRoot = ASTref_.root();
		DFSearch(pRoot,db);

		return cob;

	}
}




