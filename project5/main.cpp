// Project 5: Frequent Flyer Account
// Name: Amy Hu

#include <iostream>
#include <cassert>
#include <string>

#include "PlaneFlight.h"
#include "FrequentFlyerAccount.h"

using namespace std;

int main() {

    // Test cases

    PlaneFlight flight1("Amy Hu", "LAX", "JFK", 100.00, 2829);
    PlaneFlight flight2("", "LAX", "JFK", 100.00, 2829);
    PlaneFlight flight3("Amy Hu", "", "", 100.00, 2829);
    PlaneFlight flight4("Amy Hu", "", "JFK", 100.00, 2829);
    PlaneFlight flight5("Amy Hu", "LAX", "", 100.00, 2829);
    PlaneFlight flight6("Amy Hu", "LAX", "LAX", 100.00, 2829);
    PlaneFlight flight7("Amy Hu", "LAX", "JFK", -100.00, 2829);
    PlaneFlight flight8("Amy Hu", "LAX", "JFK", 0, 2829);
    PlaneFlight flight9("Amy Hu", "LAX", "JFK", 100.00, 0);
    PlaneFlight flight10("Amy Hu", "LAX", "LAX", 100.00, -10);

    PlaneFlight flightModify1("Amy Hu", "LAX", "JFK", 100.00, 2829);
    // PlaneFlight flightModify2("Amy Hu", "LAX", "LAX", 100.00, -10);
    // PlaneFlight flightModify3("Amy Hu", "LAX", "JFK", 0, 2829);

    FrequentFlyerAccount account1("Amy Hu");
    // FrequentFlyerAccount account2("Amy");

    // Testing PlaneFlight class attributes/operations

    // flight1("Amy Hu", "LAX", "JFK", 100.00, 2829) - tests PlaneFlight object with valid parameters
    assert(flight1.getName() == "Amy Hu");
    assert(flight1.getFromCity() == "LAX");
    assert(flight1.getToCity() == "JFK");
    assert(flight1.getCost() == 100.00);
    assert(flight1.getMileage() == 2829);

    // flight2("", "LAX", "JFK", 100.00, 2829) - tests PlaneFlight object with invalid passengerName (empty string)
    assert(flight2.getName() == "");
    assert(flight2.getFromCity() == "LAX");
    assert(flight2.getToCity() == "JFK");
    assert(flight2.getCost() == 100.00);
    assert(flight2.getMileage() == 2829);

    // tests PlaneFlight with invalid fromCity and toCity
    // flight3("Amy Hu", "", "", 100.00, 2829) - fromCity is empty
    assert(flight3.getName() == "Amy Hu");
    assert(flight3.getFromCity() == "");
    assert(flight3.getToCity() == "");
    assert(flight3.getCost() == 100.00);
    assert(flight3.getMileage() == 2829);

    // flight4("Amy Hu", "", "JFK", 100.00, 2829) - fromCity is empty
    assert(flight4.getName() == "Amy Hu");
    assert(flight4.getFromCity() == "");
    assert(flight4.getToCity() == "JFK");
    assert(flight4.getCost() == 100.00);
    assert(flight4.getMileage() == 2829);

    // flight5("Amy Hu", "LAX", "", 100.00, 2829) - toCity is empty
    assert(flight5.getName() == "Amy Hu");
    assert(flight5.getFromCity() == "LAX");
    assert(flight5.getToCity() == "");
    assert(flight5.getCost() == 100.00);
    assert(flight5.getMileage() == 2829);

    // flight6("Amy Hu", "LAX", "LAX", 100.00, 2829) - fromCity and toCity are the same
    assert(flight3.getName() == "Amy Hu");
    assert(flight6.getFromCity() == "");
    assert(flight6.getToCity() == "");
    assert(flight6.getCost() == 100.00);
    assert(flight6.getMileage() == 2829);

    // flight7("Amy Hu", "LAX", "JFK", -100.00, 2829) - tests invalid cost < 0
    assert(flight7.getName() == "Amy Hu");
    assert(flight7.getFromCity() == "LAX");
    assert(flight7.getToCity() == "JFK");
    assert(flight7.getCost() == -1);
    assert(flight7.getMileage() == 2829);


    // flight8("Amy Hu", "LAX", "JFK", 0, 2829) - tests the valid cost = 0
    assert(flight8.getName() == "Amy Hu");
    assert(flight8.getFromCity() == "LAX");
    assert(flight8.getToCity() == "JFK");
    assert(flight8.getCost() == 0);
    assert(flight8.getMileage() == 2829);

    // flight9("Amy Hu", "LAX", "JFK", 100.00, 0) - tests invalid mileage = 0
    assert(flight9.getName() == "Amy Hu");
    assert(flight9.getFromCity() == "LAX");
    assert(flight9.getToCity() == "JFK");
    assert(flight9.getCost() == 100.00);
    assert(flight9.getMileage() == -1);

    // flight10("Amy Hu", "LAX", "LAX", 100.00, -10) - tests multiple invalid inputs (fromCity = toCity, mileage < 0)
    assert(flight10.getName() == "Amy Hu");
    assert(flight10.getFromCity() == "");
    assert(flight10.getToCity() == "");
    assert(flight10.getCost() == 100.00);
    assert(flight10.getMileage() == -1);

    // ;-;

    // flightModify1("Amy Hu", "LAX", "JFK", 100.00, 2829)
    // Tests that inputting invalid parameters will NOT modify the PlaneFlight object

    flightModify1.setName(""); // empty string
    assert(flightModify1.getName() == "Amy Hu");

    flightModify1.setFromCity(""); // empty string
    assert(flightModify1.getFromCity() == "LAX");

    flightModify1.setFromCity("JFK"); // same as the flight’s associated mToCity
    assert(flightModify1.getFromCity() == "LAX");

    flightModify1.setToCity(""); // empty string
    assert(flightModify1.getToCity() == "JFK");

    flightModify1.setToCity("LAX"); // same as the flight’s associated mFromCity
    assert(flightModify1.getToCity() == "JFK");

    flightModify1.setCost(-200); // cost < 0
    assert(flightModify1.getCost() == -1);

    flightModify1.setMileage(0); // mileage = 0
    assert(flightModify1.getMileage() == -1);

    flightModify1.setMileage(-100); // mileage < 0
    assert(flightModify1.getMileage() == -1);

    // ;-;

    // flightModify1("Amy Hu", "LAX", "JFK", 100.00, 2829)
    // should become flightModify1("AH", "LAS", "LGA", 200, 100) after modifications
    // Tests that inputting valid parameters will modify the PlaneFlight object
    flightModify1.setName("AH");
    assert(flightModify1.getName() == "AH");

    flightModify1.setFromCity("LAS");
    assert(flightModify1.getFromCity() == "LAS");

    flightModify1.setToCity("LGA");
    assert(flightModify1.getToCity() == "LGA");

    flightModify1.setCost(200);
    assert(flightModify1.getCost() == 200);

    flightModify1.setMileage(100);
    assert(flightModify1.getMileage() == 100);

    // ;-; 

    // Testing FrequentFlyerAccount attributes/operations

    // Tests that account balance starts at zero
    // FrequentFlyerAccount account1("Amy Hu")
    assert(account1.getBalance() == 0);
    assert(account1.getName() == "Amy Hu");

    // Tests that .addFlightToAccount(...) does not add invalid flights to mileage balance
    assert(account1.addFlightToAccount(flightModify1) == false); // flightModify1’s name ("AH") does not match account1’s name
    assert(account1.addFlightToAccount(flight2) == false); // flight2’s name does not match account1’s name
    assert(account1.addFlightToAccount(flight3) == false); // flight3’s fromCity and toCity is empty
    assert(account1.addFlightToAccount(flight4) == false); // flight4’s fromCity is empty
    assert(account1.addFlightToAccount(flight5) == false); // flight5’s toCity is empty
    assert(account1.addFlightToAccount(flight6) == false); // flight6’s fromCity is the same as its toCity
    assert(account1.addFlightToAccount(flight7) == false); // flight7’s cost < 0
    assert(account1.addFlightToAccount(flight8) == false); // flight8’s cost = 0 - cannot add mileage from free flights
    assert(account1.addFlightToAccount(flight9) == false); // mileage = 0
    assert(account1.addFlightToAccount(flight10) == false); // mileage < 0

    assert(account1.addFlightToAccount(flight1) == true); // valid PlaneFlight parameter
    assert(account1.getBalance() == 2829); // 0 + 2829

    // Tests that .canEarnFreeFlight(...) works
    assert(account1.canEarnFreeFlight(3000) == false); // 3000 > account1’s mBalance (2829)
    assert(account1.canEarnFreeFlight(2829) == true); // 2829 = account1’s mBalance (2829)
    assert(account1.canEarnFreeFlight(2828) == true); // 2828 < account1’s mBalance (2829)
    assert(account1.canEarnFreeFlight(0) == false); // mileage cannot equal 0
    assert(account1.canEarnFreeFlight(-1) == false); // mileage cannot be less than 0

    // Tests that .freeFlight(...) ignores invalid parameters
    // flightModify1("AH", "LAS", "LGA", 200, 100) - has been modified from initial flightModify1 after previous test case testing
    assert(account1.freeFlight("", "JFK", 2829, flightModify1) == false); // empty from string
    assert(account1.freeFlight("LAX", "", 2829, flightModify1) == false); //empty to string
    assert(account1.freeFlight("LAX", "LAX", 2829, flightModify1) == false); // from string matches to string
    assert(account1.freeFlight("LAX", "JFK", 0, flightModify1) == false); // mileage must be greater than 0
    assert(account1.freeFlight("LAX", "JFK", -10, flightModify1) == false); // mileage must be greater than 0
    assert(account1.freeFlight("LAX", "JFK", 3000, flightModify1) == false); // mileage cannot exceed account’s mileage balance

    // Verifies that flight has not been modified
    assert(flightModify1.getName() == "AH");
    assert(flightModify1.getCost() == 200);
    assert(flightModify1.getFromCity() == "LAS");
    assert(flightModify1.getToCity() == "LGA");
    assert(flightModify1.getMileage() == 100);

    // Tests that .freeFlight(...) works, modifies the PlaneFlight object, and adjusts the account’s balance accordingly
    assert(account1.freeFlight("LAX", "JFK", 2828, flightModify1) == true);
    assert(account1.getBalance() == 1); // 2829 - 2828 = 1
    assert(flightModify1.getName() == "Amy Hu"); // checks that the passenger’s name has been modified
    assert(flightModify1.getCost() == 0); // checks that the flight is now free
    assert(flightModify1.getFromCity() == "LAX"); // checks that the flight’s fromCity has been modified
    assert(flightModify1.getToCity() == "JFK"); // checks that the flight’s toCity has been modified
    assert(flightModify1.getMileage() == 2828); // checks that the flight’s mileage has been modified



    // ;-; ***********

    // Test cases from BruinLearn
    // sample test code  
    PlaneFlight shortleg("Howard", "LAX", "LAS", 49.00, 285);
    PlaneFlight longleg("Howard", "LAS", "NYC", 399.00, 2800);
    PlaneFlight sample("Sample", "Sample", "Sample", 0, 1);
    FrequentFlyerAccount account("Howard");
    assert(shortleg.getFromCity() == "LAX");
    assert(shortleg.getToCity() == "LAS");
    assert(shortleg.getName() == "Howard");
    assert(std::to_string(shortleg.getCost()) == "49.000000");
    assert(std::to_string(shortleg.getMileage()) == "285.000000");

    // account balance starts at zero... 
    assert(std::to_string(account.getBalance()) == "0.000000");
    assert(account.getName() == "Howard");
    assert(account.canEarnFreeFlight(3300.00) == false);

    // flights add to an account balance 
    assert(account.addFlightToAccount(shortleg) == true);  // returns true because the names match
    assert(account.addFlightToAccount(longleg) == true);   // returns true because the names match
    assert(std::to_string(account.getBalance()) == "3085.000000");

    // free flights reduce an account balance 
    if (account.canEarnFreeFlight(285))
    {
        assert(account.freeFlight("LAS", "LAX", 285, sample) == true);
        // Howard earned a free flight... 
        assert(sample.getName() == "Howard");
        assert(std::to_string(sample.getCost()) == "0.000000");
        assert(sample.getFromCity() == "LAS");
        assert(sample.getToCity() == "LAX");
        assert(std::to_string(sample.getMileage()) == "285.000000");
        // account has been reduced for this free flight... 
        assert(std::to_string(account.getBalance()) == "2800.000000");
    }
    else
    {
        assert(false);  // there are enough miles in the account... 
    }

    // non-matching names are ignored 
    PlaneFlight muffin("Muffin", "LAX", "Doggie Heaven", 500, 500);
    assert(account.addFlightToAccount(muffin) == false);
    assert(std::to_string(account.getBalance()) == "2800.000000");

    //;-; ************************

    PlaneFlight test1("Howard", "LAX", "LAX", 49.00, 285);
    assert(test1.getFromCity() == "");
    assert(test1.getToCity() == "");

    PlaneFlight test2("Howard", "LAX", "LAS", 0.0000, 0);
    assert(test2.getCost() == 0.0000);
    assert(test2.getMileage() == -1);

    PlaneFlight test3("Howard", "", "LAX", 49.00, 285);
    assert(test3.getFromCity() == "");
    assert(test3.getToCity() == "LAX");

    cerr << "All test cases have succeed!" << endl;

    return 0;
}
