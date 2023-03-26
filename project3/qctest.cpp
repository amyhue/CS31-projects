// Project 3: Quality Control (QC) Testing
// Name: Amy Hu

#include <iostream>
#include <cassert>
#include <string>

using namespace std;

// Extracts number starting at given index
// If there is no number starting at given index, return -1 to differentiate from the number 0
int extractNum(string s, int index) { 
	size_t stringSize;
	int num = 0;
	int charAsInt;
	int indexCount = 0;
	stringSize = s.size();

	//loop to get number starting at given index
	for (int i = index; i < stringSize; i++) {
		if (isdigit(s[i])) {
			charAsInt = s[i] - '0'; // getting number from char
			num = num * 10 + charAsInt; //More digits after, so equivalent to multiplying initial qNum by 10, then adding new digit
			indexCount++; //indexCount has increased, indicating a number has been extracted
		}
		else {
			break;
		}

	}
	
	// returns the value of the number extracted
	/*if no number is extracted (i.e. indexCount is still 0), return -1 to differentiate
			when the number is 0 vs the initialized num = 0*/
	// else, return num
	if (indexCount == 0) {
		return -1;
	}
	else {
		return num;
	}
}

// "counts" the amount of indexes a number takes up and returns the "count"
// if there are leading zeroes, getNewIndex will not capture said the leading zeroes
int getNewIndex(int n) {
	int count;
	int num = n;
	if (n == 0) {
		return 1; // if n is 0, it still occupies an index, but the for loop won't account for it
	}
	for (count = 0; num > 0; count++) {
		num = num / 10;
	}
	return count;
}

// Returns true if the parameter is a well-form string as described in SPECs
// Return false otherwise
bool isValidQC(string results) {
	size_t stringSize = results.size();
	int indexNum = 0;

	//The numbers after Q, p, and d	
	int qNum = 0;
	int pNum = 0;
	int dNum = 0;
	
	// Empty strings will skip the while loop, since its stringSize = 0
	// Each loop tests a Qpd/Qdp substring -- if each substring is vaid, then the whole string should be considered valid
	while (indexNum < stringSize) {
		// At minimum, the substring must start with 'Q' to be a valid QC test
		if (results[indexNum] == 'Q') {
		//Current index is 'Q', so increase index by one to look at the next value
			indexNum++;
			qNum = extractNum(results, indexNum);//Get number after Q
			// For qNum, the number extracted must be greater than 0
			if (qNum > 0) {
				indexNum += getNewIndex(qNum); // Move the index along, since there is a number after 'Q'

				// Checking if the next character seen is 'p' (then subsequently 'd') or is 'd' (then subsequently 'p')
				// Extract the numbers after each character / fail the string in a similar fashion to 'Q'
				// if there is a leading zero, the indexNum will be on a number and not a character
				// use indexNum < stringSize in case there is no letter after the num (e.g. Q123 vs Q123p)
				// which will avoid out-of-bounds error with short-circuiting
				if (indexNum < stringSize && results[indexNum] == 'p') {
					indexNum++;
					pNum = extractNum(results, indexNum);
					// For pNum and qNum, unlike qNum, the number extracted can be 0
					if (pNum >= 0) {
						indexNum += getNewIndex(pNum);
						if (indexNum < stringSize && results[indexNum] == 'd') {
							indexNum++;
							dNum = extractNum(results, indexNum);
							if (dNum >= 0) {
								indexNum += getNewIndex(dNum);
							}
							else return false;

						}
						else return false;
					}
					else return false;
				}
				else if (indexNum < stringSize && results[indexNum] == 'd') {
					indexNum++;
					dNum = extractNum(results, indexNum);
					if (dNum >= 0) {
						indexNum += getNewIndex(dNum);
						if (indexNum < stringSize && results[indexNum] == 'p') {
							indexNum++;
							pNum = extractNum(results, indexNum);
							if (pNum >= 0) {
								indexNum += getNewIndex(pNum);
							}
							else return false;

						}
						else return false;
					}
					else return false;
				}
				else return false;
			}
			else return false;

			// At this point, if we haven't returned false yet, we should have valid qNum, pNum and dNum for this specific QC batch
			// We check pNum + dNum != qNum -- if it doesn't, directly return false. Otherwise do nothing, and continue looping
			// If there is a leading term in the final 'p'/'d' of the given batch, it will be caught when we continue the loop
			// and the next char is not 'Q' (it will be a number), since indexNum will still be less than stringSize
			if (pNum + dNum != qNum) {
				return false;
			}

			// check what qNum, pNum, and dNum are
			/*cout << "qNum is " << qNum << endl;
			cout << "pNum is " << pNum << endl;
			cout << "dNum is " << dNum << endl;*/

		}
		else {
			return false;
		}
	}
	/*cout << "finished code" << endl;*/

	// if the string is not empty, the indexNum should be greater than zero -- any invalid string that's not empty would be caught in the while loop
	// if the string is empty, it will not have entered the while loop, so its indexNum would still == 0
	if (indexNum > 0) {
		return true; 
	}
	return false;
}

