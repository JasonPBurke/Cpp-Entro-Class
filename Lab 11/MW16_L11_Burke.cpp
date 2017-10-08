/*
  Author:		   Jason Burke
  Assignment:      Lab 11
  Topic:           more on classes and objects
  File Name:       MW16_L11_Burke.cpp
  Course/Section:  COSC 1337
  Due Date:        7/21/2017
  Instructor:      Thayer
*/

/*
This program will ket the user enter a day of year (1-365) and will return the date for that day.  You can also 
enter a truncated version of the day (jan 1) and it will print out the full date.  This program will also let
you enter a date, and then iterate up and down, by five, printing out the dates for each iteration.
*/

#include <iostream>
#include <iomanip>
#include<stdio.h>
#include<array>

using namespace std;


class Day {
	private:
		int day_of_year;
		
	public:
		Day(int d_of_y=1);// constructor with default value
		Day(string month, int day);
		
		// the below arrays will be called with [1-12] to corrispond with the actual months in the year*****Theses need to be declared static and moved
		const static int arr_days_in_month [13];// = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		const static string arr_months_of_year [13];// ={" ", "january", "febuary", "march", "april", "may", "june", "july",
		                                      // "august", "september", "october", "november", "december"};
		                                     
		int get_day() {
			return day_of_year;
		}
		void set_day(int d_of_y = 1) {
			day_of_year = d_of_y;
		}
		void print();// My print member function
		
		// Overloaded pre/posfix operators
		Day operator++();
		Day operator++(int);
		Day operator--();
		Day operator--(int);		
};

///////// Static Member Function Definitions ////////

