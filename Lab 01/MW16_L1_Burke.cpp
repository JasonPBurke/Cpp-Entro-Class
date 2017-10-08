/*
//  Author: Jason Burke;
//  Course: COSC 1337 Summer 2016 MW16;
//  Instructor: Thayer
//  Lab 1:  Calculate restaurant bill and / or BMI.
*/
#include <iostream>
using namespace std;

void tip_calculator();// I am going to be creating 2 functions to perform the bill/BMI calculations.  
void bmi_calculator();// The function bodies will be after main(), so im putting hedders here to alert the compiler
					  // to their existence. 

int main()
{
	cout << "Good evening!  I can calculate your resturant bill with tip, or I can\n";
	cout << "calculate your current BMI.  Please enter 'a' if you want to calculate your\n";
	cout << "resturant bill.  Enter 'b' if you want to calculate your BMI. \n\n";

	while (true)// this will let us enter the loop and the only way out is through the 'break' using 'q'.
	{
		cout << "------------------------------------------\n";// The following is the user menu.
		cout << "Enter 'a' or 'b' now or enter 'q' to quit: ";
		char user_choice;
		cin >> user_choice;
		
		if (user_choice == 'a' or user_choice == 'A') // ignoring case
		{
			cout << "\nGreat!  Let's calculate that resturant bill.";
			tip_calculator();
		}
		else if (user_choice == 'b' or user_choice == 'B')// ignoring case
		{
			cout << "\nNo problem!  Time to calculate your BMI.";
			bmi_calculator();
		}
		else if (user_choice == 'q' or user_choice == 'Q')// ignoring case
		{
			cout << "\nGoodbye for now.";// Goodbye message.
			break; // this is our exit from the loop.
		}
		else
		{
			cout << "\nThat was not a valid choice.\n\n";// error message. Loop then repeats.
		}
	}
		
	return 0;
}// end main()

void tip_calculator()// This function will calculate a bill including tip based on a tip percentage.  The tax rate is a constant.
{
	cout << "\nPlease enter the cost of the meal: $"; 
	double food_cost = 0.0;
	cin >> food_cost;
	
		
	if(food_cost)
	{
		cout << "\nPlease enter the percentage you would like to tip: ";
		double tip_percent = 0.0;
		cin >> tip_percent;
		
		if(tip_percent)
		{
			const double tax_rate = 0.0825;
			double total_no_tip = (tax_rate*food_cost) + food_cost;
			cout  << "\nYour total before tip is: $";
			printf ("%.2f", total_no_tip);
			double tip_ammount = (tip_percent/100) * total_no_tip;
			cout << "\nYour total after tip comes to: $";
			printf ("%.2f", (tip_ammount + total_no_tip));// Format BMI output to two decimals.
			cout << "\n\n"; // The tip is to be calculated including the tax amount.  The reason for this choice is
			// due to waitstaff earning around $2.17 per hour.  Without tips, they can't keep their lights on!!
		}// end if(tip_percent)
		else
		{
			cout << "Invalid entry.  Goodbye.";
			
		}
	}// end if(food_cost)
	else
	{
		cout << "Not a valid tip percentage.  Goodbye.";
	}
}

void bmi_calculator() // This function will ask for height (in feet/inches) and weight and then calculate the BMI.
{
	int ht_feet = 0.0;
	int ht_inches = 0.0;
	int total_height = 0.0;
	int weight_in_lbs;
	
	cout << "\nEnter your height and weight and I will calculate your BMI for you!\n";
	cout << "\nPlease enter your height in feet and inches now: \n";
	cout << "Feet: ";
	cin >> ht_feet;
	cout << "So you are " << ht_feet << " feet tall and how many inches? ";
	cin >> ht_inches;
	total_height = (ht_feet*12) + ht_inches;
	
	cout << "\nGreat! now enter your weight in pounds: ";
	cin >> weight_in_lbs;
	
	//double bmi = (weight_in_lbs/(height*height)) * 703; cant get this to work so im gonna try it another way
	double height_squared = total_height*total_height;
	double bmi = (weight_in_lbs/height_squared)*703; // this works.  Leaving the above so I can as about what I did wrong there.
	
	cout << "\nOK!  Here we go.  Your BMI is: ";
	printf ("%.2f", bmi);// Format BMI output to two decimals.
	cout <<".  Good Job!\n\n";
}


/*
Good evening!  I can calculate your resturant bill with tip, or I can
calculate your current BMI.  Please enter 'a' if you want to calculate your
resturant bill.  Enter 'b' if you want to calculate your BMI.

------------------------------------------
Enter 'a' or 'b' now or enter 'q' to quit: a

Great!  Let's calculate that resturant bill.
Please enter the cost of the meal: $100

Please enter the percentage you would like to tip: 20

Your total before tip is: $108.25
Your total after tip comes to: $129.90

------------------------------------------
Enter 'a' or 'b' now or enter 'q' to quit: b

No problem!  Time to calculate your BMI.
Enter your height and weight and I will calculate your BMI for you!

Please enter your height in feet and inches now:
Feet: 5
So you are 5 feet tall and how many inches? 6

Great! now enter your weight in pounds: 165

OK!  Here we go.  Your BMI is: 26.63.  Good Job!

------------------------------------------
Enter 'a' or 'b' now or enter 'q' to quit: q

Goodbye for now.
*/
