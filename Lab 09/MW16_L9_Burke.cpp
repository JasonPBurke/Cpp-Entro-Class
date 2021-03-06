/*
//  Author: Jason Burke;

//  Lab 9: Programming Challenge
*/
/*
This program compares different sort and search algorithms for speed/effeciency.  It will compare 3 sort 
algorithms (bubble, insertion, and selection sort), and two search algorithms (linear and binary). It will
output to the screen a visual grid with the algorithm name and how long it took to process on multiple sized
arrays created for the testing.
*/


#include <iostream>
#include <iomanip>
#include <random> // needed for Orwell devcpp

using namespace std;

const int TARGET = 123456789;
// This target value will never be found, because it
// is larger than any random number generated by rand().
// Do not find the target to test for worst-case performance.

// helper functions
void showArray(int[], int);
bool verifySorted(int[], int);

// Each selection sort below does the same algorithm. The
// difference is in how well it documents its operation.
void selectionSort(int[], int);
void selectionSortDescribed(int[], int);// not used
void selectionSortDescribedShowProgress(int[], int);
void selectionSortConcise(int[], int); // not used

// My new function headers.  Bubble sort, insertion sort, and binary search for an int array.
void bubbleSort(int[], int);//*************************--------------------------************************* 
void insertionSort(int[], int);//**************************--------------------------************************* 
int binarySearchArray(int[], int, int);//******************--------------------------************************* 

bool linearSearchArray(int [], int, int, int&);

const int testSizes[] = {1000, 5000, 10000, 20000, 30000, 40000, 50000, 0};

// This code helps to automate multiple test runs.

// Call this code as many times as desired to test your sort algorithms.
float testSortAlgorithm(void sortAlgorithm(int [], int), int array[], int arraySize) {
  // This is an interesting function. The first parameter is a "function pointer",
  // It accepts any function that returns a void and has parameters of type: (int [], int)
  // So, the first parameter (in the caller) can be the name of the sort function being tested.
  // This reduces redundant code, because the same sequence of tests are performed on each
  // sort function. (Our textbook does not mention function pointers.)
  
  // fill the array with random, unsorted numbers before sorting it
  for (int index = 0; index < arraySize; index++)
    array[index] = rand();  // initialize array with random values
  int startTime = clock(); // start the test clock
  sortAlgorithm(array, arraySize);  // ALGORITHM UNDER TEST
  int stopTime = clock();  // stop the test clock
  float duration = stopTime - startTime;
  if (!verifySorted(array, arraySize)) cout<< "Error! array not sorted!!!\n";
  return duration;
}

// Copy and/or reuse this code as desired to test your search algorithms.
float testLinearSearch(int array[], int arraySize) {
  bool found = false; // true if TARGET is found in array
  int foundAt = 0;    // index in array where TARGET was found
  int startTime = clock();
  for (int repeat = 0; repeat < 1000; repeat++) // repeat test 1000 times to increase duration
    found = linearSearchArray(array, arraySize, TARGET, foundAt); // ALGORITHM UNDER TEST
  int stopTime = clock();
  int duration = stopTime - startTime;
  return duration/1000.0; // divide duration by 1000 to get time for single search
}

float testBinarySearch(int array[], int arraySize) {
  int found = -1; // anything other than -1 is the position found in the array for the element
  int startTime = clock();
  for (int repeat = 0; repeat < 1000; repeat++) // repeat test 1000 times to increase duration
    found = binarySearchArray(array, arraySize, TARGET); // ***************************************************///// 
  int stopTime = clock();
  int duration = stopTime - startTime;
  return duration/1000.0; // divide duration by 1000 to get time for single search
}

