#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// CONSTANTS
const string HEADER_TITLE = " Welcome to my Letter Count Program ";
const int HEADER_LENGTH = 60;
const char SYMBOLE = '*';
const char OUTPUT_FILL = '.';

void  HeaderTitle();

int main(int argc, char* argv[])
{
    // Calls function to output title header
    HeaderTitle();

    // Check if at least two arguments were passed, otherwise display error and exit program
    if (argc < 2)
    {
        cout << "[!] Error with input agrs.." << endl;
        cout << "> Press any key to continue. . . ";
        cin.get();
        return 1;
    }

    ifstream inFile;
    // Initialize a constant variable for the file name passed through the console window
    const string fileName = argv[1];

    // OPEN FILE
    inFile.open(fileName);
    if (!inFile)
    {
        cout << "[!] Error with file name:\t\'" << fileName << "\'" << endl;
        // Pause the program for user, then exit 
        cout << "> Press any key to continue. . . ";
        cin.get();
        return 1;
    }
    else
        cout << "[-] Analyzing file \'" << fileName << "\'..." << endl;

    // READ FILE LINES
    char letters;
    int num_A = 0;
    int num_E = 0;
    int num_I = 0;
    int num_O = 0;
    int num_U = 0;
    int vowelSumCount = 0;

    int num_W = 0;
    int num_S = 0;
    int num_D = 0;
    int extraLettersCount = 0;

    // READ FILE LINES
    while (!inFile.eof() && inFile >> letters)
    {
        letters = toupper(letters);

        switch (letters)
        {
        case 'A':
            num_A += 1;
            break;
        case 'E':
            num_E += 1;
            break;
        case 'I':
            num_I += 1;
            break;
        case 'O':
            num_O += 1;
            break;
        case 'U':
            num_U += 1;
            break;
        case 'W':
            num_W += 1;
            break;
        case 'S':
            num_S += 1;
            break;
        case 'D':
            num_D += 1;
            break;
        }
    }

    vowelSumCount = num_A + num_E + num_I + num_O + num_U;
    extraLettersCount = num_W + num_S + num_D;

    // OUTPUT
    cout << endl;
    cout << setfill(OUTPUT_FILL);
    cout << left << setw(HEADER_LENGTH) << "[+] The number of A's: " << num_A << endl;
    cout << left << setw(HEADER_LENGTH) << "[+] The number of E's: " << num_E << endl;
    cout << left << setw(HEADER_LENGTH) << "[+] The number of I's: " << num_I << endl;
    cout << left << setw(HEADER_LENGTH) << "[+] The number of O's: " << num_O << endl;
    cout << left << setw(HEADER_LENGTH) << "[+] The number of U's: " << num_U << endl;
    cout << left << setw(HEADER_LENGTH) << "[+] The vowel count is: " << vowelSumCount << endl << endl;

    string fullLine = string(HEADER_LENGTH, SYMBOLE);
    cout << fullLine << endl << endl;
    cout << left << setw(HEADER_LENGTH) << "[+] The number of W's: " << num_W << endl;
    cout << left << setw(HEADER_LENGTH) << "[+] The number of S's: " << num_S << endl;
    cout << left << setw(HEADER_LENGTH) << "[+] The number of D's: " << num_D << endl;
    cout << left << setw(HEADER_LENGTH) << "[+] The number of extra letters(W, S, D) is: " << extraLettersCount << endl;

    inFile.close();

    cout << "\nPress any key to continue. . . ";
    cin.get();
    return 0;
}

// Simple non-returning function to output the title header
void  HeaderTitle()
{
    int headerHalfLength = (HEADER_LENGTH - HEADER_TITLE.length()) / 2;

    string fullLine = string(HEADER_LENGTH, SYMBOLE);
    string halfLine = string(headerHalfLength, SYMBOLE);

    cout << fullLine << endl;
    cout << halfLine << HEADER_TITLE << halfLine << endl;
    cout << fullLine << endl << endl;
}