const int Day::arr_days_in_month [13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const string Day::arr_months_of_year [13] ={" ", "january", "febuary", "march", "april", "may", "june", "july",
		                                     "august", "september", "october", "november", "december"};

//// CONSTRUCTOR DEFINITION ////////

Day::Day(int d_of_y) {
	if(d_of_y>=1 && d_of_y<=365){
	day_of_year = d_of_y;
	} else {
		  int default_day =1;
		  cout<<"\n invalid day entered. Defaulting to day 1."<<endl;
		  day_of_year = default_day;
	}
}

////////  OVERLOADED CONSTRUCTOR DEFINITION ////////

Day::Day(string month, int day){
	
	int counter = 1;

	while(counter<sizeof(arr_months_of_year)){//sizeof(arr_months_of_year).size()
		if(day>arr_days_in_month[counter]  && month.substr(0, 3) == arr_months_of_year[counter].substr(0, 3) || day<=0){
			int default_day = 1;
	  	    cout<<"\n invalid day entered. Defaulting to jan 1."<<endl;
	  	    day_of_year = default_day;
	  	    break;
       	} 
		if(month.substr(0, 3) == arr_months_of_year[counter].substr(0, 3)){
			month = arr_months_of_year[counter];
			int day_count=0;
			for(int i =1; i<counter;){
				day_count += arr_days_in_month[--counter];
				//cout<< "day_count: "<<day_count<< endl;
				//cout<< "In for loop- days_in_month data for counter "<< counter<< ": "<< arr_days_in_month[counter]<<endl;
			}
			day_of_year = day_count+day;
			break;
		} else {
			if(counter==13){// change this value to reflect the array size.  no magic numbers!
				int default_day = 1;
		  	    cout<<"\n invalid month entered. Defaulting to jan 1."<<endl;
		  	    day_of_year = default_day;
		  	    break;	
			}
			
		}
		counter++;
		//cout<< "counter: "<< counter;
	}
}

//////// OVERLOADED PREFIX ++ OPERATOR   /////////

Day Day::operator++(){
	day_of_year ++;
	return *this;
}
//////// OVERLOADED POSTFIX ++ OPERATOR   /////////

Day Day::operator++(int){
	Day temp = *this;
	day_of_year ++;
	return temp;
}

//////// OVERLOADED PREFIX -- OPERATOR   /////////

Day Day::operator--(){
	day_of_year --;
	return *this;
}

//////// OVERLOADED POSTFIX -- OPERATOR   /////////

Day Day::operator--(int){
	Day temp = *this;
	day_of_year --;
	return temp;
}

////////  PRINT MEMBER FUNCTION DEFINITION /////////


void Day::print(){
	
  int temp_counter = arr_days_in_month[1];
  string month = " "; 
  int day = 0;
  
	
  for(int index = 1; day_of_year >= index; index++){ 
  
	if(day_of_year > temp_counter){//
	  temp_counter += arr_days_in_month[index+1];
 
	} else {

		month = arr_months_of_year[index];
		
		if(day_of_year <= arr_days_in_month[1] ){
			day = day_of_year;
		} else day = -(temp_counter - day_of_year - arr_days_in_month[index]); // not sure what i have done here, but it works
		
		const int current_year = 2017;
		string date = month + " " + to_string(day) + ", " + to_string(current_year);
		
		cout<< endl<<  " Day number: ["<< day_of_year<< "] "<< date<< endl;

		break;
	} 
  }
}



int main(){
	
	//Day my_day;
	char user_choice = 'z';
	do {
		cout<< "\noptions: d)ay [#d->m,d]; m)onth+day [m d->#d]; o)perator [+/-5]; q)uit: ";
		
		cin>> user_choice;
			if(toupper(user_choice) == 'D') {
			cout<< " Enter day of year number (-9 to quit): ";
			int day_num = 0;
			cin>> day_num;
			Day my_day(day_num);//***********
			my_day.print();
		}
		else if (toupper(user_choice) == 'M') {
			cout<< "\n Enter the month and day of month: (stop -9 to quit): ";
			string month = "zzz";
			int day = 0;
			cin>> month >> day; 
			Day my_day2(month, day);
			my_day2.print();
		}
		else if (toupper(user_choice) == 'O') {
			cout<< " Enter a month and day to start: ";
			string month ="zzz";
			int day = 0;
			cin>> month>> day;
			Day my_day3(month, day);
			cout<< "(use +/-5 days with --day, ++day, day++, day--):\n";
		    
		    
		    for(int i = 0; i<5; i++){
		      --my_day3;
			  my_day3.print();	
			}
		    
			for(int i = 0; i<5; i++){
		      ++my_day3;
			  my_day3.print();	
			}
			
			for(int i = 0; i<5; i++){
		      my_day3++;
			  my_day3.print();	
			}

			for(int i = 0; i<5; i++){
		      my_day3--;
			  my_day3.print();	
			}

		}
		else if (toupper(user_choice) == 'Q') break;
		else cout<<"Invalid entry. try again.\n";
		cin.clear();
		cin.ignore(1024, '\n');
		
		
	} while(user_choice != 'Q' && user_choice != 'q');
	cout<< "\nGoodBye"<<endl;
	
	return 0;
}

/*

options: d)ay [#d->m,d]; m)onth+day [m d->#d]; o)perator [+/-5]; q)uit: d
 Enter day of year number (-9 to quit): 366

 invalid day entered. Defaulting to day 1.

 Day number: [1] january 1, 2017

options: d)ay [#d->m,d]; m)onth+day [m d->#d]; o)perator [+/-5]; q)uit: 365
Invalid entry. try again.

options: d)ay [#d->m,d]; m)onth+day [m d->#d]; o)perator [+/-5]; q)uit: d
 Enter day of year number (-9 to quit): 365

 Day number: [365] december 31, 2017

options: d)ay [#d->m,d]; m)onth+day [m d->#d]; o)perator [+/-5]; q)uit: d
 Enter day of year number (-9 to quit): jul 23

 invalid day entered. Defaulting to day 1.

 Day number: [1] january 1, 2017

options: d)ay [#d->m,d]; m)onth+day [m d->#d]; o)perator [+/-5]; q)uit: d
 Enter day of year number (-9 to quit): 56

 Day number: [56] febuary 25, 2017

options: d)ay [#d->m,d]; m)onth+day [m d->#d]; o)perator [+/-5]; q)uit: m

 Enter the month and day of month: (stop -9 to quit): jul 23

 Day number: [204] july 23, 2017

options: d)ay [#d->m,d]; m)onth+day [m d->#d]; o)perator [+/-5]; q)uit: m

 Enter the month and day of month: (stop -9 to quit): dec 32

 invalid day entered. Defaulting to jan 1.

 Day number: [1] january 1, 2017

options: d)ay [#d->m,d]; m)onth+day [m d->#d]; o)perator [+/-5]; q)uit: o
 Enter a month and day to start: jul 1
(use +/-5 days with --day, ++day, day++, day--):

 Day number: [181] june 30, 2017

 Day number: [180] june 29, 2017

 Day number: [179] june 28, 2017

 Day number: [178] june 27, 2017

 Day number: [177] june 26, 2017

 Day number: [178] june 27, 2017

 Day number: [179] june 28, 2017

 Day number: [180] june 29, 2017

 Day number: [181] june 30, 2017

 Day number: [182] july 1, 2017

 Day number: [183] july 2, 2017

 Day number: [184] july 3, 2017

 Day number: [185] july 4, 2017

 Day number: [186] july 5, 2017

 Day number: [187] july 6, 2017

 Day number: [186] july 5, 2017

 Day number: [185] july 4, 2017

 Day number: [184] july 3, 2017

 Day number: [183] july 2, 2017

 Day number: [182] july 1, 2017

options: d)ay [#d->m,d]; m)onth+day [m d->#d]; o)perator [+/-5]; q)uit: o
 Enter a month and day to start: nov 30
(use +/-5 days with --day, ++day, day++, day--):

 Day number: [333] november 29, 2017

 Day number: [332] november 28, 2017

 Day number: [331] november 27, 2017

 Day number: [330] november 26, 2017

 Day number: [329] november 25, 2017

 Day number: [330] november 26, 2017

 Day number: [331] november 27, 2017

 Day number: [332] november 28, 2017

 Day number: [333] november 29, 2017

 Day number: [334] november 30, 2017

 Day number: [335] december 1, 2017

 Day number: [336] december 2, 2017

 Day number: [337] december 3, 2017

 Day number: [338] december 4, 2017

 Day number: [339] december 5, 2017

 Day number: [338] december 4, 2017

 Day number: [337] december 3, 2017

 Day number: [336] december 2, 2017

 Day number: [335] december 1, 2017

 Day number: [334] november 30, 2017

options: d)ay [#d->m,d]; m)onth+day [m d->#d]; o)perator [+/-5]; q)uit: q

GoodBye

--------------------------------
Process exited after 79.49 seconds with return value 0
Press any key to continue . . .
*/
