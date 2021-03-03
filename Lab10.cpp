#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>

using namespace std;
void createFile();
void openFile();
void writeFile();
void readFile();
string location();
FILE* file;
string locationName;
struct railway {
	int numberTrain;
	string finalDestination;
	int time;
	int freeSeats;
};
railway railwayArray[10];

int main()
{
    int index;
    
	while (true) {
		std::cout << "Make a choise.\n"
			<< "\t1 - Create\n"
			<< "\t2 - Open and print\n"
			<< "\t3 - Exit" <<endl;
		switch (_getch()) {
		case '1':
			createFile();
			break;
		case '2':
			openFile();
			break;
		case '3':
			exit(1);
			break;

		}
	}
}

	void createFile() {
		if (locationName.length() != 0) {
			
		}
		if ((file = fopen(location().c_str(), "w")) == NULL) {
			cout << "Error while creating";
			exit(1);
		}
		else {
			cout << "File create";
			fclose(file);
		}
	}

	void openFile() {

		if ((file = fopen(location().c_str(), "r")) == NULL) {
			cout << "Error while opening";
			exit(1);
		}
		while (true) {
			std::cout << "Make a choise.\n"
				<< "\t1 - Read file\n"
				<< "\t2 - Write file\n"
				<< "\t3 - Exit" << endl;
			switch (_getch()) {
			case '1':
				readFile();
				break;
			case '2':
				writeFile();
				break;
			case '3':
				exit(1);
				break;

			}
		}
	}
		string location() {
			cout << "Enter file location" << endl;
			cin >> locationName;
			return locationName;
		}

		void readFile() {
			rewind(file);
			int counter = 0;
			while (!feof(file)) {
				printf("%d %s %d %d\n", railwayArray[counter].numberTrain, railwayArray[counter].finalDestination.c_str(),
					railwayArray[counter].freeSeats, railwayArray[counter].time);
				counter++;
			}
			cout << "Amount of fields: " << counter;
			fclose(file);
		}
		void writeFile() {
			rewind(file);
			string inputString;
			while (getline(cin,inputString)) {
				cout << "Enter number of Train, Final Destination of Train, Free Seats in Trains, Time of Department";
				fputs(inputString.c_str(), file);
				fclose(file);
			}

		}
	
