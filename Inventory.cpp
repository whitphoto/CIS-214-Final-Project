/************************************
*									*
*		Nathan Whitchurch			*
*		CIS 214 Dean Chapman		*
*		Final Project				*
*									*
*		Inventory.cpp				*
*									*
************************************/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>

#include "Inventory.h"
#include "Produce.h"
#include "Item.h"



/********************************************************************
*																	*
*	Default constructor only, all values set by member functions	*
*	with nothibg passed in.											*
*																	*
********************************************************************/

Inventory::Inventory()
	{
		
	}//end constructor
	
	
	
/********************************************************************************
*																				*
*		popInventory() first creates three arrays, one for each type of 		*
*		inventory item in this project. The sizes are determined with a call 	*
*		to the countInventory() function. popInventory() then reads from the 	*
*		inventoryy.txt, parses the itemType from the string to determine 		*
*		which array it should go into and creates a new object in the			*
*		appropriate array.														*
*																				*
********************************************************************************/

void Inventory::popInventory()
	{
			countInventory();
			
			produceArray = new Produce[prodSize];	
			int produceArraySpace = 0;						
													// These three blocks of declarations set up
			breadArray = new Bread[breadSize];		// the arrays for the three classes of products 
			int breadArraySpace = 0;				// in the inventory
			
			drinkArray = new Drink[drinkSize];
			int drinkArraySpace = 0;
			
				ifstream infile;
				string itemIn;
				
		        infile.open("inventory.txt");
		        if(infile.is_open())
		            {
						cout << "\nInventory.txt Opened for reading!";
		            }
		        if(infile.fail())
		            {
		                cerr << "Error Opening File"; 
		                exit(1);
		            }
		         
		    		while (!infile.eof())
		    			{
		    				getline (infile, itemIn);
		    					string itemTypeIn = Inventory::itemType(itemIn);	// parses item type out
										
								if ( itemTypeIn == "pr")
									{
										produceArray[produceArraySpace] = Produce(itemIn);
								
										produceArraySpace++;
									}// end produce if loop
								
								else if ( itemTypeIn == "br")								// these three if statements determine
									{														// the type of inventory produce and 
										breadArray[breadArraySpace] = Bread(itemIn);		// populate the appropriate array with 
																							// created objects by passing the string
										breadArraySpace++;									// itemIn to the appropriate constructor
									}// end bread if loop
								
								else if ( itemTypeIn == "bv")
									{
										drinkArray[drinkArraySpace] = Drink(itemIn);
								
										drinkArraySpace++;
									
									}// end drink if loop
									
						}// end while
	}//end popInventory()
	
/************************************************************************************
*																					*
*		countInventory opens the inventory.txt file and determines the number		*
*		of each type of inventoy by parsing out the two character itemType 			*
*		that starts each line. It then calls the three set methods. This is 		*
*		needed becuase C++ does not utilize dynamic arrays.							*
*																					*
*************************************************************************************/
	
void Inventory::countInventory()
	{
	
		int prodCount = 0;
		int breadCount = 0;
		int drinkCount = 0;
				
		ifstream inFile;
		string t;
		
			inFile.open("inventory.txt");
		    if(inFile.is_open())
		        {cout << "\nInventory.txt opened for counting!\n";}
		        if(inFile.fail())
		            {
		                cerr << "Error Opening File"; 
		                exit(1);
		            }
		         
		    		while (!inFile.eof())
		    			{							
		         			getline(inFile,t);
					        string type = Inventory::itemType(t);
					        if (type == "pr")		
					        	prodCount++;
					        if (type=="br")			// determine type from 
					        	breadCount++;		// parsed data
					        if (type=="bv")
					        	drinkCount++;
						}//end while
						
						
						setProdSize(prodCount);		// call set functions to change the 
						setBreadSize(breadCount);	// values of the private variables
						setDrinkSize(drinkCount);	// 
												
	}//end countInventory();
	

/********************************************************************
*																	*
*		this function, itemType(), will parse out the first two 	*
*		characters of the string which will identify the type of	*
*		inventory item and therefore the class it should be 		*	
*		instantiated into											*
*																	*
*********************************************************************/

