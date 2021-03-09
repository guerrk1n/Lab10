#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>

using namespace std;
void createFile();
void printData();
void writeFile();
void readFile();
void info();
void openFile(string);
void sort();
string location();
FILE* file;
string locationName;
int fieldsAmount;
struct railway {
	char finalDestination[10];
	int numberTrain;
	int freeSeats;
	int time;
};
railway railwayArray[5];

int main()
{
	while (true) {
		cout << "Make a choise.\n"
			<< "\t1 - Create\n"
			<< "\t2 - Print data\n"
			<< "\t3 - Write data\n"
			<< "\t4 - Info about free seat to destination\n"
			<< "\t6 - Exit\n" << endl;
		switch (_getch()) {
		case '1':
			createFile();
			break;
		case '2':
			printData();
			break;
		case '3':
			writeFile();
			break;
		case '4':
			info();
			break;
		case '5':
			sort();
			break;
		case '6':
			exit(0);
			break;
		default: 
			printf("Check your input \n");
			break;
		}
	}
}

void createFile() {
	openFile("w");
	printf("File created \n");
}

void printData() {

		openFile("r");
		readFile();
		for(int i=0; i < fieldsAmount; i++)
		printf("%s %d %d %d\n", railwayArray[i].finalDestination, railwayArray[i].numberTrain,
			railwayArray[i].freeSeats, railwayArray[i].time);
		fclose(file);
}

void openFile(string param) {
	if (locationName.length() != 0) {
		if ((file = fopen(locationName.c_str(), param.c_str())) == NULL) {
			printf("Error while opening \n");
			exit(1);
		}
	}else if ((file = fopen(location().c_str(), param.c_str())) == NULL) {
		printf("Error while opening \n");
		exit(1);
	}
	
}

string location() {
	printf("Enter file location \n");
	cin >> locationName;
	return locationName;
}

void readFile() {
	
	fieldsAmount = 0;
	rewind(file);
	while (!feof(file)) {
		fscanf(file," %s %d%d%d\n", &railwayArray[fieldsAmount].finalDestination,&railwayArray[fieldsAmount].numberTrain,
			&railwayArray[fieldsAmount].freeSeats, &railwayArray[fieldsAmount].time);
		fieldsAmount++;
	}
	fclose(file);
}
void writeFile() {
	openFile("w");
	string input;
	printf("Enter CTRL + Z to exit \n");
		while (getline(cin, input)) {
			printf("Destination,Train number, Free Seats, Time: ");
			fputs(input.c_str(), file);
		}
			fclose(file);
		}
	

void info() {
	string destination;
	openFile("r");
	readFile();
	printf("Enter destination: ");
	cin >> destination;
	bool freeSeats = false;
	printf("Avaible trains to: %s \n",destination);
	for (int i = 0; i < fieldsAmount; i++) {
		if (destination == railwayArray[i].finalDestination && railwayArray[i].freeSeats > 0) {
			freeSeats = true;
			printf("%s %d %d %d\n", railwayArray[i].finalDestination, railwayArray[i].numberTrain,
				railwayArray[i].freeSeats, railwayArray[i].time);
		}
	}
	if (!freeSeats) {
		printf("There is no avaibles train to your destination.");
	}
}

void sort() {
	
}


