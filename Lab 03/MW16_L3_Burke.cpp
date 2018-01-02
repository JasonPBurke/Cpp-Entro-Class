/*
//  Author: Jason Burke;

//  Lab 3:  Create a Math Tutor sutable for 3rd graders that restricts the ansewers to 100 or less.
*/

#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main() {
	
	// This block seeds the rand() with the system time so it is different every time the program runs
	unsigned seed = time(0);
	srand(seed);
	
	cout<< "Welcome to the Math Tutor!  I will give you some math problems.  Try and solve them! (or enter -1 to quit)"<< endl;	
	cout<< "\nTry and solve the following problems.  I will give you feedback when you are done.\n"<<endl;
	
	int total_question_count = 0;// This and correct_counter are needed for the percent calc in main
	int correct_counter = 0;	 // so they needed to be available outside the while loop.
	bool sentinel = false;
	
		while(sentinel == false){
		
			int random_num_1 = rand()%101;// Generate a random value in range 0-100
			int random_num_2 = rand()%(101-random_num_1);// Generates a second rand_num that will not total over 100 when added to num_1

			cout<< random_num_1 << " + "<< random_num_2<< " = "; //Output the math problem
			int user_answer = 0;
			cin>> user_answer;
			
			int computed_answer = random_num_1 + random_num_2; 
			
			// This could be changed to decrement the correct_counter var.  this would eliminate the need for both counters.
			if(user_answer == computed_answer) {
				cout<< "Correct!\n"<< endl;
				correct_counter++;
				
			} else if(user_answer < 0) {
					sentinel = true;
					continue;
			} else {
				cout<< "Incorrect.\n"<< endl;
			}
			
			total_question_count++;
		}
	
	int percent = 100*correct_counter/total_question_count;// To convert to a percentage
	
	cout<<"\nYou got "<< correct_counter<< " question(s) correct and "<< total_question_count-correct_counter
		<< " question(s) wrong for a score of "<< percent<< "%."<<endl;
		
	if(percent > 70) {
		cout<< "Nice job!  You have studied well."<< endl;
	} else {
		cout<< "Looks like you need to study a little bit more."<< endl;
	}
	
	return 0;
}
