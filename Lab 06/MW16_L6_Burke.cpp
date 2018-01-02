/*
//  Author: Jason Burke;

//  Lab 6: Write a program that uses 3 overloaded functions to ask for, calculate, and display the distance between
//  either 2 letters, 2 numbers in a range, or 2 (x,y) point sets.  
/*
This program is designed to take the value of 2 letters, numbers, or coordinate sets(x,y) and 
display the integer distance between them.  It will take advantage of overloaded functions, handle 
user entry errors, and allow the user to quit the program with ease.  The program will also show
the use of pass-by-refrence perameters, pass-by-value parameters, constant parameters, and default perameters.
The program uses static local variables to count the number of times each display function is called and 
displays it with the distance info to the user.
*/

#include <cmath>    // pow(a,b), sqrt(a,n)
#include <iostream> // cin, cout, endl, etc.
#include <iomanip>  // setw, setprecision, left, right, fixed, scientific, etc.
#include <string>   // good practice to include this, just in case (may need this for XCode)
using namespace std;

//functions
void display_menu();
// overloaded input 
char input(const string=" Enter a new letter:", const string=" Must enter a letter: ");// defining defualt input values
float input(const float, const float, string= "Enter a new number: ", string=" Must enter a number in the range (-100,100): ");// with defaults
void input(double &x, double &y, string=" Enter a point(x or y): ");// using pass-by-refrence variables
//overloaded dist
int dist(char, char);
float dist(float, float);
double dist(double, double, double, double);
//overloaded display
void display(const string, const char, const char,const int);// constant paramaters.
void display(const string, const float, const float, const float);// constant paramaters.
void display(const string, const double, const double, const double, const double, const double);// constant paramaters.

void clear_cin();// to help clean up the code, i put this in a function
void clear_screen();

int main() {
	//global constants
	//const string error_message = "  Something went wrong. Try again: ";//***this is my functions string error message.
	// This is not a const param.  Make some const params in the param list.

	while(true) {
		display_menu();
		char user_choice = 'z';
		cin>>user_choice;
		user_choice = tolower(user_choice);// Thanks for this, professor.
		const string error_message = "  Something went wrong. Try again: ";//***this is my functions string error message.
		
		if(user_choice == 'l') {
			//function calls for the letters;
			//char first_letter = input();// using the default messages only
			char first_letter = input("\n  Enter the first letter(a to z): ");// using one of the default values..this outputs default error msg
			//char first_letter = input("\n  Enter the first letter(a to z): ", error_message);// not using default values
			clear_cin();
			char second_letter = input("  Now the second letter(a to z): ", error_message);// this outputs the global const error msg
			int letter_distance = dist(first_letter, second_letter);
			display("  The Distance between letters ", first_letter, second_letter, letter_distance);
			clear_cin(); // avoiding a error when user entered >1 letter for the second letter.
		}				
		else if(user_choice == 'n') {
			//function calls for the numbers; 
			float first_num = input(-100, 100,"\n  Enter the first number(-100,100): ", error_message);
	     	//float second_num = input(-100,100,"  Enter the second number(-100,100): ", error_message);
	     	float second_num = input(-100,100);// usin all default values... kind of ugly output
	     	float num_distance= dist(first_num, second_num);
	     	display("  The number of digits between the numbers ", first_num, second_num, num_distance);
		}
		else if(user_choice == 'p') {
			//function calls for the points
			double x1=0, y1=0, x2=0, y2=0;// to store the 4 point values from the function.
			input(x1, y1, "\n  Enter the first point(x): ");//y value is asked for inside the function
			input(x2, y2, "\n  Enter the second point(x): ");
			double d = dist(x1, y1, x2, y2);
			display("  The straight line distance between point sets ", x1, y1, x2, y2, d);
		} 
		else if(user_choice == 'q') {
			cout<<"\n\n  Goodbye.\n\n";
			break;
		} else {
			cout<<endl<<error_message<<endl<<"  ";
			clear_cin();// clearing here to avoid user menu errors where they enter >1 letter with a trailing letter being a menu letter. eg"kl"
			clear_screen();
		}		
	}
	return 0;	
}

  /*********************************\
 *                                   *
*          Menu Function              * // Provide a simple menu for the user. 
 *                                   *
  \*********************************/ 
  
// This function clears the screen and then displays the menu options.
void display_menu() {
	cout<< "\nDisplay the distance between two items: letters, numbers, or points.\n\n";
	cout<< "  Options: l)etter; n)umber; p)oint; q)uit: ";
}

 /*********************************\
*                                   *
*		Letter Input Function        * // Ask for a letter, check it isalpha() and return letter if it is. else ask user again.
*                                   *
 \*********************************/

char input(string prompt, string error_message) {
		
	cout<< prompt;// this is my string prompt for the letter function call.
	char letter = 'z';
	cin>>letter;// want to put this in the while condition...

	while (!isalpha(letter)) { 
		cout<<error_message;//***this is my functions string error message.	
		clear_cin();
		cin>>letter;
	}
	return letter;
}

  /**********************************\
 *                                    *
*       Number Input Functon           * //Ask user for a number, check that it's within a range(else ask the user for it again), return the number.
 *                                    *
  \**********************************/

float input(float min, float max, string prompt, string error_message) { 
	
	cout<< prompt;
	float number = 0;
	cin>>number;
	
	while(number<min || number>max || cin.fail()) {   //can i use the 'or' or 'and' in place || or && 
		cout<<error_message;
		clear_cin();
		cin>>number;		
	}
	return number;
}

  /*********************************\
 *                                   *
*        Point Input Function         * // Get x and y point values.  No error checking and no range provided. Store new x/y values by reference.
 *                                   *  // Uses pass-by-reference to change 2 values
  \*********************************/

