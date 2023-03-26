// Project Name: Sales Tax Payment Calculator
// Author: Amy Hu

#include <iostream>
#include <string>
using namespace std;

int main() {

	// Declare and initialize variables
	// User-inputted variables -- they are initialized as strange values so if something is wrong, the output should be obviously weird
	string stateName = "state";
	string month = "month";
	double purchaseAmount = 10000;
	int day = 10000;
	int year = 10000;

	// Other variables
	double stateTaxRate = 0.0;
	double avgLocalTaxRate = 0.0;
	double levy = 0.0;
	int freeTaxDayStart = 0;
	int freeTaxDayEnd = 0;
	string freeTaxMonth = "none";
	double paymentAmount = 0.0;

	// Gather inputs for the state name, purchase amount, month, day, year
	cout << "State Name: ";
	getline(cin, stateName);

	cout << "Purchase amount: ";
	cin >> purchaseAmount;
	cin.clear();
	cin.ignore(10000, '\n');

	cout << "Provide the month: ";
	getline(cin, month);

	cout << "Provide the day: ";
	cin >> day;
	cin.clear();
	cin.ignore(10000, '\n');

	cout << "Provide the year: ";
	cin >> year;
	cin.clear();
	cin.ignore(10000, '\n');

	// Check state and assign taxes based on given table
	// If date falls in the state's free tax date, set the taxes to 0.00
	// If the state has no free tax date, the taxes will be set according to the table
	// Since we cannot use functions, the states will keep their if-statements even if they have no free tax date
	// If the government suddenly wants to add a free tax date, this will allow for minimal edits and hopefully reduce the introduction of new, unintentional bugs
	// If state is not in the table, print "Invalid state" to terminal and end the program
	if (stateName == "Alabama") {
		freeTaxMonth = "July";
		freeTaxDayStart = 15;
		freeTaxDayEnd = 17;
		
		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.04;
			avgLocalTaxRate = 0.0514;
			levy = 0.00;
		}
	}
	else if (stateName == "Alaska") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.0143;
			levy = 0.00;
		}
	}
	else if (stateName == "Arizona") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.0560;
			avgLocalTaxRate = 0.0277;
			levy = 0.00;
		}
	}
	else if (stateName == "Arkansas") {
		freeTaxMonth = "August";
		freeTaxDayStart = 6;
		freeTaxDayEnd = 7;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.0650;
			avgLocalTaxRate = 0.0293;
			levy = 0.00;
		}
	}
	else if (stateName == "California") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.0725;
			avgLocalTaxRate = 0.0131;
			levy = 0.01;
		}
	}
	else if (stateName == "Colorado") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.0290;
			avgLocalTaxRate = 0.0473;
			levy = 0.00;
		}
	}
	else if (stateName == "Connecticut") {
		freeTaxMonth = "August";
		freeTaxDayStart = 21;
		freeTaxDayEnd = 27;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.0635;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
	}
	else if (stateName == "Delaware") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
	}
	else if (stateName == "Florida") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.06;
			avgLocalTaxRate = 0.0105;
			levy = 0.00;
		}
	}
	else if (stateName == "Georgia") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.04;
			avgLocalTaxRate = 0.0329;
			levy = 0.00;
		}
	}
	else if (stateName == "Hawaii") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.04;
			avgLocalTaxRate = 0.0041;
			levy = 0.00;
		}
	}
	else if (stateName == "Idaho") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.06;
			avgLocalTaxRate = 0.0003;
			levy = 0.00;
		}
	}
	else if (stateName == "Illinois") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.0625;
			avgLocalTaxRate = 0.0249;
			levy = 0.00;
		}
	}
	else if (stateName == "Indiana") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.07;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
	}
	else if (stateName == "Iowa") {
		freeTaxMonth = "August";
		freeTaxDayStart = 5;
		freeTaxDayEnd = 6;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.06;
			avgLocalTaxRate = 0.0082;
			levy = 0.00;
		}
	}
	else if (stateName == "Kansas") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.0650;
			avgLocalTaxRate = 0.0217;
			levy = 0.00;
		}
	}
	else if (stateName == "Kentucky") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.06;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
	}
	else if (stateName == "Louisiana") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.0445;
			avgLocalTaxRate = 0.05;
			levy = 0.00;
		}
	}
	else if (stateName == "Maine") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.055;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
	}
	else if (stateName == "Maryland") {
		freeTaxMonth = "August";
		freeTaxDayStart = 14;
		freeTaxDayEnd = 20;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.06;
			avgLocalTaxRate = 0.0143;
			levy = 0.00;
		}
	}
	else if (stateName == "Massachusetts") {
		freeTaxMonth = "August";
		freeTaxDayStart = 14;
		freeTaxDayEnd = 20;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.0625;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
	}
	else if (stateName == "Michigan") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.06;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
	}
	else if (stateName == "Minnesota") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.0688;
			avgLocalTaxRate = 0.0055;
			levy = 0.00;
		}
	}
	else if (stateName == "Mississippi") {
		freeTaxMonth = "July";
		freeTaxDayStart = 29;
		freeTaxDayEnd = 30;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.07;
			avgLocalTaxRate = 0.0007;
			levy = 0.00;
		}
	}
	else if (stateName == "Missouri") {
		freeTaxMonth = "April";
		freeTaxDayStart = 19;
		freeTaxDayEnd = 25;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.0423;
			avgLocalTaxRate = 0.039;
			levy = 0.00;
		}
	}
	else if (stateName == "Montana") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
	}
	else if (stateName == "Nebraska") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.0550;
			avgLocalTaxRate = 0.0135;
			levy = 0.00;
		}
	}
	else if (stateName == "Nevada") {
		freeTaxMonth = "August";
		freeTaxDayStart = 5;
		freeTaxDayEnd = 7;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.0685;
			avgLocalTaxRate = 0.0129;
			levy = 0.00;
		}
	}
	else if (stateName == "New Hampshire") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
	}
	else if (stateName == "New Jersey") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.0663;
			avgLocalTaxRate = -0.0003;
			levy = 0.00;
		}
	}
	else if (stateName == "New Mexico") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.0513;
			avgLocalTaxRate = 0.0269;
			levy = 0.00;
		}
	}
	else if (stateName == "New York") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.04;
			avgLocalTaxRate = 0.0449;
			levy = 0.00;
		}
	}
	else if (stateName == "North Carolina") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.0475;
			avgLocalTaxRate = 0.0222;
			levy = 0.00;
		}
	}
	else if (stateName == "North Dakota") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.05;
			avgLocalTaxRate = 0.0185;
			levy = 0.00;
		}
	}
	else if (stateName == "Ohio") {
		freeTaxMonth = "August";
		freeTaxDayStart = 5;
		freeTaxDayEnd = 7;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.0575;
			avgLocalTaxRate = 0.0142;
			levy = 0.00;
		}
	}
	else if (stateName == "Oklahoma") {
		freeTaxMonth = "August";
		freeTaxDayStart = 6;
		freeTaxDayEnd = 8;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.0450;
			avgLocalTaxRate = 0.0442;
			levy = 0.00;
		}
	}
	else if (stateName == "Oregon") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
	}
	else if (stateName == "Pennsylvania") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.06;
			avgLocalTaxRate = 0.0034;
			levy = 0.00;
		}
	}
	else if (stateName == "Rhode Island") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.07;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
	}
	else if (stateName == "South Carolina") {
		freeTaxMonth = "August";
		freeTaxDayStart = 5;
		freeTaxDayEnd = 7;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.06;
			avgLocalTaxRate = 0.0143;
			levy = 0.00;
		}
	}
	else if (stateName == "South Dakota") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.045;
			avgLocalTaxRate = 0.019;
			levy = 0.00;
		}
	}
	else if (stateName == "Tennessee") {
		freeTaxMonth = "July";
		freeTaxDayStart = 29;
		freeTaxDayEnd = 31;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.07;
			avgLocalTaxRate = 0.0247;
			levy = 0.00;
		}
	}
	else if (stateName == "Texas") {
		freeTaxMonth = "August";
		freeTaxDayStart = 5;
		freeTaxDayEnd = 7;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.0625;
			avgLocalTaxRate = 0.0194;
			levy = 0.00;
		}
	}
	else if (stateName == "Utah") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.0595;
			avgLocalTaxRate = 0.0099;
			levy = 0.0125;
		}
	}
	else if (stateName == "Vermont") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.06;
			avgLocalTaxRate = 0.0018;
			levy = 0.00;
		}
	}
	else if (stateName == "Virginia") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.0530;
			avgLocalTaxRate = 0.0035;
			levy = 0.01;
		}
	}
	else if (stateName == "Washington") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.0650;
			avgLocalTaxRate = 0.0267;
			levy = 0.00;
		}
	}
	else if (stateName == "West Virginia") {
		freeTaxMonth = "August";
		freeTaxDayStart = 5;
		freeTaxDayEnd = 7;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.06;
			avgLocalTaxRate = 0.0039;
			levy = 0.00;
		}
	}
	else if (stateName == "Wisconsin") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.05;
			avgLocalTaxRate = 0.0044;
			levy = 0.00;
		}
	}
	else if (stateName == "Wyoming") {
		freeTaxMonth = "none";
		freeTaxDayStart = 0;
		freeTaxDayEnd = 0;

		if (month == freeTaxMonth && (day >= freeTaxDayStart && day <= freeTaxDayEnd)) {
			stateTaxRate = 0.00;
			avgLocalTaxRate = 0.00;
			levy = 0.00;
		}
		else {
			stateTaxRate = 0.04;
			avgLocalTaxRate = 0.0136;
			levy = 0.00;
		}
	}
	else {
		cout << "Invalid state!" << endl;
		return 0;
	}

	// Check that purchase amount is greater than 0
	// If purchaseAmount less than 0, print "Invalid amount!" to terminal and end the program
	// Otherwise, do nothing
	if (purchaseAmount <= 0) {
		cout << "Invalid amount!" << endl;
		return 0;
	}

	// Check that the month is spelled correctly
	// If it is not, print "Invalid Month" to terminal and end the program
	// Otherwise do nothing
	// Use && because the month has to fail to match the given month values
	if (month != "January" 
		&& month != "February" 
		&& month != "March"
		&& month != "April"
		&& month != "May"
		&& month != "June"
		&& month != "July"
		&& month != "August"
		&& month != "September"
		&& month != "October"
		&& month != "November"
		&& month != "December") {
		cout << "Invalid month!" << endl;
		return 0;
	}

	// Check that the day is between 1 and 31
	// If it is less than 1 or greater than 31, print "Invalid day!" to terminal and end the program
	// Otherwise do nothing
	if (day < 1 || day > 31) {
		cout << "Invalid day!" << endl;
		return 0;
	}

	// Check that the year is between 1 and 2025
	// If it is less than 1 or greater than 2025, print "Invalid year!" to terminal and end the program
	// Otherwise do nothing
	if (year < 1 || year > 2025) {
		cout << "Invalid year!" << endl;
		return 0;
	}

	// If none of the inputs are invalid, calculate the payment amount
	paymentAmount = purchaseAmount + purchaseAmount*stateTaxRate + purchaseAmount*avgLocalTaxRate + purchaseAmount*levy;

	// outputs to 2 digits after the decimal point with cout
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	// print the total payment amount to the terminal to two decimal places
	cout << "Please pay a total of $" << paymentAmount << endl;
	
	return 0;
}