/************************************
*									*
*		Nathan Whitchurch			*
*		CIS 214 Dean Chapman		*
*		Final Project				*
*									*
*		Bread.cpp					*
*									*
************************************/
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

#include "Bread.h"
#include "Item.h"

using namespace std;


/********************************************************************************************
*																							*
*		The constructor for this child class will handle all of it's own unique variables	*
*		within the constructor and call the base class constructor with the common variables* 
*		to reduce code. A default constructor is needed to create an empty array			*
*																							*
*********************************************************************************************/

Bread::Bread()
	{
	}
Bread::Bread(string itemIn) : Item (itemIn)
	{
		shelfLife = Bread::getLife(itemIn);
		fresh = Bread::getFresh(itemIn);
	
	}//end Bread constructor
	
int Bread::getLife(string itemIn)
	{
		string lifeIn = itemIn.substr(38,4);
		stringstream lifeExtract(lifeIn);
		int lifeOut = 0;
		lifeExtract >> lifeOut;
		return lifeOut;
	}//end getLife()
	
bool Bread::getFresh(string itemIn)
	{	
	bool freshOut;
	
		string freshIn = itemIn.substr(42,1);
		if (freshIn == "0")
			freshOut = false;
		else if (freshIn == "1")	
			freshOut = true;
			
	return freshOut;
	}//end getFresh()
	
void Bread::printLabel()
	{
		cout 
				<< endl
				<< setw(15) << description << string(10, ' ')
				<< setw(5) << price
				<< endl
				<< setw(6) << item << string(18, ' ')
				<< setw(6) << shelf
				<< endl;		
	}//end Bread printLabel()
	
void Bread::printBreadHeader(int reportType)
	{
		const int pad = 3;
		const string sep = " | ";
		const string line = sep + string(77, '-') + sep;
				
		cout	
				<< endl << line << endl
				<< sep
				<< string(36, ' ') << "BREAD" << string(36, ' ')
				<< sep
				<< endl << line << endl
				<< sep
				<< setw(6) << "Item" << sep 
				<< setw(15) << "Description" << sep
				<< setw(6) << "Shelf" << sep
				<< setw(5) << "Price" << sep
				<< setw(6) << "Quant" << sep
				<< setw(9) << "Shelf Life" << sep
				<< setw(11) << "Fresh Baked" << sep
				<< endl << line;
				
				
		std::ofstream outfile;
		
		if (reportType == 1)
			{
				outfile.open("BreadReport.txt", std::ios_base::app);
			}
  		
  		else if (reportType == 2)
  			{
				outfile.open("BreadReport.txt", std::ios_base::app);	
			}
		
		else if (reportType == 3)
			{
				outfile.open("ZeroLevelsReport.txt", std::ios_base::app);
			}
		outfile
				<< endl << line << endl
				<< sep
				<< string(36, ' ') << "BREAD" << string(36, ' ')
				<< sep
				<< endl << line << endl
				<< sep
				<< setw(6) << "Item" << sep 
				<< setw(15) << "Description" << sep
				<< setw(6) << "Shelf" << sep
				<< setw(5) << "Price" << sep
				<< setw(6) << "Quant" << sep
				<< setw(9) << "Shelf Life" << sep
				<< setw(11) << "Fresh Baked" << sep
				<< endl << line;
				
	}// end printBreadHeader
	
	
void Bread::printBreadLine(int reportType)
	{
		string pad = string(3, ' ');
		
		string freshOut;
		
		if (fresh == 1)
			freshOut = "Yes";
		else if (fresh == 0)
			freshOut = "no";
		
		cout 	
				<< endl << pad
				<< setw(6) << item << pad
				<< setw(15)	<< description << pad
				<< setw(6) << shelf << pad
				<< setw(5) << price << pad
				<< setw(6) << quantity << pad
				<< setw(9) << shelfLife << pad
				<< setw(11) << freshOut << pad;
				
				std::ofstream outfile;
		
		if (reportType == 1)
			{
				outfile.open("BreadReport.txt", std::ios_base::app);
			}
  		
  		else if (reportType == 2)
  			{
				outfile.open("BreadReport.txt", std::ios_base::app);	
			}
			
		else if (reportType == 3)
			{
				outfile.open("ZeroLevelsReport.txt", std::ios_base::app);
			}
			
		outfile
				<< endl << pad
				<< setw(6) << item << pad
				<< setw(15)	<< description << pad
				<< setw(6) << shelf << pad
				<< setw(5) << price << pad
				<< setw(6) << quantity << pad
				<< setw(9) << shelfLife << pad
				<< setw(11) << freshOut << pad;
		
		
	}// end printBreadLine
	
	
