
#pragma once
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <iostream>
#include <ctime>
#include "../CppProperties/CppProperties.h"
#include "../Parser/ActionsAndRules.h"
#include "../Parser/ActionsAndRules.h"
#include <iostream>
#include <functional>


#pragma warning (disable : 4101)  // disable warning re unused variable x, below

/*

namespace CodeAnalysis
{
	
	class TypeAnalysis
	{
	public:
		using SPtr = std::shared_ptr<ASTNode*>;

		TypeAnalysis();
		void doTypeAnalysisysis();
	private:
		void DFS(ASTNode* pNode);
		AbstrSynTree& ASTref_;
		ScopeStack<ASTNode*> scopeStack_;
		Scanner::Toker& toker_;
	};

	inline TypeAnalysis::TypeAnalysis() :
		ASTref_(Repository::getInstance()->AST()),
		scopeStack_(Repository::getInstance()->scopeStack()),
		toker_(*(Repository::getInstance()->Toker()))
	{
		std::function<void()> test = [] { int x; };  // This is here to test detection of lambdas.
	}                                              // It doesn't do anything useful for dep anal.

	inline bool doDisplay(ASTNode* pNode)
	{
		static std::string toDisplay[] = {
			"function", "lambda", "class", "struct", "enum", "alias", "typedef"
		};
		for (std::string type : toDisplay)
		{
			if (pNode->type_ == type)
				return true;
		}
		return false;
	}
	inline void TypeAnalysis::DFS(ASTNode* pNode)
	{
		static std::string path = "";
		if (pNode->path_ != path)
		{
			std::cout << "\n    -- " << pNode->path_ << "\\" << pNode->package_;
			path = pNode->path_;
		}
		if (doDisplay(pNode))
		{
			std::cout << "\n  " << pNode->name_;
			std::cout << ", " << pNode->type_;
		}
		for (auto pChild : pNode->children_)
			DFS(pChild);
	}

	inline void TypeAnalysis::doTypeAnalysisysis()
	{
		std::cout << "\n  starting type analysis:\n";
		std::cout << "\n  scanning AST and displaying important things:";
		std::cout << "\n -----------------------------------------------";
		ASTNode* pRoot = ASTref_.root();
		DFS(pRoot);
		std::cout << "\n\n  the rest is for you to complete\n";
	}




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
		out << "\n    " << std::setw(8) << "name" << " : " << tname;
		out << "\n    " << std::setw(8) << "category" << " : " << nspace;
		out << "\n    " << std::setw(8) << "Description" << " : " << filename;

		/*
		std::vector<std::string> c = childrenList;
		for (Key k : c)
		{

			out << "\t" << k;

		}


		
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
		Element value(Key key);
		size_t count();


		Element NoSqlDb::makeCopyElement(Key key);
		void NoSqlDb::showKeys(Keys list);
	private:
		using Item = std::pair<Key, Element>;
		std::unordered_map<Key, Element> store;
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


		if (store.find(key) != store.end())
			return false;
		store[key] = elem;
		return true;
	}




	//Returns the Element of a certain key in the Database

	Element NoSqlDb::value(Key key)
	{
		if (store.find(key) != store.end())
			return store[key];
		return Element();
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

*/