string Inventory::itemType(string itemIn)
	{
		
		string itemType = itemIn.substr(0,2);
		
		if (itemType == "pr")
			{
				return "pr";			
			}
		else if (itemType == "br")
			{
			  	return "br";	 	
			}
		else if (itemType == "bv")
			{
				return "bv"; 			
			}
			
	}//end itemType

void Inventory::printFullReport()
	{
		if( remove( "InventoryReport.txt" ) != 0 )
    		perror( "Error deleting file" );
 		else
    		puts( "Old file successfully deleted" );
    		
		Inventory::printProduceReport(1);
		Inventory::printBreadReport(1);
		Inventory::printDrinkReport(1);		
		
		Inventory::mainMenu();
	}
		
void Inventory::printZeroStockLevels()
	{
		if( remove( "ZeroLevelsReport.txt" ) != 0 )
    		perror( "Error deleting file" );
 		else
    		puts( "Old file successfully deleted" );
    	
    	Inventory::printProduceReport(3);
		Inventory::printBreadReport(3);
		Inventory::printDrinkReport(3);	
		
		Inventory::mainMenu();
		
	}
void Inventory::printProduceReport(int reportType)
	{
		if (reportType == 1)
			{
				Produce::printProdHeader(reportType);
				int size = this->getProdSize();
				for (int i = 0; i < size; i++);
				size = this->getProdSize();
				for (int i = 0; i < size; i++)
					{
						this->produceArray[i].printLine(reportType);
					}//end for loop
			}
		else if (reportType == 2)
			{
				if( remove( "ProduceReport.txt" ) != 0 )
	    			perror( "Error deleting file" );
	 			else
	    			puts( "Old file successfully deleted" );
	    
	    		Produce::printProdHeader(reportType);
				int size = this->getProdSize();
				for (int i = 0; i < size; i++)
					{
						this->produceArray[i].printLine(reportType);
					}//end for loop
	    		
    		}
    	else if (reportType == 3)
    	{
		
		Produce::printProdHeader(reportType);
		int size = this->getProdSize();
		for (int i = 0; i < size; i++)
			{
				if (this->produceArray[i].getInvQt() == 0)
					this->produceArray[i].printLine(reportType);
			}//end for loop
		}// end if
	}//end printProduceReport
	
void Inventory::printBreadReport(int reportType)
	{
		
		if (reportType == 1)
			{
				Bread::printBreadHeader(reportType);
				int size = this->getBreadSize();
				for (int i = 0; i <size; i++)
					{
						this->breadArray[i].printBreadLine(reportType);
					}//end for loop
			}
		else if (reportType == 2)
  			{
  				if( remove( "BreadReport.txt" ) != 0 )
    				perror( "Error deleting file" );
    		
				Bread::printBreadHeader(reportType);
				int size = this->getBreadSize();
				for (int i = 0; i <size; i++)
					{
						this->breadArray[i].printBreadLine(reportType);
					}//end for loop
			}
		else if (reportType ==3)
			{
				Bread::printBreadHeader(reportType);
				int size = this->getBreadSize();
				for (int i = 0; i <size; i++)
					{
						if (this->breadArray[i].getInvQt() == 0)
							this->breadArray[i].printBreadLine(reportType);
					}//end for loop
			}// end if
					
	}//end printBreadReport
	
void Inventory::printDrinkReport(int reportType)
	{
		if (reportType == 1)
			{
				Drink::printDrinkHeader(reportType);
				int size = this->getDrinkSize();
				for (int i = 0; i < size; i++)
					{
						this->drinkArray[i].printDrinkLine(reportType);
					}//end for loop
			}
		else if (reportType == 2)
  			{
  				if( remove( "DrinkReport.txt" ) != 0 )
    				perror( "Error deleting file" ); 		
				Drink::printDrinkHeader(reportType);
				int size = this->getDrinkSize();
				for (int i = 0; i < size; i++)
					{
						this->drinkArray[i].printDrinkLine(reportType);
					}//end for loop
			}
		else if (reportType == 3)
			{
				Drink::printDrinkHeader(reportType);
				int size = this->getDrinkSize();
				for (int i = 0; i < size; i++)
					{
						if (this->drinkArray[i].getInvQt() == 0)
						this->drinkArray[i].printDrinkLine(reportType);
					}//end for loop
			}
	}//end printDrinkReport
	
