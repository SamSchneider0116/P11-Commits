/*
Sam Schneider
Introductory Programmng
April 9, 2026
P11 - Commits (because the lab instructions didn't tell me to make commits)
*/


#include <iostream>
#include <string>

using namespace std;


int const NUMROWS = 13;											//Constant Integer for number of total rows on plane

void initialSeatFill(char seats[][NUMROWS]);						//Fills all rows will applicible avaliable seats
char getSeatChar(string userInput);								//Gets the column letter from user input
int getRowNum(string userInput);								//Gets the row number from user input

int getRowIndex(int thisRow);									//Gets the row index and returns error if needed
int getSeatIndex(char thisSeat);								//Gets the seat index and returns error if needed
void displaySeatColumn(char seats[][NUMROWS], int column);		//Displays seat column

void displayAllSeats(char seats[][NUMROWS]);					//Displays all seat columns and labels in plane



int main() {

	string userInput = "";			//User input, requested seat

	char seatLtr = 'O';				//Column letter from user input
	int rowNum = 0;					//Row number from user input

	int rowIndex = 0;				//Row index, tests for errors or returns array index
	int seatIndex = 0;				//Seat index, tests for errors or returns array index

	char seats[4][NUMROWS];			//Stupid multi-dimensional array that made everything 10x harder; stores seat values

	//Fill array with initial values
	initialSeatFill(seats);

	while (true) {

		//Display plane seats
		displayAllSeats(seats);

		//Prompts user input
		cout << "Enter a seat or Q to quit: ";
		cin >> userInput;

		system("cls");

		//Quits
		if (userInput == "Q" || userInput == "q") {

			return 0;

		}

		//Gets information from user input
		seatLtr = getSeatChar(userInput);		
		rowNum = getRowNum(userInput);

		//Gets row index
		rowIndex = getRowIndex(rowNum);

		//If invalid, returns error message
		if (rowIndex == 13) {

			cout << "Sorry, no such seat exists on the CRJ 200.\n\n";

		}

		//If not, continues
		else {

			//Gets seat index
			seatIndex = getSeatIndex(seatLtr);

			//If invalid, returns error message
			if (seatIndex == 4) {

				cout << "Sorry, no such seat exists on the CRJ 200.\n\n";

			}

			//If not, continues
			else {

				//Tests for 13D and 13C
				if (seats[seatIndex][rowIndex] == 'O') {

					cout << "Sorry, no such seat exists on the CRJ 200.\n\n";

				}

				//Tests for occupied seat
				else if (seats[seatIndex][rowIndex] == 'X') {

					cout << "Sorry, there is already someone assigned to this seat.\n\n";

				}

				//Occupies seat
				else {

					seats[seatIndex][rowIndex] = 'X';

				}

			}

		}

	}

}



/*
initialSeatFill: fills seats[][] array with avaliable seats upon program start
@param seats -  reference to a 2-D character array 
*/
void initialSeatFill(char seats[][NUMROWS]) {
	for (int i = 0; i < NUMROWS - 1; i++) {
		seats[0][i] = 'D';
		seats[1][i] = 'C';
	}

	seats[0][NUMROWS - 1] = 'O';
	seats[1][NUMROWS - 1] = 'O';


	for (int i = 0; i < NUMROWS; i++) {
		seats[2][i] = 'B';
		seats[3][i] = 'A';
	}

}

/*
getSeatChar: given user input, returns desired seat character for column calculation
@param userInput -  string representing user's desired seat
@return appropriate character
*/
char getSeatChar(string userInput) {
	int length = userInput.length();

	if (tolower(userInput[length - 1]) != 'a' && tolower(userInput[length - 1]) != 'b' && tolower(userInput[length - 1]) != 'c' && tolower(userInput[length - 1]) != 'd') {
		return 'O';
	}

	else {
		return toupper(userInput[length - 1]);
	}

}

/*
getRowNum: given user input, returns desired row number
@param userInput -  string representing user's desired seat
@return appropriate integer
*/
int getRowNum(string userInput) {
	int length = userInput.length();
	string rowNumS = "";

	for (int i = 0; i < length - 1; i++) {
		rowNumS = rowNumS + userInput[i];
	}

	int rowNum = stoi(rowNumS);

	return rowNum;
}

/*
displaySeatColumn: given a 2-D mapping of the seating chart in the form [columns][rows],
will print out a "column" of seats on one row of output (i.e., seat 'A' for all rows in the plane)
@param seats - reference to a 2-D character array
@param column - reference to which column of seats to display
*/
void displaySeatColumn(char seats[][NUMROWS], int column) {

	for (int i = 0; i < NUMROWS; i++) {
		if (column == 0 && i == NUMROWS - 1) {
			break;
		}

		else if (column == 1 && i == NUMROWS - 1) {
			break;
		}

		else {
			cout << seats[column][i] << " ";
		}
	}

}

/*
displayAllSeats: given a 2-D mapping of the seating chart in the form [columns][rows],
will print out full map including row labels, avaliable seats, and occupied seats
@param seats - reference to a 2-D character array
*/
void displayAllSeats(char seats[][NUMROWS]) {

	displaySeatColumn(seats, 0);
	cout << endl;
	displaySeatColumn(seats, 1);
	cout << endl << endl;
	cout << "                  1 1 1 1" << endl;
	cout << "1 2 3 4 5 6 7 8 9 0 1 2 3" << endl << endl;
	displaySeatColumn(seats, 2);
	cout << endl;
	displaySeatColumn(seats, 3);
	cout << endl << endl;

}

/*
getRowIndex: given user input, returns appropriate row index into arrays.
@param thisRow - integer indicating row selected by the user
@return appropriate index into 2-D array if the specified row is valid, ERROR value otherwise
*/
int getRowIndex(int thisRow) {

	if (thisRow > 13 || thisRow < 1) {
		return 13;
	}

	else {
		return thisRow - 1;
	}

}

/*
getSeatIndex: given user input, returns appropriate column index into seating chart array.
@param thisSeat - character indicating selected seat within row
@return appropriate index into 2-D array if the specified seat is valid, ERROR value otherwise
*/
int getSeatIndex(char thisSeat) {

	if (thisSeat == 'D') {
		return 0;
	}

	else if (thisSeat == 'C') {
		return 1;
	}

	else if (thisSeat == 'B') {
		return 2;
	}

	else if (thisSeat == 'A') {
		return 3;
	}

	else {
		return 4;
	}

}