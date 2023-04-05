// Project 6: Vacation Account Balance
// Name: Amy Hu

#include <iostream>
#include <string>
#include "BloodDonation.h"

using namespace std;

// constructor
BloodDonation::BloodDonation(int EmployeeID, int EmployeeAge, double EmployeeWeight) {
	setID(EmployeeID);
	setAge(EmployeeAge);
	setWeight(EmployeeWeight);
}

// getter for ID
int BloodDonation::getID() {
	return mID;
}

// setter for ID with six digits -- if it does not have six digits, it is considered invalid
// Invalid IDs will have mID = -1 to indicate an invalid ID
// Assumes that the ID does not have leading zeros
// Will not properly set/fail to set IDs with leading zeros
void BloodDonation::setID(int id){
	int digitCount = 0;
	int tempID = id;
	while (tempID > 0) { // takes care of negative IDs as well
		tempID = tempID / 10;
		digitCount++;
	}
	if (digitCount == 6) // checks that the number of digits in the ID is 6
		mID = id;
	else
		mID = -1;
}

// getter for age
int BloodDonation::getAge() {
	return mAge;
}

// valid ages are from 21 to 65, inclusive
// invalid ages will set mAge as -1 to indicate an invalid age
void BloodDonation::setAge(int age) {
	if (age >= 21 && age <= 65)
		mAge = age;
	else
		mAge = -1;
}

// getter for weight
double BloodDonation::getWeight() {
	return mWeight;
}

// valid weights are from 101.00 to 280.00, inclusive
// invalid weights will set mWeight as -1 to indicate an invalid weight
void BloodDonation::setWeight(double weight) {
	if (weight >= 101.00 && weight <= 280.00)
		mWeight = weight;
	else
		mWeight = -1;
}