void testAlgorithms(int array[], int arraySize) {
  // This draws a table of results for each algorithm tested.
  const int AlgorithmNameWidth=16;
  const int DurationWidth=10;
  cout << setw (AlgorithmNameWidth) << left << "Algorithm";
  for (int testCount=0; testSizes[testCount]; ++testCount)
    cout << setw(DurationWidth) << right << testSizes[testCount];
    cout << endl << string(AlgorithmNameWidth, '=');
  for (int testCount=0; testSizes[testCount]; ++testCount)
    cout << setw(DurationWidth) << right << " =======";
    
// Copy and/or reuse this code as desired to test your algorithms.
  cout << endl << setw (AlgorithmNameWidth) << left << "selection sort";
  for (int testCount=0; (testSizes[testCount] && testSizes[testCount] <= arraySize); ++testCount)
    cout << setw(DurationWidth) << right << testSortAlgorithm(selectionSort, array, testSizes[testCount]);
    // In the line above, I am passing the name of the function selectionSort as a parameter into
    // the function testSortAlgorithm. You can do the same thing for your sort algorithms, as long
    // as your sort algorithms return a void and have parameters: (int array[], int size).
   
  cout << endl << setw (AlgorithmNameWidth) << left << "linear search";
  for (int testCount=0; (testSizes[testCount] && testSizes[testCount] <= arraySize); ++testCount)
    cout << setw(DurationWidth) << right << testLinearSearch(array, testSizes[testCount]);
  cout << endl;
  
  
  // Add a loop to call and test your first sort algorithm here
  // Testing the bubble sort algorithm//***********************************************************************/////
  cout << endl << setw (AlgorithmNameWidth) << left << "bubble sort";
  for (int testCount=0; (testSizes[testCount] && testSizes[testCount] <= arraySize); ++testCount)
    cout << setw(DurationWidth) << right << testSortAlgorithm(bubbleSort, array, testSizes[testCount]);
    
  // Add a loop to call and test your second sort algorithm here
  // Testing the insertion sort function
  cout << endl << setw (AlgorithmNameWidth) << left << "insertion sort";
  for (int testCount=0; (testSizes[testCount] && testSizes[testCount] <= arraySize); ++testCount)
    cout << setw(DurationWidth) << right << testSortAlgorithm(insertionSort, array, testSizes[testCount]);
    
    
  // Add a loop to call and test your search algorithm here
  cout << endl << setw (AlgorithmNameWidth) << left << "binary search";
  for (int testCount=0; (testSizes[testCount] && testSizes[testCount] <= arraySize); ++testCount)
    cout << setw(DurationWidth) << right << testBinarySearch(array, testSizes[testCount]);
  cout<< endl<<endl;
    
}

// Useful test to verify that array is really sorted!
bool verifySorted(int array[], int size) {
  // returns true if array is in ascending sorted order, else false.
  for (int i=0; i<(size-1); ++i)
    if (array[i]>array[i+1]) return false;
  return true;
}

int main () {
  // the random number generator has to be "seeded" only once.
  unsigned int seed = time(0);
  srand(seed);

  // When first implementing your algorithm, you may want to test it
  // on a very small array. If so, uncomment the lines below.
  const int SMALLSIZE = 6;
  int smallArray[SMALLSIZE] = {5, 7, 2, 8, 9, 1}; // for testing purposes
 
  cout << "Optional testing of specific algorithms, prior to performance comparison table:\n\n";
  cout << "UNSORTED smallArray is: "; showArray(smallArray, SMALLSIZE);
  if (!verifySorted(smallArray, SMALLSIZE)) cout<< "Note: smallArray not sorted.\n";
  selectionSortDescribedShowProgress(smallArray, SMALLSIZE);
  cout << "SORTED   smallArray is: "; showArray(smallArray, SMALLSIZE);
  if (verifySorted(smallArray, SMALLSIZE)) cout<< "Note: smallArray is sorted.\n";

  // When first implementing your algorithm, you may want to test it
  // on a very small array. If so, try it on smallArray below.
  
  
  const int BIGSIZE = 50000;
  int bigArray[BIGSIZE];
  float duration = 0.0; // time in milliseconds

  // Do a single test run using the full size of bigArray
  duration = testSortAlgorithm(selectionSort, bigArray, BIGSIZE);
  cout << fixed << setprecision(2);
  
  cout << "\nSelection sort on bigArray took: "
       << setw(7) << duration << " milliseconds." << endl;
              
  duration = testSortAlgorithm(bubbleSort, bigArray, BIGSIZE);//*******************************************////////////////////
  cout << "Bubble  sort  on  bigArray took: "
       << setw(7) << duration << " milliseconds." << endl;
     
  duration = testSortAlgorithm(insertionSort, bigArray, BIGSIZE);//*******************************************////////////////////
  cout << "Insertion sort on bigArray took: "
       << setw(7)<< duration << " milliseconds." << endl;

  duration = testLinearSearch(bigArray, BIGSIZE);
  cout << "Linear search  of bigArray took: "
       << setw(7) << duration << " milliseconds."<<endl;
       
  duration = testBinarySearch(bigArray, BIGSIZE);//*******************************************////////////////////
  cout << "Binary search  of bigArray took: "
       << setw(7)<< duration << " milliseconds.\n" << endl;
       
       
  // Test the algorithms on ever longer list of numbers. Only one
  // array is needed.  Lengths of 1000, 5000, 10000, 20000, 30000,
  // 40000, 50000 are tested.
  testAlgorithms(bigArray, BIGSIZE);
  cout << endl;

  // system("pause");  // optional, commented out
  return 0;
} // end of main

