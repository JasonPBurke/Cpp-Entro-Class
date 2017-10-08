/*
//  Author: Jason Burke;
//  Course: COSC 1337 Summer 2016 MW16;
//  Instructor: Thayer
//  Lab 6: Write a program that...

    Program description
*/

#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
using namespace std;

class Inventory {

    private:
	  int itemNumber;
	  int quantity;
	  double cost;
	  string itemDescription;
	  
	public:
	  
	  Inventory();// default constructor prototype	  
	  Inventory(int, int, double, string);//Constructor 2 prototype
	  
	  void setItemNumber(int i) {itemNumber = i;}	  
	  void setQuantity(int q) {quantity = q;}	  
	  void setCost(double c) {cost = c;}	  
	  void setItemDescription(string d) {itemDescription = d;}	  
	  int getItemNumber() {return itemNumber;}	  
	  int getQuantity() {return quantity;}	  
	  double getCost() {return cost;}	  
	  string getItemDescription() {return itemDescription;}	  
	  double getTotalCost() {return cost * quantity;}	  
};// end class Inventory

Inventory::Inventory() {// Default constructor definition
  itemNumber = quantity = cost = 0.00;
  itemDescription = "No Description Found";
};

Inventory::Inventory(int i, int q, double c, string desc) {//Constructor 2 definition
  setItemNumber(i);// Calling members functions to set the data
  setQuantity(q);
  setCost(c);
  setItemDescription(desc);
}	

int main() {
		
	Inventory myInventory0, myInventory1, myInventory2, myInventory3, myInventory4;// create 5 Inventory objects to fill the array
	
	cout<< "How many items in your inventory (1-5)? ";
	int totalItems = 0;
	cin>> totalItems;
	cout<< endl;
	Inventory itemArray[5] {myInventory0, myInventory1, myInventory2, myInventory3, myInventory4};// array of objects
	//vector <Inventory> itemVector {myInventory_test}
	while(true) {// Set to false to 'turn off' the while loop for testing

		if(totalItems<=5 || totalItems == true) {
				
			for(int i=0; i<totalItems; i++) {
	
				static int count =0;
				cout<< "\n Enter item "<< ++count<< " description: ";
				cin.get();
				string desc; getline(cin, desc);//cin>> desc;
				itemArray[i].setItemDescription(desc);
				cout<< "\n Enter the item number: ";
				int itemNum; cin>> itemNum;
				itemArray[i].setItemNumber(itemNum);
				cout<< "\n Enter the quantity: ";
				int quant; cin>> quant;
				itemArray[i].setQuantity(quant);
				cout<< "\n Enter the cost: ";
				double cst; cin>> cst;
				itemArray[i].setCost(cst);				
			}
			static double grandTotal;
			for(int i=0; i<totalItems; i++) {
			
				cout<< "\nList Item #"<< i+1<< endl;
				cout<< " Item Description: "<< itemArray[i].getItemDescription()<< endl;// adding the string item description
				cout<< " Inventory item number: "<< itemArray[i].getItemNumber()<< endl;
				cout<< " Item quantity: "<< itemArray[i].getQuantity()<< endl;
				cout<< " Item cost each: $"<< itemArray[i].getCost();
				cout<< fixed<< showpoint<< setprecision(2)<< endl;
				cout<< " Total cost for this item: $"<< itemArray[i].getTotalCost()<< endl;// do a += to get a grand total
				grandTotal+= itemArray[i].getTotalCost();
			}
			cout<<"\n Grand Total for inventory entered: $"<< grandTotal<< endl;	
			break;
		} else {
			cin.clear();
			cin.ignore(240,'\n');
			cout<< "Please indicate 5 or less items: ";
			cin>> totalItems;
			cout<< endl;
		}
	}
	return 0;
}// end main()

/*
How many items in your inventory (1-5)? 3


 Enter item 1 description: Base Balls

 Enter the item number: 34

 Enter the quantity: 12

 Enter the cost: 5.99

 Enter item 2 description: Baseball Bats

 Enter the item number: 45

 Enter the quantity: 99

 Enter the cost: 34.99

 Enter item 3 description: Baseball Gloves

 Enter the item number: 12

 Enter the quantity: 55

 Enter the cost: 43.99

List Item #1
 Item Description: Base Balls
 Inventory item number: 34
 Item quantity: 12
 Item cost each: $5.99
 Total cost for this item: $71.88

List Item #2
 Item Description: Baseball Bats
 Inventory item number: 45
 Item quantity: 99
 Item cost each: $34.99
 Total cost for this item: $3464.01

List Item #3
 Item Description: Baseball Gloves
 Inventory item number: 12
 Item quantity: 55
 Item cost each: $43.99
 Total cost for this item: $2419.45

 Grand Total for inventory entered: $5955.34

--------------------------------
Process exited after 56.92 seconds with return value 0
Press any key to continue . . .
*/
