// Project 6: Vacation Account Balance
// Name: Amy Hu

#include <iostream>
#include <string>

#include "BloodDonation.h"
#include "VacationAccount.h"

using namespace std;

// constructor
VacationAccount::VacationAccount(int EmployeeID) {
	mBalance = 0;
	setID(EmployeeID);
}

// getter for balance
double VacationAccount::getBalance() {
	return mBalance;
}

// getter for ID
int VacationAccount::getID() {
	return mID;
}

// setter for ID with six digits -- if it does not have six digits, it is considered invalid
// Invalid IDs will have mID = -1 to indicate an invalid ID
// Assumes that the ID does not have leading zeros
// Will not properly set/fail to set IDs with leading zeros
void VacationAccount::setID(int id) {
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

// Checks if the employee gets 4 more hours for their donation
// If the donation is valid and matches the account ID, the balance increases by 4 hours
// and VacationAccount returns true to indicate the successful added vacation time
// Otherwise, the balance should be untouched and the function should return false 
bool VacationAccount::addVacationToAccount(BloodDonation donation) {
	if (mID == donation.getID() &&
		donation.getID() != -1 &&
		donation.getAge() != -1 &&
		donation.getWeight() != -1) {
		mBalance = mBalance + 4;
		return true;
	}
	else
		return false;
}
