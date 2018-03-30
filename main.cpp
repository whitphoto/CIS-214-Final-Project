/************************************
*									*
*		Nathan Whitchurch			*
*		CIS 214 Dean Chapman		*
*		Final Project				*
*									*
************************************/


#include <iostream>
#include <cstdlib>


#include "Item.h"
#include "Produce.h"
#include "Bread.h"
#include "Drink.h"

#include "Inventory.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
	{
				
		Inventory *test = new Inventory;		// create Inventory object
		test->popInventory();					// populate the arrays 
		test->mainMenu();						// print menu for user interaction
		
		return 0;
	}
