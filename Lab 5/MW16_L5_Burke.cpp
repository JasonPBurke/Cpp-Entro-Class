/*
//  Author: Jason Burke;
//  Course: COSC 1337 Summer 2016 MW16;
//  Instructor: Thayer
//  Lab 5: Write a program that reads population data from a file and displays it in a bar chart.  Allow for the file to be
           edited and still be read.

    This progran will read total population data with corresponding year from a file and display it in a horizontal bar chart.  the years will be
printed along the left side of the screen with the population for that year displayed as stars(*) following it.  It will work in such a 
manner so that file data can be added/removed and it will display all data found in the file.
*/
#include <iostream> // cin, cout, endl
#include <fstream>  // open, close, eof
using namespace std;

int main() {

	//const string infile_name = "People.txt";--This was giving me an error and I wasnt sure why.  The same error was happening with the simple IO program.
	ifstream inFile("People.txt");
	
	if(inFile) {
		
		cout<<"Hello There!\nI am built to display up-to-date population data, working in 20 year increments.\n"
			<<endl;
		cout<<"Here is a representation of the most recent population data: \n\n";

		int population = 0;

		// the outer while loop will perform all the actions we need for each item in the file.  Will close when reaches EOF.
		while(!inFile.eof()) {

			inFile>> population;
			static int year = 1900;
			
			if(inFile.eof()) break;

			int stars = population/1000;

			// This next part is drawing out the rows of stars.
			cout<< year<< " ";
			for(int columns = 0; columns<stars; columns++){
				cout<< "*";
			}			
			cout<<endl;
			year+=20;
		}//end while
		inFile.close();		
	} else {
		cout<<"Error Message";
	}
	return 0;
}
/*
Output:

Hello There!
I am built to display up-to-date population data, working in 20 year increments.

Here is a representation of the most recent population data:

1900 **
1920 ****
1940 *****
1960 *********
1980 **************
2000 ******************
2020 ************************
2040 **********

--------------------------------
*/
