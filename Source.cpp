#include <iostream>
#include <string>

using namespace std;



int const NUMROWS = 13;

void initalSeatFill(char seats[][NUMROWS]);
char getSeatChar(string userInput);
int getRowNum(string userInput);

int getRowIndex(int thisRow);
int getSeatIndex(char thisSeat);
void displaySeatColumn(char seats[][NUMROWS], int column);

void displayAllSeats(char seats[][NUMROWS]);




int main() {

	string userInput = "";

	char seatLtr = 'O';
	int rowNum = 0;

	int rowIndex = 0;
	int seatIndex = 0;

	char seats[4][NUMROWS];

	initalSeatFill(seats);

	while (true) {

		displayAllSeats(seats);

		cout << "Enter a seat or Q to quit: ";
		cin >> userInput;

		system("cls");

		if (userInput == "Q" || userInput == "q") {

			return 0;

		}

		seatLtr = getSeatChar(userInput);
		rowNum = getRowNum(userInput);

		rowIndex = getRowIndex(rowNum);

		if (rowIndex == 13) {

			cout << "Sorry, no such seat exists on the CRJ 200.\n\n";

		}

		else {

			seatIndex = getSeatIndex(seatLtr);

			if (seatIndex == 4) {

				cout << "Sorry, no such seat exists on the CRJ 200.\n\n";

			}

			else {

				if (seats[seatIndex][rowIndex] == 'O') {
					cout << "Sorry, no such seat exists on the CRJ 200.\n\n";
				}

				else if (seats[seatIndex][rowIndex] == 'X') {
					cout << "Sorry, there is already someone assigned to this seat.\n\n";
				}

				else {
					seats[seatIndex][rowIndex] = 'X';
				}

			}

		}

	}

}



void initalSeatFill(char seats[][NUMROWS]) {
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

char getSeatChar(string userInput) {
	int length = userInput.length();

	if (tolower(userInput[length - 1]) != 'a' && tolower(userInput[length - 1]) != 'b' && tolower(userInput[length - 1]) != 'c' && tolower(userInput[length - 1]) != 'd') {
		return 'O';
	}

	else {
		return toupper(userInput[length - 1]);
	}

}

int getRowNum(string userInput) {
	int length = userInput.length();
	string rowNumS = "";

	for (int i = 0; i < length - 1; i++) {
		rowNumS = rowNumS + userInput[i];
	}

	int rowNum = stoi(rowNumS);

	return rowNum;
}

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

int getRowIndex(int thisRow) {

	if (thisRow > 13 || thisRow < 1) {
		return 13;
	}

	else {
		return thisRow - 1;
	}

}

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