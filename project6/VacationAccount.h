// Project 6: Vacation Account Balance
// Name: Amy Hu

#ifndef VacationAccount_H
#define VacationAccount_H

#include <iostream>
#include <string>
#include "BloodDonation.h"
using namespace std;

class VacationAccount {
	private:
		int mID;
		double mBalance;

	public:
		VacationAccount(int EmployeeID);

		double getBalance();

		int getID();
		void setID(int id); // additional helper/setter function

		bool addVacationToAccount(BloodDonation donation);

};

#endif