// Returns the total number of pass test results from all of the batches reported in the string
// Return -1 if the parameter is not valid
int passQC(string results) {
	size_t stringSize = results.size();
	int indexNum = 0;
	int totPass = 0;
	int pNum = 0;

	if (!isValidQC(results)) return -1; // if results is not a valid QC test string, automatically return -1
	
	while (indexNum < stringSize) {
		if (results[indexNum] == 'p') {
			indexNum++; // start index at the number, not at 'p'
			pNum = extractNum(results, indexNum); 
			totPass += pNum; // Add the extracted number after 'p' to the total number of passes
			indexNum += getNewIndex(pNum);
		}
		else {
			indexNum++;
		}
	}

	return totPass;
}

// Returns the total number of defect test results from all of the batches reported in the string
// Return -1 if the parameter is not valid
int defectQC(string results) {
	size_t stringSize = results.size();
	int indexNum = 0;
	int totDefect = 0;
	int dNum = 0;

	if (!isValidQC(results)) return -1; // if results is not a valid QC test string, automatically return -1

	while (indexNum < stringSize) {
		if (results[indexNum] == 'd') {
			indexNum++; // start index at the number, not at 'p'
			dNum = extractNum(results, indexNum);
			totDefect += dNum; // Add the extracted number after 'p' to the total number of passes
			indexNum += getNewIndex(dNum);
		}
		else {
			indexNum++;
		}
	}

	return totDefect;
}

// Returns the total number of test results from all of the batches reported in the string
// Return -1 if the parameter is not valid
int totalQC(string results) {
	size_t stringSize = results.size();
	int indexNum = 0;
	int totTest = 0;
	int qNum = 0;

	if (!isValidQC(results)) return -1; // if results is not a valid QC test string, automatically return -1

	// if results is a valid QC test result, then number of passes + number of defects = number of tests (i.e. the number after Q)
	while (indexNum < stringSize) {
		if (results[indexNum] == 'Q') {
			indexNum++; // start index at the number, not at 'Q'
			qNum = extractNum(results, indexNum);
			totTest += qNum; // Add the extracted number after 'p' to the total number of passes
			indexNum += getNewIndex(qNum);
		}
		else {
			indexNum++;
		}
	}

	return totTest;
}

// Returns the total number of batches reported in the string
// Return -1 if the parameter is not valid
int batches(string results) {
	size_t stringSize = results.size();
	int indexNum = 0;
	int totBatch = 0;

	if (!isValidQC(results)) return -1; // if results is not a valid QC test string, automatically return -1

	// if results is a valid QC test result, then number of passes + number of defects = number of tests (i.e. the number after Q)
	while (indexNum < stringSize) {
		if (results[indexNum] == 'Q') {
			indexNum++; // go to next char
			totBatch++; // if there is a 'Q', then there is 1 batch
		}
		else {
			indexNum++;
		}
	}
	return totBatch;
}

