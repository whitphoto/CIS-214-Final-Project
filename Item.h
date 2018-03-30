/************************************
*									*
*		Nathan Whitchurch			*
*		CIS 214 Dean Chapman		*
*		Final Project				*
*									*
************************************/

/************************************************************
*															*
*		This is the abstracted base class that all items	*
*		in the store will be children of.					*
*		The printLabel function, a pure virtual function, 	*
*		make this an abstract base class.					*
*															*
*************************************************************/

#ifndef ITEM_H
#define ITEM_H

#include <cstdlib>
#include <iostream>

using namespace std;

/***************************************************************************
*																			*
*		Item will be the abstracted base class that all items will 			*
*		be based on. As an abstracted class it will never be instantaiated	*
*		directly, but the constructor will be refered to in the child		*
*		class constructors to simplify code.								*
*																			*
*****************************************************************************/


class Item
	{
		protected:
			
			string item; //although represented by numbers this is kept as a string so no math is accidently applied to it
			string description;
			string shelf;//although represented by numbers this is kept as a string so no math is accidently applied to it
			float price;
			int quantity;
			
				
		
		public:
			Item();
			Item(string);
			virtual void printLabel() =0; // pure virtual function makes this an abstracted base class
			//virtual void stockLevels();
			
			
			//the following functions will be used to parse out the relevent information 
			//from the getItem() function in class InOut and convert it into INTs or FlOATS 
			//if needed. Any unique data needed by a child class will be parsed by a function
			//within that class. As a parent class all functions will be inherited to children
			
			string getItemNum(string);
			string getDescrip(string);
			string getShelf(string);
			float getPrice(string);
			int getQtNumber(string);
			
			int getInvQt() {return quantity;};
			
	};
	
	
	
	
#endif