void Inventory::mainMenu()
	{
		int choice = 0;
		cin.clear();
		cout << "\ncout << choice " << choice ;
    	
		try{
				
			cout 	
					<< endl
					<< endl
					<< "|----Main Menu----|"
					<< endl
					<< "1: Reports"
					<< endl
					<< "2: Labels"
					<< endl
					<<"3: Exit Program"
					<< endl
					<< "Please press 1, 2 or 3: ";
						
			cin >> choice;
		
			while(1)
				{
				if(cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(),'\n');
						cout<< "Please enter numbers only!!" <<endl;
						this->mainMenu();
					}//end if loop
					if(!cin.fail())
						break;
				}//end while loop
			if (choice == 1)
				Inventory::reportMenu();
			else if (choice == 2)
				Inventory::labelMenu();
			else if (choice == 3)
				exit(1);// end if
			else if (choice <1 | choice >3)
			{
				choice = 0;
				cout<<"\nthrowing error";
				throw 1;
			}// end if
		}// end try
		
	catch(int menu)
		{
			cout<<"throwing error";
			this->errorMessage(menu);
		}//end catch
	
	}//end mainMenu
	
void Inventory::reportMenu()
	{
		int choice = 0;
		cin.clear();
		
		try{		
			cout 	
					<< endl
					<< endl
					<< "|----Reports Menu----|"
					<< endl
					<< "1: Print Full Report"
					<< endl
					<< "2: Produce Report Only"
					<< endl
					<<	"3: Bread Report Only"
					<< endl
					<< "4: Drink Report Only"
					<< endl
					<< "5: Zero Stock Levels Report"
					<< endl
					<< "6: Return To Main Menu"
					<< endl
					<< "Please choose 1 through 6: ";
					
					cin >> choice;					
			while(1)
				{
				if(cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(),'\n');
						cout<< "Please enter numbers only!!" <<endl;
						this->reportMenu();
					}//end if loop
					if(!cin.fail())
						break;
				}//end while loop
			if (choice == 1)
				this->printFullReport();
			else if (choice == 2)
				{
					Inventory::printProduceReport(2);
					Inventory::mainMenu();
				}
			else if (choice == 3)
				{
					Inventory::printBreadReport(2);
					Inventory::mainMenu();
				}
			else if (choice == 4)
				{
					Inventory::printDrinkReport(2);
					Inventory::mainMenu();
				}
			else if (choice ==5)
				this->printZeroStockLevels();
			else if (choice == 6)
				this->mainMenu();
			else if (choice <1 | choice >5)
			{
				choice = 0;
				cout<<"\nthrowing error";
				throw 2;
			}// end if				
		}// end try
		
	catch(int menu)
		{
			cout<<"throwing error";
			this->errorMessage(menu);
		}//end catch				
	}// end reportMenu
	
	

void Inventory::labelMenu()
	{
		int choice = 0;
		cin.clear();
		try{
				cout
						<< "|---Labels---|" << endl
						<< "1. Print Labels" << endl 
						<< "2. Return To Main Menu" << endl
						<< "Please choose 1 or 2: ";	
				cin >> choice;					
				while(1)
					{
					if(cin.fail())
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(),'\n');
							cout<< "Please enter numbers only!!" <<endl;
							this->reportMenu();
						}//end if loop
						if(!cin.fail())
							break;
					}//end while loop	
				if (choice == 1)
					Inventory::printAllLabels();
				else if (choice == 3)
					this->mainMenu();
				else if (choice <1 | choice >2)
					{
						choice = 0;
						throw 3;
					}// end if
			}// end try
			catch(int menu)
				{
					this->errorMessage(3);
				}

	}// end labelMenu
	
void Inventory::errorMessage(int menu)
	{
		cout << "\n you have entered an invalid choice. Please choose again.";
		
		if (menu == 1)
			this->mainMenu();
		if (menu == 2)
			this->reportMenu();
		if (menu == 3)
			this->labelMenu();
	}
void Inventory::printAllLabels()
	{
		int size;
		size = this->getProdSize();
			for (int i = 0; i < size; i++ )
				{
					this->produceArray[i].printLabel();
				}// end for loop
		size = this->getBreadSize();
			for (int i = 0; i < size; i++ )
				{
					this->breadArray[i].printLabel();
				}// end for loop
		size = this->getDrinkSize();
			for (int i = 0; i < size; i++ )
				{
					this->drinkArray[i].printLabel();
				}// end for loop
	}
