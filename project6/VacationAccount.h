// Project 6: Vacation Account Balance
// Name: Amy Hu

#include <iostream>
#include <string>
#include <cassert>

#include "BloodDonation.h"
#include "VacationAccount.h"

using namespace std;

int main() {
	// Test Cases

	BloodDonation donor1(123456, 30, 120.02);
	BloodDonation donor2(12345, 21, 101.00);
	BloodDonation donor3(1234567, 65, 280.01);
	BloodDonation donor4(-123456, 66, 280.00);
	BloodDonation donor5(0, 0, 0);
	BloodDonation donor6(123456, 20, 100.99);

	BloodDonation donorModify1(123456, 30, 120.02);
	BloodDonation donorModify2(0, 0, 0);

	VacationAccount account1(123456);
	VacationAccount account2(123457);
	VacationAccount account3(12345);
	VacationAccount account4(1234567);
	VacationAccount account5(-123456);

	//Test BloodDonation class

	// Test .getID()
	assert(donor1.getID() == 123456); // valid ID
	assert(donor2.getID() == -1); // invalid ID - only 5 digits
	assert(donor3.getID() == -1); // invalid ID - only 7 digits
	assert(donor4.getID() == -1); // invalid ID - negative number
	assert(donor5.getID() == -1); // invalid ID - only 1 digit
	assert(donor6.getID() == 123456); // valid ID

	// Test .getAge()
	assert(donor1.getAge() == 30); // valid age
	assert(donor2.getAge() == 21); // valid age (inclusive of lower bound)
	assert(donor3.getAge() == 65); // valid age (inclusive of upper bound)
	assert(donor4.getAge() == -1); // invalid age (greater than upper bound)
	assert(donor5.getAge() == -1); // invalid age (less than lower bound)
	assert(donor6.getAge() == -1); // invalid age (less than lower bound)

	// Test .getWeight()
	assert(donor1.getWeight() == 120.02); // valid weight
	assert(donor2.getWeight() == 101.00); // valid weight (inclusive of lower bound)
	assert(donor3.getWeight() == -1); // invalid weight - above the upper limit by 0.01
	assert(donor4.getWeight() == 280.00); // valid weight (inclusive of upper bound)
	assert(donor5.getWeight() == -1); //invalid weight - below the lower limit
	assert(donor6.getWeight() == -1); // invalid weight - below the lower limit

	// Test BloodDonation setter functions

	// invalid setID parameter overwrites previously valid ID attribute
	donorModify1.setID(1234);
	assert(donorModify1.getID() == -1);
	// invalid setAge parameter overwrites previously valid age attribute
	donorModify1.setAge(101);
	assert(donorModify1.getAge() == -1);
	// invalid setWeight parameter overwrites previously valid weight attribute
	donorModify1.setWeight(100.99);
	assert(donorModify1.getWeight() == -1);

	// valid setID parameter overwrites previously invalid ID attribute
	donorModify2.setID(234567);
	assert(donorModify2.getID() == 234567);
	// valid setAge parameter overwrites previously invalid age attribute
	donorModify2.setAge(65);
	assert(donorModify2.getAge() == 65);
	// valid setWeight parameter overwrites previously invalid weight attribute
	donorModify2.setWeight(280.00);
	assert(donorModify2.getWeight() == 280.00);

	// ;-;

	// Test VacationAccount class

	// Test initial balance = 0, regardless if ID is valid or not
	assert(account1.getBalance() == 0); // valid ID
	assert(account2.getBalance() == 0); // valid ID
	assert(account3.getBalance() == 0); // invalid ID - 5 digits
	assert(account4.getBalance() == 0); // invalid ID - 7 digits
	assert(account5.getBalance() == 0); // invalid ID - negative number

	// Tests .getID() - should be -1 if not valid
	assert(account1.getID() == 123456); // valid ID
	assert(account2.getID() == 123457); // valid ID
	assert(account3.getID() == -1); // invalid ID - 5 digits
	assert(account4.getID() == -1); // invalid ID - 7 digits
	assert(account5.getID() == -1); // invalid ID - negative number

	// Tests .addVacationToAccount() - should add 4 to balance if valid ID and donation and do nothing else
	assert(account1.addVacationToAccount(donor1) == true); // valid account & donation & IDs match
	assert(account1.addVacationToAccount(donor2) == false); // invalid donation ID & IDs don’t match
	assert(account1.addVacationToAccount(donor3) == false); // invalid donation ID, Weight & IDs don’t match
	assert(account1.addVacationToAccount(donor4) == false); // invalid donation ID, Age & IDs don’t match
	assert(account1.addVacationToAccount(donor5) == false); // invalid donation ID, Age, Weight & IDs don’t match
	assert(account1.addVacationToAccount(donor6) == false); // invalid donation Age, Weight (although IDs match)

	assert(account2.addVacationToAccount(donor1) == false); // valid account & donation, but IDs don’t match
	assert(account3.addVacationToAccount(donor2) == false); // invalid account & donation have same ID stored (-1), but still not a valid addition

	// Check .addVacationToAccount() increases balance accordingly
	assert(account1.getBalance() == 4);
	account1.addVacationToAccount(donor1); // To check adds and not just replace with 4
	assert(account1.getBalance() == 8);
	assert(account2.getBalance() == 0);
	assert(account3.getBalance() == 0);


	cerr << "All test cases have succeed!" << endl;

	return 0;
}
