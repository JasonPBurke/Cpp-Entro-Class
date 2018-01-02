/*
//  Author: Jason Burke;

//  Lab 2:  Create a diamond pattern whose number of lines can be determined by the user.
*/

#include <iostream>
using namespace std;

/*
This program will ask the user how many lines they want the diamond pattern to be, and then print out a 
diamond shape with that number of rows.  works for odd and even numbers.  It will also loop, asking for 
another number from the user until the user enters 0 (or a negitave number).
*/
int main() {
	
	int row = 0;
	int col_star = 0;
	int col_space = 0;
	int num_lines = 2;
	
	cout << "Hello there!  I can print out a diamond pattern using any number of lines.\n";
	while (num_lines-1>0) {// added the -1 so that the user can enter 0 to quit.
		cout << "How many lines would you like the diamond to be? (0 to exit) ";
		cin >> num_lines;
		num_lines++;// I had to increment the num_lines by one to get the spacing correct....
		
		
		// you could use % to check if the input # is odd/even; then if/else the appropriate for loops...
		// this loop will draw the top half of the diamond pattern. 
		for (row = 1; row <(num_lines/2)+1; row++) 
		{
			for (col_space = (num_lines/2)-row; col_space >= 1; col_space--) 
			{
				cout << " ";
			}
			for (col_star = 1; col_star <= (row*2)-1; col_star++)
			{
				cout << "*";
			}
			cout << "\n";
		}
		
		// this if/else structure will check if the diamond is to be odd or even and run code that will do that.
		if (num_lines%2) {// this loop should handle the odd numbers for the lower triangle.
		
			for (row = (num_lines/2) ; row >= 1; row--)
			{
				for (col_space = 1; col_space <= (num_lines/2)-row; col_space++)
				{
					cout << " ";
				}
				for (col_star = 1; col_star <= (row*2)-1; col_star++) 
				{
					cout << "*";
				}
				cout << "\n";
			}
	    } else {
		
			// this loop should handle the even numbers for the lower triangle.
			for (row = (num_lines/2)-1; row >= 1; row--)
			{
				for (col_space = 1; col_space <= (num_lines/2)-row; col_space++)
				{
					cout << " ";
				}
				for (col_star = 1; col_star <= (row*2)-1; col_star++) 
				{
					cout << "*";
				}
				cout << "\n";
			}
		}
	} // end while loop
	cout<<"\nGoodbye for now.";
}//end main()
