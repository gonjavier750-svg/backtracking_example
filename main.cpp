#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "estado.h"
#include "solucioncoloreado.h"
#include "Tablero.h"
#include "Color.h"
#include "problema.h"

using namespace std;


// Helper class to temporarily store fixed cells
class FixedCell {

	private:
		int f;
		int c;
		string color;

	public:
		FixedCell(int row, int col, string colorName) {
		f = row;
		c = col;
		color = colorName;
 }

	int getRow() const { return f; }
	int getCol() const { return c; }
	string getColor() const { return color; }
};


// Helper function: count fixed cells of a given color
int countFixedOfColor(const vector<FixedCell>& fixed, string color) {
	int count = 0;
	for (int i = 0; i < fixed.size(); i++) {

		if (fixed[i].getColor() == color) {
			count++;
  }
 }
	return count;
}


// Function to configure the board
Tablero configureBoard() {
	int N;
	cout << "COLOR PUZZLE CONFIGURATION" << endl;

	do {

	cout << "Enter the board dimension (N x N) [Max 10]: ";
	cin >> N;

	} while (N < 1 or N > 10);

	list<string> colorNames;

	cout << endl;
	cout << "STEP 1: COLOR REGISTRATION" << endl;
	cout << "Valid colors: Blue, Red, Green, Yellow, Orange, Purple, Brown, Pink, White, Cyan" << endl;

	bool entering = true;

	while (entering) {
	int op;

	cout << endl;
	cout << "1. Add a color name" << endl;
	cout << "2. Finish color registration" << endl;
	cout << "Option: ";
	cin >> op;

	if (op == 1) {

	string n;
	cout << "Color name: ";
	cin >> n;

	Color cTemp;
	cTemp.setNombre(n);

	if (cTemp.getNombre() != "") {

		colorNames.push_back(n);
		cout << "Color " << n << " registered" << endl;

   }
  } else if (op == 2) {
	if (colorNames.empty()) {
	cout << "You must register at least one color" << endl;

	} else {
	entering = false;
		}
	}
}

	vector<FixedCell> fixedTemp;
	int numFixed;

	cout << endl;
	cout << "STEP 2: FIXED CELLS" << endl;
	cout << "Enter the number of initially colored (fixed) cells: ";
	cin >> numFixed;

	for (int i = 0; i < numFixed; i++) {
	int f, c;
	string col;
	bool valid = false;

	do {
	cout << "Fixed cell " << i + 1 << " (Format: row column colorName): ";
	cin >> f >> c >> col;

	bool colorExists = false;

	for (list<string>::iterator it = colorNames.begin(); it != colorNames.end(); ++it) {

	if (*it == col) colorExists = true;
	}

	if (!colorExists) {
    cout << "Error: Color " << col << " was not registered in Step 1" << endl;
	} else if (f < 0 or f >= N or c < 0 or c >= N) {
    cout << "Error: Coordinates out of range" << endl;
	} else {
    valid = true;

	FixedCell newFixed(f, c, col);
	fixedTemp.push_back(newFixed);
		}
	} while (!valid);
}

	Tablero board(N);

	cout << endl;
	cout << "STEP 3: QUANTITY CONSTRAINTS" << endl;

	for (list<string>::iterator it = colorNames.begin(); it != colorNames.end(); ++it) {
		string name = *it;
		int prevUses = countFixedOfColor(fixedTemp, name);

		int option, minVal, maxVal;

		cout << endl;
		cout << "Configuring constraints for: " << name << endl;
		cout << "INFO: You have already placed " << prevUses << " fixed cells of this color" << endl;

		cout << "1. Fixed number of occurrences" << endl;
		cout << "2. Range [min, max]" << endl;
		cout << "Option: ";
		cin >> option;

	bool countValid = false;
	while (!countValid) {
	if (option == 1) {
    cout << "TOTAL number of occurrences (must be >= " << prevUses << "): ";
    cin >> minVal;
    maxVal = minVal;

	} else {
    cout << "Minimum occurrences (must be >= " << prevUses << "): ";
    cin >> minVal;
    cout << "Maximum occurrences: ";
    cin >> maxVal;
	}

	if (minVal < prevUses) {
    cout << "Error: The minimum cannot be less than the fixed cells already placed" << endl;
	} else {
    countValid = true;
	}
  }

	Color newColor(name, minVal, maxVal, 0);
	board.addColor(newColor);
}

	for (int i = 0; i < fixedTemp.size(); i++) {

		board.setCasillaInicial(fixedTemp[i].getRow(), fixedTemp[i].getCol(), fixedTemp[i].getColor());
	}

	return board;
}


// MAIN

int main() {

	Tablero initialBoard = configureBoard();

	cout << endl;
	cout << "INITIAL BOARD STATE" << endl;
	initialBoard.mostrar();
	initialBoard.mostrarCasillasFijas();

    Problema problem(initialBoard);

	cout << endl;
	cout << "STARTING BACKTRACKING..." << endl;

    list<SolucionColoreado> solutions = problem.ejecutaBacktracking();

	cout << endl;
	cout << "----------------------------------------" << endl;
	cout << "PROCESS FINISHED" << endl;

    if (solutions.empty()) {
		cout << "No valid solution was found" << endl;

	} else {
		int count = 0;
        cout << "Total solutions found: " << solutions.size() << endl;
        cout << "----------------------------------------" << endl;

        list<SolucionColoreado>::iterator it = solutions.begin();

        while (it != solutions.end()) {
            count++;
            cout << endl;
            cout << "========================================" << endl;
            cout << "SOLUTION NUMBER " << count << ":" << endl;
            cout << "========================================" << endl;

            it->mostrar();
            cout << endl;

            it++;
        }
	}
	cout << "----------------------------------------" << endl;

	return 0;
}