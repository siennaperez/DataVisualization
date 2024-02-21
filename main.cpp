// file inclusions to use functions in the program
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
using namespace std;

// main function
int main()
{
// gathering data to form table (title and headers)
    string title;
    cout << "Enter a title for the data:\n";
    getline(cin, title);
    cout << "You entered: " << title << endl;

    string c1_header;
    cout << "Enter the column 1 header:\n";
    getline(cin, c1_header);
    cout << "You entered: " << c1_header << endl;

    string c2_header;
    cout << "Enter the column 2 header:\n";
    getline(cin, c2_header);
    cout << "You entered: " << c2_header << endl;

// creating the vectors that will populate with the users inputted values
    vector<string> stringsVector;
    vector<int> integersVector;

// setting up the user for input
    string DataPoint;

// getting valid user inputs until "-1" is entered
    while (true){
        bool ErrorThrown = false;
        cout << "Enter a data point (-1 to stop input):\n";
        // user input for the data
        getline(cin, DataPoint);

        // ends the while loop for user input when "-1" is entered
        if (DataPoint == "-1"){
            break;
        }
        // first two errors involving commas
        if (DataPoint.find(',') == string::npos){
            cout << "Error: No comma in string.\n";
            ErrorThrown = true;
        }
        if (count(DataPoint.begin(), DataPoint.end(), ',') > 1) {
            cout << "Error: Too many commas in input.\n";
            ErrorThrown = true;
        }
        if (!ErrorThrown) {

            // splitting the string into two parts, before the comma (string) and after (integer)
            size_t comma = DataPoint.find(',');
            string authors = DataPoint.substr(0, comma);
            string novels = DataPoint.substr(comma + 1);

            // second exception handling: checking if the novels string will convert to an integer
            try{
                // cast the novels values into integers (STOI = 's'tring 'to' 'i'nteger)
                int novelsNumber = stoi(novels);

                // push_back pushes the data into the previously made vectors
                stringsVector.push_back(authors);
                integersVector.push_back(stoi(novels));

                // prints the data seperated
                cout << "Data string: " << authors << endl;
                cout << "Data integer: " << novelsNumber << endl;
            }
                // if the novels value is not able to cast into an integer, the user is prompted to redo their input
            catch(const invalid_argument&) {
                cout << "Error: Comma not followed by an integer.\n";
                continue;
                ErrorThrown = true;
            }
        }
    }

// creating the formatted table
    cout << "\n";
    // title line printed (33pt width)
    cout << right << setw(33) << title << endl;

    // headers and top seperating line printed
    cout << left << setw(20) << c1_header << "|" << right << setw(23) << c2_header << endl;
    cout << setfill('-') << setw(44) << "" << setfill(' ') << endl;

    // populating the table with the created vectors from the user input data
    for (size_t i = 0; i < stringsVector.size(); ++i) {
        cout << left << setw(20) << stringsVector[i] << "|" << right << setw(23) << integersVector[i] << endl;
    }
// creating the histogram
    cout << endl;
// printing authors names vertically with spacer after
    for (size_t i = 0; stringsVector.size() > i; ++i) {
        // method for inserting an empty line before the histogram data but not after (fails test case)
        if (i>0) {
            cout << endl;
        }
        cout << right << setw(20) << stringsVector[i] << " ";
        // printing the stars for number of novels
        for (int j = 0; integersVector[i] > j; ++j) {
            cout << "*";
        }
    }

    return 0;
}