int main() {
	string qc;

	cout << "QC Test: ";
	getline(cin, qc);
	cout << isValidQC(qc) << endl;
	cout << passQC(qc) << endl;
	cout << defectQC(qc) << endl;
	cout << totalQC(qc) << endl;
	cout << batches(qc) << endl;
	cout << "reached main()" << endl;

	/*cout << (100 == 'c') << endl;
	cout << ('c' == 'c') << endl;*/

	cout << "qc is " << qc << endl;


// Tests the program runs in general for correct test results

// QC Test Result: Q3p2d1
	assert(isValidQC("Q3p2d1") == true);
	assert(passQC("Q3p2d1") == 2);
	assert(defectQC("Q3p2d1") == 1);
	assert(totalQC("Q3p2d1") == 3);
	assert(batches("Q3p2d1") == 1);

	cout << "Q3p2d1 has passed" << endl;

	// QC Test Result: Q3d2p1
	assert(isValidQC("Q3d2p1") == true);
	assert(passQC("Q3d2p1") == 1);
	assert(defectQC("Q3d2p1") == 2);
	assert(totalQC("Q3d2p1") == 3);
	assert(batches("Q3d2p1") == 1);

	cout << "Q3d2p1 has passed" << endl;

	// QC Test Result: Q123p100d23Q100d60p40
	assert(isValidQC("Q123p100d23Q100d60p40") == true);
	assert(passQC("Q123p100d23Q100d60p40") == 140);
	assert(defectQC("Q123p100d23Q100d60p40") == 83);
	assert(totalQC("Q123p100d23Q100d60p40") == 223);
	assert(batches("Q123p100d23Q100d60p40") == 2);

	cout << "Q123p100d23Q100d60p40 has passed" << endl;

	// Tests that zero after ‘Q’ is invalid

	// QC Test Result: Q0p0d0
	assert(isValidQC("Q0p0d0") == false);
	assert(passQC("Q0p0d0") == -1);
	assert(defectQC("Q0p0d0") == -1);
	assert(totalQC("Q0p0d0") == -1);
	assert(batches("Q0p0d0") == -1);

	// Tests that leading zeroes are invalid

	// QC Test Result: Q20p010d10
	assert(isValidQC("Q20p010d10") == false);
	assert(passQC("Q20p010d10") == -1);
	assert(defectQC("Q20p010d10") == -1);
	assert(totalQC("Q20p010d10") == -1);
	assert(batches("Q20p010d10") == -1);

	// Tests that regular zeroes are valid

	// QC Test Result: Q20p10d10
	assert(isValidQC("Q20p10d10") == true);
	assert(passQC("Q20p10d10") == 10);
	assert(defectQC("Q20p10d10") == 10);
	assert(totalQC("Q20p10d10") == 20);
	assert(batches("Q20p10d10") == 1);

	// Tests that ‘p’ and ‘d’ order does not matter

	// QC Test Result: Q3p2d1
	assert(isValidQC("Q3p2d1") == true);
	assert(passQC("Q3p2d1") == 2);
	assert(defectQC("Q3p2d1") == 1);
	assert(totalQC("Q3p2d1") == 3);
	assert(batches("Q3p2d1") == 1);

	// QC Test Result: Q3d2p1
	assert(isValidQC("Q3d2p1") == true);
	assert(passQC("Q3d2p1") == 1);
	assert(defectQC("Q3d2p1") == 2);
	assert(totalQC("Q3d2p1") == 3);
	assert(batches("Q3d2p1") == 1);

	// Tests that ‘p’ number and ‘d’ number sum to ‘Q’’s number

	// QC Test Result: Q3d2p1
	assert(isValidQC("Q3d2p1") == true);
	assert(passQC("Q3d2p1") == 1);
	assert(defectQC("Q3d2p1") == 2);
	assert(totalQC("Q3d2p1") == 3);
	assert(batches("Q3d2p1") == 1);

	// QC Test Result: Q3d2p0
	assert(isValidQC("Q3d2p0") == false);
	assert(passQC("Q3d2p0") == -1);
	assert(defectQC("Q3d2p0") == -1);
	assert(totalQC("Q3d2p0") == -1);
	assert(batches("Q3d2p0") == -1);

	// Tests that extra characters are not allowed

	// QC Test Result: Q3wd3p0
	assert(isValidQC("Q3wd3p0") == false);
	assert(passQC("Q3wd3p0") == -1);
	assert(defectQC("Q3wd3p0") == -1);
	assert(totalQC("Q3wd3p0") == -1);
	assert(batches("Q3wd3p0") == -1);

		// Tests that numbers for defect/pass required

		// QC Test Result: Q3dp3
	assert(isValidQC("Q3dp3") == false);
	assert(passQC("Q3dp3") == -1);
	assert(defectQC("Q3dp3") == -1);
	assert(totalQC("Q3dp3") == -1);
	assert(batches("Q3dp3") == -1);

		// QC Test Result: Q3pd3
	assert(isValidQC("Q3pd3") == false);
	assert(passQC("Q3pd3") == -1);
	assert(defectQC("Q3pd3") == -1);
	assert(totalQC("Q3pd3") == -1);
	assert(batches("Q3pd3") == -1);

		// Tests that the string must start with Q

		// QC Test Result: q3p0d3
	assert(isValidQC("q3p0d3") == false);
	assert(passQC("q3p0d3") == -1);
	assert(defectQC("q3p0d3") == -1);
	assert(totalQC("q3p0d3") == -1);




	cout << "All test cases succeeded" << endl;

}
