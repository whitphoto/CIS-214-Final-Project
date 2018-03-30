/************************************
*									*
*		Nathan Whitchurch			*
*		CIS 214 Dean Chapman		*
*		Final Project				*
*									*
*		Drink.h						*
*									*
************************************/



#ifndef DRINK_H
#define DRINK_H

#include <cstdlib>
#include <iostream>
#include "Item.h"

using namespace std;

class Drink : public Item
	{
		 
		private: 			//defines the size and type of packaging
			char size;		// 1 for two liter, 2 for 6 pack, 3 for 12 pack, 4 for 16oz bottles
							// any other value will result in an error caught in functions
			
			
		public:
			void printLabel();
			Drink();
			Drink(string);
			char getSize(string);
			
			static void printDrinkHeader(int);
			void printDrinkLine(int);
			
			
	};





#endif
