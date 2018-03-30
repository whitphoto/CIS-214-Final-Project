/************************************
*									*
*		Nathan Whitchurch			*
*		CIS 214 Dean Chapman		*
*		Final Project				*
*									*
*		Drink.cpp					*
*									*
************************************/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

#include "Drink.h"
#include "Item.h"

using namespace std;


/********************************************************************************************
*																							*
*		The constructor for this child class will handle all of it's own unique variables	*
*		within the constructor and call the base class constructor with the common variables* 
*		to reduce code. A default constructor is needed to create an empty array			*
*																							*
*********************************************************************************************/


Drink::Drink()
	{
	}

Drink::Drink(string itemIn) : Item(itemIn)
	{
		size = Drink::getSize(itemIn);
	
	}

void Drink::printLabel()
	{
		cout 
				<< endl
				<< setw(15) << description << string(10, ' ')
				<< setw(5) << price
				<< endl
				<< setw(6) << item << string(18, ' ')
				<< setw(6) << shelf
				<< endl;		
	}//end Drink printLabel()
	
	
	
char Drink::getSize(string itemIn)
	{
		char sizeOut = itemIn[37];
		return sizeOut;
	}

void Drink::printDrinkHeader(int reportType)
	{
		const int pad = 3;
		const string sep = " | ";
		const string line = sep + string(77, '-') + sep;
				
		cout	
				<< endl << line << endl
				<< sep
				<< string(36, ' ') << "DRINKS" << string(35, ' ')
				<< sep
				<< endl << line << endl
				<< sep
				<< setw(6) << "Item" << sep 
				<< setw(15) << "Description" << sep
				<< setw(6) << "Shelf" << sep
				<< setw(5) << "Price" << sep
				<< setw(6) << "Quant" << sep
				<< setw(10) << "Drink Size" << sep
				<< string(11, ' ') << sep
				<< endl << line;
				
		std::ofstream outfile;
		
		if (reportType == 1)
			{
				outfile.open("InventoryReport.txt", std::ios_base::app);
			}
  		
  		else if (reportType == 2)
  			{	
				outfile.open("DrinkReport.txt", std::ios_base::app);	
			}
		else if (reportType == 3)
			{
				outfile.open("ZeroLevelsReport.txt", std::ios_base::app);
			}
		outfile
				<< endl << line << endl
				<< sep
				<< string(36, ' ') << "DRINKS" << string(35, ' ')
				<< sep
				<< endl << line << endl
				<< sep
				<< setw(6) << "Item" << sep 
				<< setw(15) << "Description" << sep
				<< setw(6) << "Shelf" << sep
				<< setw(5) << "Price" << sep
				<< setw(6) << "Quant" << sep
				<< setw(10) << "Drink Size" << sep
				<< string(11, ' ') << sep
				<< endl << line;
			
				
				
				
	}// end printDrinkHeader
	
void Drink::printDrinkLine(int reportType)
	{

			
		char sizeIn = size;
		string sizeOut;
		
		if (sizeIn == '1')
			sizeOut = "16 Ounce";
		else if (sizeIn == '2')
			sizeOut = "2 Liter";
		else if (sizeIn == '3')
			sizeOut = "Six Pack";
		
		string pad = string(3, ' ');
		cout 	<< endl << pad
				<< setw(6) << item << pad
				<< setw(15)	<< description << pad
				<< setw(6) << shelf << pad
				<< setw(5) << price << pad
				<< setw(6) << quantity << pad
				<< setw(10) << sizeOut << pad;
				
	std::ofstream outfile;
		
		if (reportType == 1)
			{
				outfile.open("InventoryReport.txt", std::ios_base::app);
			}
  		
  		else if (reportType == 2)
  			{
				outfile.open("DrinkReport.txt", std::ios_base::app);	
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
				<< setw(10) << sizeOut << pad;
		
	}
	