//////////////////////////////////////////////
// Add your first sort algorithm in here

/********************************************\ // Bubble sort compares the first 2 array elements and swaps them if needed.  It then looks at the
             Bubble Sort Function              // second and third elements, with swaps if needed, then the third and fourth and so on. The largest
\********************************************/ // elements will 'bubble' to the 'top'(end) sorting the highest value to the right and moving left.

void bubbleSort(int array[], int arraySize){
	int tempHolder = 0;// to hold the value to be swapped during a swap.
	bool swapValues=false;//used to exit the do-while loop.
	
	do { 
	    swapValues = false;// kicks us out of the loop if set to false at end of each loop.
		for(int arraySubCount = 0; arraySubCount<(arraySize-1); arraySubCount++ ) {// iterate through the array subscripts until the end of 
																				   //the array (or no swaps happen).
			if(array[arraySubCount] > array[arraySubCount + 1]) {// compare 2 consceutive array values based on the for loop 
																 //above to see if the first one is greater.
				tempHolder = array[arraySubCount]; // if the first array element compaired is greater,  its value is stored in the tempHolder.
				array[arraySubCount] = array[arraySubCount+1];// then the second value is stored in the array position of the first value
				array[arraySubCount +1] = tempHolder;// finally, the tempHolder value(holding the original first value)
				 									 // is assigned to the second value's array spot.
				swapValues=true;// now that a swap occured, set swapValues to true to continue the loop 
								//until you cant swap anymore values(is now sorted).
			}
		}
	} while (swapValues);// keeps us in a loop as long as a swap has taken place in that loop pass.
}


// Add your second sort algorithm in here
/********************************************\  Insertion sort will effectively partition the array and will use the left side to hold the
             Insertion Sort Function            sorted values, while the right side contains the unsorted values.  We start with the first value
\*******************************************/// in the sorted pile, and we add the next item in the array, and sort in into place on the left. 
											 // The next time through we will start sorting at [1] instead of [0] and so on to the end of the array.
void insertionSort(int array[], int arraySize) {
	
	for (int sortedSubArrayIndex = 0; sortedSubArrayIndex < arraySize; sortedSubArrayIndex++){ // 
		int unsortedSubArrayIndex = sortedSubArrayIndex;// set the sorted and unsorted index values equal to each other.  this way, when we iterate
														// to sorted set, the program will start searching at the end of its new index value.
		int temp=-1;// used to hold the value to be swapped
		// The while loop is where the swap happens.  We go into the loop while the unsorted sub-array is greater than 0 and 
		while (unsortedSubArrayIndex > 0 && array[unsortedSubArrayIndex] < array[unsortedSubArrayIndex-1]){//
		  temp = array[unsortedSubArrayIndex];
		  array[unsortedSubArrayIndex] = array[unsortedSubArrayIndex-1];
		  array[unsortedSubArrayIndex-1] = temp;
		  unsortedSubArrayIndex--;// decrement the index so that the inner loop will eventually end(it will equal 0 and exit loop).
		  }
	}
} 

/********************************************\ // Binary search, used on a sorted array, checks the mid-point for the value desired, and if it's
             Binary Search Function            // not there, it will 'discard' from searching the side of the array that does not have our value.
\********************************************/ // We continue to chop the array until the mid-point is the value we were looking for.

