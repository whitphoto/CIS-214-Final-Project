/************************************
*									*
*		Nathan Whitchurch			*
*		CIS 214 Dean Chapman		*
*		Final Project				*
*									*
*		Inventory.h					*
*									*
************************************/

#ifndef INVENTORY_H
#define INVENTORY_H

#include <cstdlib>
#include <iostream>

#include "Item.h"
#include "Produce.h"
#include "Bread.h"
#include "Drink.h"

using namespace std;

class Inventory
	{
		private:
			void setProdSize(int sizeIn) {prodSize = sizeIn;};		// Set methods coded inline 
			void setDrinkSize(int sizeIn) {drinkSize = sizeIn;};	// with declaration since they 
			void setBreadSize(int sizeIn) {breadSize = sizeIn;};	// are one line functions
			
			void countInventory();
								
			int prodSize;											// Variables used to set and 
			int breadSize;											// later determine the size of
			int drinkSize;											// of the product arrays. Private
																	// so they can only be altered by set 
																	// functions
		public:
			
			Inventory();
			
			Produce *produceArray;	// arrays of inventory items declared public
			Bread *breadArray;		// so functions in other classes can access 
			Drink *drinkArray;		// easily
			
			void popInventory();	

			string itemType(string);	
			
			void printFullReport();			// 
			void printProduceReport(int);	//
			void printBreadReport(int);		// report functions
			void printDrinkReport(int);		//
			void printZeroStockLevels();
			
			void printAllLabels();
			
			
			int getProdSize(){return prodSize;};		// get methods coded inline
			int getBreadSize(){return breadSize;};		// with declaration since they
			int getDrinkSize(){return drinkSize;};		// are one line functions
			
			void mainMenu();							//
			void reportMenu();							// Menu methods and exception
			void labelMenu();							// handling 
			void errorMessage(int);						//
		
	};

#endif
