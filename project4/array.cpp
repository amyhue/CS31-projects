// Project 4: String Arrays
// Name: Amy Hu

#include <iostream>
#include <cassert>
#include <string>

using namespace std;

// Checks if the given string is a floating point value that optionally includes a decimal point
bool isFloat(string maybeNum) {
	int deciCount = 0;
	int numCount = 0;
	bool deciBool = false;


	for (int i = 0; i < maybeNum.size(); i++) {
		// if the character is not a digit, we need to check if it is a decimal point
		// If it is a decimal point, we increase the deciCount by 1 so that deciCount == 1
		// If we come accross another decimal, the string is no longer a floating point value because it would have more than 1 decimal
		if (isdigit(maybeNum[i])) {
			numCount++; // counts how many digits are in the float
		}
		else {
			if (deciCount < 1 && maybeNum[i] == '.') deciCount++;
			else return false;
		}
		deciBool = true;
	}

	if (numCount < 1) deciBool = false; // if there is no digit in the string, it obviously is not a float

	return deciBool;
}

//Checks if if the given string has any capital letters
bool hasCaps(string mightHaveCaps) {
	for (int i = 0; i < mightHaveCaps.size(); i++) {
		if (isupper(mightHaveCaps[i])) return true;
	}
	return false;
}

//Required Functions

// finished function unless Piazza has new info
int locateMaximum(const string array[], int n) {
	string tempLargest = "";
	int indexMaximum = 0;

	// if n <=0, no point in running rest of code -- just terminate directly
	if (n <= 0) {
		return -1;
	}
	// Based on SPECS, we can assume that n < the array's size, so it will not trigger an out-of-bounds error
	for (int i = 0; i < n; i++){
		
		if (array[i] > tempLargest) {
			tempLargest = array[i];
			indexMaximum = i;
		}
		else continue;
	}

	return indexMaximum;

}

int countFloatingPointValues(const string array[], int  n) {
	int floatCounter = 0;
	
	// if n <=0, no point in running rest of code -- just terminate directly
	if (n <= 0) {
		return -1;
	}

	for (int i = 0; i < n; i++) {
		if (isFloat(array[i])){
			floatCounter++;
		}
		else continue;
	}
	return floatCounter;
}

bool hasNoCapitals(const string array[], int n) {
	// if n <=0, no point in running rest of code -- just terminate directly
	// This function probably doesn't need this if statement, but may as well keep for consistency with the other functions
	if (n <= 0) {
		return true;
	}

	for (int i = 0; i < n; i++) {
		if (hasCaps(array[i])) {
			return false;
		}
		else continue;
	}
	return true;
}

int shiftLeft(string array[], int n, int amount, string placeholder) {
	int placeholderCount = 0;
	// if n <=0 or amount < 0, no point in running rest of code -- just terminate directly
	if (n <= 0 || amount < 0) {
		return -1;
	}

	for (int i = 0; i < amount; i++) { // each loops moves the given array to the left one index
		for (int j = 0; j < n - 1; j++) { // j < n-1 to avoid potential out-of-bounds issues when j = n-1 based on the loop
			array[j] = array[j + 1];
		}
		array[n - 1] = placeholder; // replace the last value (index = n-1) in array with placeholder
		placeholderCount++;
	}

	if (n < amount) placeholderCount = n; 

	//cout << placeholderCount << endl; // *** DELETE LATER
	return placeholderCount;
}

int main() {


	// Test Cases

	string arr1[] = { "apple", "banana", "ch3rrieS", "Durian" };
	string arr2[] = { "001000", " 0", "11", "1.1", ".", "1,000", "-1" };
	string arr3[] = { "", "", "", "" };
	string arr4[] = { "fox", "fox", "fox", "fox", "fox", "fox" };
	string arr5[] = { "Apple", "banana", "ch3rries", "banana", "banana", "Durian", "ch3rries" };

	// locateMaximum function
	assert(locateMaximum(arr1, 4) == 2); // tests string comparison works (“D” < “c”)
	assert(locateMaximum(arr1, 2) == 1);  // tests function only considers the n-index subarray
	assert(locateMaximum(arr2, 7) == 2); // tests string comparison works for numbers
	assert(locateMaximum(arr3, 4) == 0); // tests empty strings in an array
	assert(locateMaximum({}, 0) == -1); // tests empty string array and n = 0
	assert(locateMaximum(arr4, 6) == 0); // tests repeating strings and locates smallest index for the max
	assert(locateMaximum(arr5, 7) == 2); // tests multiple repeating strings and locates smallest index for the max
	assert(locateMaximum(arr5, -7) == -1); // tests n < 0

	// countFloatingPointValues function
	assert(countFloatingPointValues(arr1, 4) == 0); // tests that even if there are numbers in the string, it does not mean floating point
	assert(countFloatingPointValues(arr2, 7) == 3); // tests generally works
	assert(countFloatingPointValues(arr2, 2) == 1); // tests function considers the n-index subarray and leading zeroes are okay
	assert(countFloatingPointValues({}, 0) == -1); // tests empty string array and n = 0
	assert(countFloatingPointValues(arr2, -10) == -1); // tests n < 0

	// hasNoCapitals function
	assert(hasNoCapitals(arr1, 4) == false); // has capitals
	assert(hasNoCapitals(arr1, 3) == false); // tests capital location doesn’t matter – if it has capital it is false
	assert(hasNoCapitals(arr1, 2) == true); // no capital
	assert(hasNoCapitals(arr1, 0) == true); // tests n = 0
	assert(hasNoCapitals(arr1, -10) == true); // tests n < 0
	assert(hasNoCapitals(arr2, 7) == true); // has no capitals b/c all numbers
	assert(hasNoCapitals(arr3, 4) == true); // empty string has no capitals
	assert(countFloatingPointValues({}, 0) == -1); // tests empty string array

	// shiftLeft function
	assert(shiftLeft(arr1, 4, 2, "fruits") == 2); // tests amount < n
	assert(shiftLeft(arr1, 4, 7, "fruits") == 4); // tests amount > n
	assert(shiftLeft(arr1, 4, 0, "fruits") == 0); // tests amount = 0
	assert(shiftLeft(arr1, 4, -1, "fruits") == -1); // tests amount < 0
	assert(shiftLeft(arr1, 0, 2, "fruits") == -1); // tests n = 0
	assert(shiftLeft(arr1, -1, 2, "fruits") == -1); // tests n < 0
	assert(shiftLeft(arr1, 3, 4, "fruits") == 3); // tests function only considers n-index
	assert(shiftLeft(arr4, 6, 3, "fox") == 3); // tests that if placeholder is in the array already, it doesn’t matter
	assert(shiftLeft({}, 0, 0, "") == -1); // tests empty string array



	/*string arr10[] = { "fox", "fox", "fox", "fox", "fox", "fox" };
	shiftLeft({}, 0, 0, "");*/

	/*int len = 6;
	for (int i = 0; i < len; i++) {
		cout << arr10[i] << ", ";
	}*/


	cerr << "All test cases have succeed" << endl;
	return 0;
}