int binarySearchArray(int array[], int arraySize, int wantedValue){
	// These set up the start, end and mid values we need for the binary search.  also gives us a variable to hold 
	// the [] position of the searched value, and a bool value to return from the function.
	int areaStartPoint = 0,
	    areaEndPoint = arraySize -1,
	    areaMidPoint = -1,
	    wantedValuePosition = -1;
	bool valueFound = false;
	
	while(!valueFound && areaStartPoint<=areaEndPoint) { // lets us search through the array while the value is not found and 
														 // while the start and end points are not equal. 
														 
		areaMidPoint = (areaStartPoint+areaEndPoint)/2;// finds the mid point, as an integer, to use in the loop.  gets a new value each loop.
		
		if(array[areaMidPoint] == wantedValue) {// check if the midpoint value is equal to the wanted value.
			valueFound = true;//  set valueFound to true if above true.  this will let us leave the loop.
			wantedValuePosition = areaMidPoint;// set the return value(wantedValuePosition) to the found value position now in areaMidPoint.
		}
		// this triggers if the wanted value is between the start of the search area and the midpoint.  It will chop the back half  
		// of the search area from the array, reseting the end-point to the old mid-point.
		else if(array[areaMidPoint] > wantedValue) {
			 areaEndPoint = areaMidPoint - 1;
		} 
		else areaStartPoint = areaMidPoint + 1; // this triggers if the wanted value is between the midpoint and the end of the search area.
	}											// It will chop the front half of the search area from the array, reseting the start to the 
												// old mid-point.
												
	return wantedValuePosition;// this will return the position of the wanted value in the array as an int.
}

//////////////////////////////////////////////

void showArray(int array[], int size) {
  for (int count = 0; count < size; count++)
    cout << setw(2) << array[count] << ' ';
  cout << endl;
}

// Your new search algorithm cannot be linear search, because it is provided here.
bool linearSearchArray(int a[], int s, int t, int &p) {
  // This is very terse, short, cryptic - not recommended!
  for (int i = 0; i < s; i++) if (a[i] == t) {p=i; return true;}
  p = -1;
  return false;
}

// Your new sort algorithm cannot be selection sort, because it is provided here.
// This is the selection sort from our textbook
void selectionSort(int array[], int size) {
  int startScan, minIndex, minValue;
  for (startScan = 0; startScan < (size - 1); startScan++) {
    minIndex = startScan;
    minValue = array[startScan];
    for (int index = startScan + 1; index < size; index++) {
      if (array[index] < minValue) {
        minValue = array[index];
        minIndex = index;
      }
    }
    array[minIndex] = array[startScan];
    array[startScan] = minValue;
  }
}

// This is selection sort described in more detail
void selectionSortDescribed(int array[], int size) {
  int minIndexSoFar = 0, minValueSoFar;
  for (int unsortedIndex = 0; unsortedIndex < (size - 1); unsortedIndex++) {
    // The outer loop looks at unsorted data, which is initially the whole array.
    // Gradually, a smaller and smaller portion of the array remains unsorted.
    minIndexSoFar = unsortedIndex;
    minValueSoFar = array[unsortedIndex];
    for (int seekMinIndex = unsortedIndex + 1; seekMinIndex < size; seekMinIndex++) {
      // the inner loop seeks the smallest value possible in the
      // remaining unsorted portion of the array.
      if (array[seekMinIndex] < minValueSoFar) {
        // found a smaller value than I had before, save it for now
        minValueSoFar = array[seekMinIndex];
        minIndexSoFar = seekMinIndex;
      }
    }
    // The smallest value in the unsorted portion of the array has been found.
    // Replace the older minimum value, which wasn't really the actual minimum
    // value, with the new, real minimum value which was just found.
    array[minIndexSoFar] = array[unsortedIndex];
    array[unsortedIndex] = minValueSoFar;
    // ... continue seeking the minimum value in the smaller remaining portion.
  }
}

