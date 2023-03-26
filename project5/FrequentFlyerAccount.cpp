// Project 5: Frequent Flyer Account
// Name: Amy Hu

#include <iostream>
#include <string>

#include "PlaneFlight.h"
#include "FrequentFlyerAccount.h"

using namespace std;

// constructor
FrequentFlyerAccount::FrequentFlyerAccount(string name) {
	mName = name;
	mBalance = 0; // since balance starts at 0 when we open a new account
}

// accessor
double FrequentFlyerAccount::getBalance() {
	return mBalance;
}

// accessor
string FrequentFlyerAccount::getName() {
	return mName;
}

bool FrequentFlyerAccount::addFlightToAccount(PlaneFlight flight) {
	if (flight.getName() == mName &&
		flight.getCost() > 0 &&
		flight.getFromCity() != flight.getToCity() &&
		flight.getFromCity() != "" &&
		flight.getToCity() != "" &&
		flight.getMileage() > 0) {
		mBalance = mBalance + flight.getMileage();
		return true;
	}
	else
		return false;
}

bool FrequentFlyerAccount::canEarnFreeFlight(double mileage) {
	if (mileage > 0 && mileage <= mBalance) // mileage parameter has to be less than mileage balance
		return true;
	else
		return false;
}

bool FrequentFlyerAccount::freeFlight(string from, string to, double mileage, PlaneFlight& flight) {
	if (from != to &&
		from != "" &&
		to != "" &&
		canEarnFreeFlight(mileage)) {
		PlaneFlight newFlight(mName, from, to, 0, mileage); // new plane flight, to avoid if from = mToCity and to = mFromCity
		flight = newFlight; // modify the original flight
		mBalance = mBalance - mileage;
		return true;
	}
	else
		return false;
}
