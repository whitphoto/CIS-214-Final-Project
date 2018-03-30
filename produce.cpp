/************************************
*									*
*		Nathan Whitchurch			*
*		CIS 214 Dean Chapman		*
*		Final Project				*
*									*
*		Produce.cpp					*
*									*
************************************/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>


#include "Produce.h"
#include "Item.h"



using namespace std;


/********************************************************************************************
*																							*
*		The constructor for this child class will handle all of it's own unique variables	*
*		within the constructor and call the base class constructor with the common variables* 
*		to reduce code. A default constructor is needed to create an empty array and is 	*
*		empty.																				*
*																							*
*********************************************************************************************/

Produce::Produce() : Item()
	{
		
	}//Default constructor
	
Produce::Produce(string itemIn) : Item (itemIn)
	{
		shelfLife = Produce::getLife(itemIn);
		packaged =  Produce::getPack(itemIn);

	}//end Produce constructor
		
	
int Produce::getLife(string itemIn)
	{
		string lifeIn = itemIn.substr(38,4);
		stringstream lifeExtract(lifeIn);
		int lifeOut = 0;
		lifeExtract >> lifeOut;
		return lifeOut;
		
	}//end getLife()
	
	
bool Produce::getPack(string itemIn)
	{
		string packIn = itemIn.substr(42,1);
	
		bool packOut;
		if (packIn == "0")
			packOut = false;
		else if(packIn == "1")
			packOut = true;			
		return packOut;
	}//end getPack
	
void Produce::printProdHeader(int reportType)
	{
		const int pad = 3;
		const string sep = " | ";
		const string line = sep + string(74, '-') + sep;

		cout	
				<< endl << line << endl
				<< sep
				<< string(33, ' ') << "PRODUCE" << string(34, ' ')
				<< sep
				<< endl << line << endl
				<< sep
				<< setw(6) << "Item" << sep 
				<< setw(15) << "Description" << sep
				<< setw(6) << "Shelf" << sep
				<< setw(5) << "Price" << sep
				<< setw(6) << "Quant" << sep
				<< setw(9) << "Shelf Life" << sep
				<< setw(8) << "Packaged" << sep
				<< endl << line;
				
		std::ofstream outfile;

  			if (reportType == 1)
				outfile.open("InventoryReport.txt", std::ios_base::app);
			  		
  		else if (reportType == 2)
				outfile.open("ProduceReport.txt", std::ios_base::app);	
		else if (reportType == 3)
			{
				outfile.open("ZeroLevelsReport.txt", std::ios_base::app);
			}
  		outfile
				<< endl << line << endl
				<< sep
				<< string(33, ' ') << "PRODUCE" << string(34, ' ')
				<< sep
				<< endl << line << endl
				<< sep
				<< setw(6) << "Item" << sep 
				<< setw(15) << "Description" << sep
				<< setw(6) << "Shelf" << sep
				<< setw(5) << "Price" << sep
				<< setw(6) << "Quant" << sep
				<< setw(9) << "Shelf Life" << sep
				<< setw(8) << "Packaged" << sep
				<< endl << line;
				
  
	}// end printProdHeader
	

	
void Produce::printLine(int reportType)
	{
		string pad = string(3, ' ');
		
		string packOut;
				if (packaged == 1)
					packOut = "Yes";
				else if (packaged == 0)
					packOut = "no";
		
		cout 	<< endl << pad
				<< setw(6) << item << pad
				<< setw(15)	<< description << pad
				<< setw(6) << shelf << pad
				<< setw(5) << price << pad
				<< setw(6) << quantity << pad
				<< setw(9) << shelfLife << pad
				<< setw(8) << packOut << pad;
				
		std::ofstream outfile;
		
		if (reportType == 1)
				outfile.open("InventoryReport.txt", std::ios_base::app);  		
  		else if (reportType == 2)
				outfile.open("ProduceReport.txt", std::ios_base::app);	
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
				<< setw(8) << packOut << pad;
		  
		  				
	}
	

void Produce::printLabel()
	{
		cout 
				<< endl
				<< setw(15) << description << string(10, ' ')
				<< setw(5) << price
				<< endl
				<< setw(6) << item << string(18, ' ')
				<< setw(6) << shelf
				<< endl;		
	}//end produce printLabel()
	
	


