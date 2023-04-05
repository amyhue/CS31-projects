// Project 6: Vacation Account Balance
// Name: Amy Hu

#ifndef BloodDonation_H
#define BloodDonation_H

#include <iostream>
#include <string>
using namespace std;

class BloodDonation {
	private:
		int mID;
		int mAge;
		double mWeight;

	public:
		BloodDonation(int EmployeeID, int EmployeeAge, double EmployeeWeight);

		int getID();
		void setID(int id);

		int getAge();
		void setAge(int age);

		double getWeight();
		void setWeight(double weight);
};

#endif
