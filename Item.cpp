/************************************
*									*
*		Nathan Whitchurch			*
*		CIS 214 Dean Chapman		*
*		Final Project				*
*									*
************************************/
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Item.h"

using namespace std;


/****************************************************
*		All of the base class funstions for item	* 
*		are included in this file. As an abstract 	*
*		class all of these functions should be		*
*  		over ridden by the child class functions	*
*													*
*****************************************************/
Item::Item()
	{
		
	}
Item::Item(string itemIn)
	{
		item = Item::getItemNum(itemIn);
		description = Item::getDescrip(itemIn);
		shelf = Item::getShelf(itemIn);
		price = Item::getPrice(itemIn);
		quantity = Item::getQtNumber(itemIn);
	
	}//end Item constructor 
	
	
	
	
	
	
	
	
	
/************************************************************
*															*
*		The Following are all the Get methods for parsing	*
*		input from inventory.txt							*
*															*
*************************************************************/
	
	
string Item::getItemNum(string itemIn)
	{
		string itemNumOut = itemIn.substr(0,5);
		return itemNumOut;
	}//end getItemNum
	
string Item::getDescrip(string itemIn)
	{
		string descOut = itemIn.substr(6,15);
		return descOut;
	}//end getShelf
	
	
string Item::getShelf(string itemIn)

	{
		string shelfOut = itemIn.substr(21,6);
		return shelfOut;
	}//end getShelf

float Item::getPrice(string itemIn)
	{
		string priceIn = itemIn.substr(27,5);
		stringstream priceExtract(priceIn);
		float priceOut = 0;
		priceExtract >> priceOut;
		return priceOut;
		
	}//end getPrice
	
int Item::getQtNumber(string itemIn)
	{
		string qtNumIn = itemIn.substr(32,6);
		stringstream qtNumExtract(qtNumIn);
		int qtNumOut = 0;
		qtNumExtract >> qtNumOut;
		return qtNumOut;
		
	}//end GetItemNumber
	


	

	
	

