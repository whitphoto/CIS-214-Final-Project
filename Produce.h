/************************************
*									*
*		Nathan Whitchurch			*
*		CIS 214 Dean Chapman		*
*		Final Project				*
*									*
*		Produce.h					*
*									*
************************************/



#ifndef PRODUCE_H
#define PRODUCE_H

#include <cstdlib>
#include <iostream>
#include "Item.h"

using namespace std;


/****************************************************
*													*
*		Produce is a child class of item, inheriting*
*		all of the protected variables and adding	*
*		ones unique to produce items as well as		*
*		defining a printLabel function				*
*													*
*****************************************************/

class Produce : public Item
	{
		private:
			int shelfLife; // shelf life in days 
			bool packaged; // packaged or not, to label price by pound if needed
			
			
		public:
			
			Produce();
			Produce(string);
			
			int getLife(string);
			bool getPack(string);
			
			static void printProdHeader(int);
		
			void printLine(int);
			void printLabel();
	};
	
#endif
