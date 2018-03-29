/////////////////////////////////////////////////////////////////////
//  Persistance.h -  Functions supporting XMl Parsing              //
//  ver 1.0                                                        //
//                                                                 //
//  Language:      Visual C++ 2008, SP1                            //
//  Platform:      Dell Inspiron, Windows 8.1			           //
//  Application:   NoSql Database - CIS 687 Project 3             //
//  Author:        Nishanth Chandrasekaran SUID:215242434		   //
/////////////////////////////////////////////////////////////////////
/*
Module Operations:
==================
This module defines a Persistance class
* - The functions defined in this class are used for,
> Returning the DataBase object after populating it from the XML Document
Public Interface:
=================
toXml
fromXml
Build Process:
==============
Required files
-CppProperties
- convert.h
-NoSQLDataBase
Maintenance History:
====================
ver 2.0 : 6 April 2017
- first release
*/

#pragma once
#include "../XmlDocument/XmlDocument/XmlDocument.h"
#include "../XmlDocument/XmlElement/XmlElement.h"
#include "../CppProperties/CppProperties.h"
#include "../Convert/Convert.h"
#include "../StrHelper.h"
#include "../NoSQLDataBase/NoSQLDataBase.h"
#include "../Dependency/Dependency.h"
#include<fstream>




using Key = std::string;
using Keys = std::vector<std::string>;

using namespace XmlProcessing;
using SPtr = std::shared_ptr<AbstractXmlElement>;
using Path = std::string;
using File = std::string;
using Files = std::vector<File>;
using Pattern = std::string;
using Ext = std::string;
using FileMap = std::unordered_map<Pattern, Files>;




//Returns a xml string and used to persist values in the XML Document for dependency
std::string toXml(Dependency db)
{
    std::string xml;
	XmlDocument doc;
    Keys allkeys = db.keys();
    SPtr pRoot = makeTaggedElement("DBX");
	doc.docElement() = pRoot;
    for (Key keyss : allkeys)
	{
       SPtr pNameElem = makeTaggedElement("Record");
	   pRoot->addChild(pNameElem);
       SPtr elekey = makeTaggedElement("Key");
	   pNameElem->addChild(elekey);
	   SPtr tenamekey = makeTextElement(keyss);
	   elekey->addChild(tenamekey);
	  SPtr ele15 = makeTaggedElement("Children-Keys");
	  pNameElem->addChild(ele15);
      for (ElementItem k : db.value(keyss))
	 {
		  for (std::string s : k.childrenList)
		  {
			  SPtr techild = makeTaggedElement("Child");
			  ele15->addChild(techild);
			  SPtr childvalue = makeTextElement(s);
			  techild->addChild(childvalue);

		  }
		
     }

	 }
	xml = doc.toString();
	try
	{
	std::ofstream sample("../nishu.xml");
	sample << xml;
	sample.close();
	}
	catch (const std::exception& e)
	{
	std::cout << e.what();
	}
    return xml;
}







//Returns a xml string and used to persist values in the XML Document for SCC
std::string toXmlscc(std::vector<std::vector<int>>& db, std::unordered_map<int, File>& rev)
{
	std::string xml;
	XmlDocument doc;
	SPtr pRoot = makeTaggedElement("DBX");
	doc.docElement() = pRoot;	
	for (std::vector<int> r : db)
	{
		
		SPtr ele15 = makeTaggedElement("SCC_Component");
		pRoot->addChild(ele15);
		for  (int a : r)
		{
			
				SPtr techild = makeTaggedElement("Child");
				ele15->addChild(techild);
				SPtr childvalue = makeTextElement(rev[a]);
				techild->addChild(childvalue);

			}

		

	}
	xml = doc.toString();
	try
	{
		std::ofstream sample("../nishuu.xml");
		sample << xml;
		sample.close();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
	return xml;
}





