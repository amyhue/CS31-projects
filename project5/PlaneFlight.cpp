// Project 5: Frequent Flyer Account
// Name: Amy Hu

#include <iostream>
#include <string>
#include "PlaneFlight.h"

using namespace std;

// constructor 
PlaneFlight::PlaneFlight(string passengerName, string fromCity, string toCity, double cost, double mileage) {
	setName(passengerName);
	if (fromCity != toCity) {
		setFromCity(fromCity);
		setToCity(toCity);
	}
	setCost(cost);
	setMileage(mileage);
}

// cost accessor
double PlaneFlight::getCost() {
	return mCost;
}

// cost setter or mutator
void PlaneFlight::setCost(double cost) {
	if (cost >= 0)
		mCost = cost;
	else
		mCost = -1; // for invalid cost amount
}

// mileage accessor
double PlaneFlight::getMileage() {
	return mMileage;
}

// mileage setter or mutator
void PlaneFlight::setMileage(double mileage) {
	if (mileage > 0)
		mMileage = mileage;
	else
		mMileage = -1; // for invalid mileage amount
}

// name accessor
string PlaneFlight::getName() {
	return mName;
}

// name setter or mutator
void PlaneFlight::setName(string name) {
	if (name != "")
		mName = name;
}

// From City accessor
string PlaneFlight::getFromCity() {
	return mFromCity;
}

// From City setter or mutator
void PlaneFlight::setFromCity(string from) {
	if (from != "" && from != mToCity)
		mFromCity = from;
}

// To City accessor
string PlaneFlight::getToCity() {
	return mToCity;
}

// To City setter or mutator
void PlaneFlight::setToCity(string to) {
	if (to != "" && to != mFromCity)
		mToCity = to;
}