void input(double &x, double &y, string prompt) {
	static bool word_swap = true;
	cout<< prompt;
	cin>> x;
	string first_or_second_y = "first";
	
	if(!word_swap) {
		first_or_second_y = "second";
		word_swap = true;
	} else word_swap = false;
	cout<< "\n  Enter the "<<first_or_second_y<<" point(y): ";
	cin>> y;
}

  /*********************************\
 *                                   *
*      Letter Distance Function       * // Take 2 letters and calculate the integer distance between them. Return distance value.
 *                                   *
  \*********************************/

int dist(char a, char b) {
	int distance = abs(toupper(a)-toupper(b));
	return distance;
}

  /**********************************\
 *                                    *
*      Number Distance Function        * // take 2 numbers within a range and calculate 
 *                                    *  // how many digits apart they are.  return that value
  \**********************************/
  
float dist(float f1, float f2) {
	float d = 0;
	if(f1>f2) {
		d = f1-f2;
	} else d = f2-f1;
	//display("  The distance between the numbers ", f1, f2, d); *edit: wasnt sure if calling the display function here was good practice.
	return d;
}

  /**********************************\
 *                                    *
*       Point Distance Function        * // Find the distance between two user inputed point sets on a graph with no error checks or input ranges. 
 *                                    *  // Did not use pow() due to only raising to the power of 2. Would use pow() for power of 3 and up.
  \**********************************/   // Return the distance found
  
double dist(double x1, double y1, double x2, double y2) {
	
	double distance_x = (x2-x1) * (x2-x1); // calculate distance between the x values
	double distance_y = (y2-y1) * (y2-y1); // calculate distance between the y values
	double distance = sqrt(distance_x + distance_y); // calculate the distance between the point sets
	return distance;
}

  /**********************************\
 *                                    *
*       Letter Display Function        * // Takes a message, the 2 letters, and the distance between them and displays it on screen.
 *                                    *
  \**********************************/
  
void display(string msg, char ch1, char ch2, int d) {
	static int call_count = 0;
	call_count++;
	cout<<"\nCall #"<<call_count<< endl<< msg<< ch1<< " and "<< ch2<< " is: "<< d<<endl<<"  ";
	clear_screen();	
}  
  
  /**********************************\
 *                                    *
*       Number Display Function        * // Takes a message, the 2 numbers, and the distance between them and displays it on screen.
 *                                    *
  \**********************************/
  
void display(string msg, float f1, float f2, float d) {
	static int call_count = 0;
	call_count++;
	cout<< "\nCall #"<< call_count<< endl<< msg<< f1<< " and "<< f2<< " is: "<<d<<endl<<"  "; 
	clear_screen();
}
  
  /**********************************\
 *                                    *  // Takes a message, the 2 point sets, and the distance between them and displays it on screen.
*        Point Display Function        * // could add setprecision(2)...not sure if we want to though
 *                                    *
  \**********************************/
  
void display(string msg, double x1, double y1, double x2, double y2, double d) {
	static int call_count = 0;
	call_count++;
	cout<<"\nCall #"<<call_count<< endl<< msg<<'('<< x1<< ','<< y1<< ") and ("<< x2<< ','<< y2<< ") is "<< d<< endl<<"  ";
	clear_screen();
}



  /**********************************\
 *                                    *
*        Clear cin Function            * // This function is to group code that clears the cin into a one line function call.
 *                                    *
  \**********************************/
  
void clear_cin() {
	cin.clear();
	cin.ignore(1000,'\n');
}

  /**********************************\
 *                                    *
*        Clear Screen Function         * // This function groups the code to pause and then clear screen into a one line function call.
 *                                    *
  \**********************************/
  
void clear_screen() {
	system("pause");
	system("cls");
}	
/*

Display the distance between two items: letters, numbers, or points.

  Options: l)etter; n)umber; p)oint; q)uit: L

  Enter the first letter(a to z): a
  Now the second letter(a to z): g

Call #1
  The Distance between letters a and g is: 6
  Press any key to continue . . .
  

Display the distance between two items: letters, numbers, or points.

  Options: l)etter; n)umber; p)oint; q)uit: N

  Enter the first number(-100,100): 120
  Something went wrong. Try again: 100
Enter a new number: -40

Call #1
  The number of digits between the numbers 100 and -40 is: 140
  Press any key to continue . . .


Display the distance between two items: letters, numbers, or points.

  Options: l)etter; n)umber; p)oint; q)uit: P

  Enter the first point(x): 11

  Enter the first point(y): 22

  Enter the second point(x): 33

  Enter the second point(y): 44

Call #2
  The straight line distance between point sets (11,22) and (33,44) is 31.1127
  Press any key to continue . . .
  

Display the distance between two items: letters, numbers, or points.

  Options: l)etter; n)umber; p)oint; q)uit: l

  Enter the first letter(a to z): 3
 Must enter a letter: 6
 Must enter a letter: r
  Now the second letter(a to z): 4
  Something went wrong. Try again: 8
  Something went wrong. Try again: u

Call #2
  The Distance between letters r and u is: 3
  Press any key to continue . . .
  
Display the distance between two items: letters, numbers, or points.

  Options: l)etter; n)umber; p)oint; q)uit: q


  Goodbye.


--------------------------------
Process exited after 183.1 seconds with return value 0
Press any key to continue . . .
*/
