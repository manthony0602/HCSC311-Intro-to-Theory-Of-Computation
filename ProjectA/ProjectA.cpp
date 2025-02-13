#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// Function to check if a string is a valid numeric literal
bool isValidNumber(const string& str) {
    int i = 0, len = str.length();
    bool hasDigit = false, hasDecimal = false, hasExponent = false;

    if (len == 0) return false; // Empty string is not valid

    // Check for optional sign at the beginning
    if (str[i] == '+' || str[i] == '-') i++;

    // Check digits, decimal point, and exponent
    while (i < len) {
        if (isdigit(str[i])) {
            hasDigit = true;
        } else if (str[i] == '.' && !hasDecimal && !hasExponent) {
            hasDecimal = true;
        } else if ((str[i] == 'e' || str[i] == 'E') && hasDigit && !hasExponent) {
            hasExponent = true;
            hasDigit = false; // There must be a digit after exponent
            if (i + 1 < len && (str[i + 1] == '+' || str[i + 1] == '-')) i++; // Skip sign
        } else {
            return false; // Invalid character
        }
        i++;
    }

    return hasDigit; // Must have at least one digit
}

int main() {
    string inputFile, outputFile, line;

    // Ask user for input filename
    cout << "Enter input filename: ";
    cin >> inputFile;
    outputFile = inputFile + "_output.txt"; // Generate output file name

    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

/*
    if (!inFile) {
        cout << "Error: Unable to open input file!" << endl;
        return 1;
    }

    if (!outFile) {
        cout << "Error: Unable to create output file!" << endl;
        return 1;
    }
*/

    // Process each line in the file
    while (getline(inFile, line)) {
        /*
        if (isValidNumber(line))
            outFile << setw(12) << left << line << (isValidNumber(line) ? "is a valid numeric literal" : "is NOT a valid numeric literal") << endl;
        else
            outFile << setw(12) << left << line << (isValidNumber(line) ? "is a valid numeric literal" : "is NOT a valid numeric literal") << endl;
        */
        cout << setw(12) << left << line << (isValidNumber(line) ? "is a valid numeric literal" : "is NOT a valid numeric literal") << endl;
    }

    // Close files
    inFile.close();
    outFile.close();

    return 0;
}
