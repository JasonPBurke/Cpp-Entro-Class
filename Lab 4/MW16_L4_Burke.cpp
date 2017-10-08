/*
//  Author: Jason Burke;
//  Course: COSC 1337 Summer 2016 MW16;
//  Instructor: Thayer
//  Lab 4: Write a program that displays a menu allowing the user to select air, water, or steel (and a distance) and then
//         display the amount of time it will take for the sound wave to travel that distance in that medium.
*/
/*
This program will display the time, in seconds, that it takes for a sound wave to travel through various 
mediums.  A menu will be presented to the user to choose from different materials through which to make
the calculation.  It will handle invalid user entrys in a graceful manner.
*/
#include <iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;

int main() {
	
	cout<< "\nThis program will tell you how many seconds it takes a sound wave \n"<<
			"to travel through different mediums given a specific distance."<< endl;
	
	bool sentinel = false;	
		
	while(sentinel == false) {
		
		enum material {air='a', water='w', steel='s', quit='q'};
				
		// This is the user menu
		cout<< "\nWhat material would you like to use?\n"<<endl;
		cout<< "enter 'a' for air\n";
		cout<< "enter 'w' for water\n";
		cout<< "enter 's' for steel\n";
		cout<< "enter 'q' to quit\n";
		cout<< "\nChoice: ";
		
		char user_selection = 'z';
		cin>> user_selection;
		int distance = -0;// This is used in the switch statement so must stay outside the if statement below.
		// This loop allows the user to quit after the menu without seeing another question.
		if(user_selection == 'q') {
			
		} else if(user_selection == 'a' or user_selection == 'w' or user_selection == 's') {
			
			cout<< "\nOk.  Now tell me how many feet the sound wave is traveling (-1 to quit): ";
			cin>> distance;
			if(distance == -1) {
				sentinel = true;
				continue;
			}
			// This while loop will force entry of a positive integer.
			while(distance <0) {
				cout<< "That is an invalid distance.  Please enter a positive integer now (-1 to quit): ";
				cin>> distance;
				if(distance == -1) {
				sentinel = true;
				break;
				}
			}
		
		} else {
			cout<<"\nThat is an invalid entry.  Try again.\n"<<endl;// Displays after an invalid entry at menu
		}
		double speed = 0.0000;
		// This switch statement calculates the time in seconds for each material.  It also uses
		// setprecision() to set precision to 4 decimals.  
		if(user_selection > 0 && distance > 0 || user_selection == 'q') {
			switch(user_selection) {
			
			case air:	speed = 1100;// ft per second
						cout<< "\nIt will take "<<setprecision(4)<<fixed<<distance/speed << " seconds for a sound wave to travel "<< distance<< " feet through air."<< endl;
						break;
			case water: speed = 4900;// feet per second
						cout<< "\nIt will take "<<setprecision(4)<<fixed<<distance/speed << " seconds for a sound wave to travel "<< distance<< " feet through water."<< endl;;
						break;
			case steel: speed = 16400;// feet per second
						cout<< "\nIt will take "<<setprecision(4)<<fixed<<distance/speed << " seconds for a sound wave to travel "<< distance<< " feet through steel."<< endl;
						break;
			case quit:	sentinel = true;
						break;
			}
		}
	}	
	cout<<"\nGoodbye for now\n";	
	return 0;
}// end main()
/*
This program will tell you how many seconds it takes a sound wave
to travel through different mediums given a specific distance.

What material would you like to use?

enter 'a' for air
enter 'w' for water
enter 's' for steel
enter 'q' to quit

Choice: a

Ok.  Now tell me how many feet the sound wave is traveling: 23456456

It will take 21324.0509 seconds for a sound wave to travel 23456456 feet through air.

What material would you like to use?

enter 'a' for air
enter 'w' for water
enter 's' for steel
enter 'q' to quit

Choice: w

Ok.  Now tell me how many feet the sound wave is traveling: 234566

It will take 47.8706 seconds for a sound wave to travel 234566 feet through water.

What material would you like to use?

enter 'a' for air
enter 'w' for water
enter 's' for steel
enter 'q' to quit

Choice: s

Ok.  Now tell me how many feet the sound wave is traveling: 234566

It will take 14.3028 seconds for a sound wave to travel 234566 feet through steel.

What material would you like to use?

enter 'a' for air
enter 'w' for water
enter 's' for steel
enter 'q' to quit

Choice: q

Goodbye for now.




This program will tell you how many seconds it takes a sound wave
to travel through different mediums given a specific distance.

What material would you like to use?

enter 'a' for air
enter 'w' for water
enter 's' for steel
enter 'q' to quit

Choice: e

That is an invalid entry.  Try again.


What material would you like to use?

enter 'a' for air
enter 'w' for water
enter 's' for steel
enter 'q' to quit

Choice: a

Ok.  Now tell me how many feet the sound wave is traveling: -344556
That is an invalid distance.  Please enter a positive integer now: -2345
That is an invalid distance.  Please enter a positive integer now: 34567

It will take 31.4245 seconds for a sound wave to travel 34567 feet through air.

What material would you like to use?

enter 'a' for air
enter 'w' for water
enter 's' for steel
enter 'q' to quit

Choice: q

Goodbye for now.
*/
