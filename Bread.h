/************************************
*									*
*		Nathan Whitchurch			*
*		CIS 214 Dean Chapman		*
*		Final Project				*
*									*
*		Bread.h						*
*									*
************************************/



#ifndef BREAD_H
#define BREAD_H

#include <cstdlib>
#include <iostream>

using namespace std;

class Bread : public Item
	{
		private:
			int shelfLife; // shelf life in days 
			bool fresh; //Baked fresh or packaged
			
			
		public:
			void printLabel();
			static void printBreadHeader(int);
			void printBreadLine(int);
			
			
			Bread();
			Bread(string);
						
			int getLife(string);
			bool getFresh(string);
	};





#endif