// This is selection sort described in great detail
// It also shows the result of each pass of the outer loop.
void selectionSortDescribedShowProgress(int array[], int size) {
  int minIndexSoFar = 0, minValueSoFar;
  for (int unsortedIndex = 0; unsortedIndex < (size - 1); unsortedIndex++) {
    // The outer loop looks at unsorted data, which is initially the whole array.
    // Gradually, a smaller and smaller portion of the array remains unsorted.
    minIndexSoFar = unsortedIndex;
    minValueSoFar = array[unsortedIndex];
    for (int seekMinIndex = unsortedIndex + 1; seekMinIndex < size; seekMinIndex++) {
      // the inner loop seeks the smallest value possible in the
      // remaining unsorted portion of the array.
      if (array[seekMinIndex] < minValueSoFar) {
        // found a smaller value than I had before, save it for now
        cout << "  previous min value: " << minValueSoFar << " at offset: " << minIndexSoFar;
        minValueSoFar = array[seekMinIndex];
        minIndexSoFar = seekMinIndex;
        cout << "; found smaller value: " << minValueSoFar << " at offset: " << minIndexSoFar << endl;
      }
    }
    // The smallest value in the unsorted portion of the array has been found.
    // Replace the older minimum value, which wasn't really the actual minimum
    // value, with the new, real minimum value which was just found.
    array[minIndexSoFar] = array[unsortedIndex];
    array[unsortedIndex] = minValueSoFar;
    cout << "  swapped the previous minimum value: " << array[minIndexSoFar]
         << " with with new minimum value: " << array[unsortedIndex] << endl;
    cout << "After pass " << unsortedIndex << " the array looks like this: ";
    showArray(array, size);
    cout << endl;
    // ... continue seeking the minimum value in the smaller remaining portion.
  }
}

// This is a selection sort from a concise algorithm encyclopedia.
// As is, it is VERY CRYPTIC!
void selectionSortConcise(int array[], int size) {
  int i, idx, val;
  for (i = 0; i < (size - 1); i++) {
    idx = i;
    val = array[i];
    for (int j = i + 1; j < size; j++) {
      if (array[j] < val) {
        val = array[j];
        idx = j;
      }
    }
    array[idx] = array[i];
    array[i] = val;
  }
}

/*
Optional testing of specific algorithms, prior to performance comparison table:

UNSORTED smallArray is:  5  7  2  8  9  1
Note: smallArray not sorted.
  previous min value: 5 at offset: 0; found smaller value: 2 at offset: 2
  previous min value: 2 at offset: 2; found smaller value: 1 at offset: 5
  swapped the previous minimum value: 5 with with new minimum value: 1
After pass 0 the array looks like this:  1  7  2  8  9  5

  previous min value: 7 at offset: 1; found smaller value: 2 at offset: 2
  swapped the previous minimum value: 7 with with new minimum value: 2
After pass 1 the array looks like this:  1  2  7  8  9  5

  previous min value: 7 at offset: 2; found smaller value: 5 at offset: 5
  swapped the previous minimum value: 7 with with new minimum value: 5
After pass 2 the array looks like this:  1  2  5  8  9  7

  previous min value: 8 at offset: 3; found smaller value: 7 at offset: 5
  swapped the previous minimum value: 8 with with new minimum value: 7
After pass 3 the array looks like this:  1  2  5  7  9  8

  previous min value: 9 at offset: 4; found smaller value: 8 at offset: 5
  swapped the previous minimum value: 9 with with new minimum value: 8
After pass 4 the array looks like this:  1  2  5  7  8  9

SORTED   smallArray is:  1  2  5  7  8  9
Note: smallArray is sorted.

Selection sort on bigArray took: 3969.00 milliseconds.
Bubble  sort  on  bigArray took: 12023.00 milliseconds.
Insertion sort on bigArray took: 3532.00 milliseconds.
Linear search  of bigArray took:    0.16 milliseconds.
Binary search  of bigArray took:    0.00 milliseconds.

Algorithm             1000      5000     10000     20000     30000     40000     50000
================   =======   =======   =======   =======   =======   =======   =======
selection sort        1.00     40.00    161.00    627.00   1431.00   2550.00   3875.00
linear search         0.00      0.02      0.03      0.06      0.10      0.13      0.16

bubble sort           4.00    100.00    455.00   1874.00   4320.00   7682.00  12039.00
insertion sort        1.00     35.00    142.00    558.00   1292.00   2260.00   3558.00
binary search         0.00      0.00      0.00      0.00      0.00      0.00      0.00



--------------------------------
Process exited after 63.27 seconds with return value 0
Press any key to continue . . .
*/
