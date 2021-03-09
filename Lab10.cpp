#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>

using namespace std;
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
void createFile();
void printData();
void writeFile();
void readFile();
void info();
void openFile(string);
void insertionsort();
void quickSort(railway*, int, int);
void bruteForceSearch();
void binarySearch();
void print();

int main()
{
	while (true) {
		cout << "Make a choise.\n"
			<< "\t1 - Create\n"
			<< "\t2 - Print data\n"
			<< "\t3 - Write data\n"
			<< "\t4 - Info about free seat to destination\n"
			<< "\t5 - Insertion Sort\n"
			<< "\t6 - Quick Sort\n"
			<< "\t7 - Brute - force search\n"
			<< "\t8 - Binary search\n"
			<< "\t10 - Exit\n" << endl;
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
			insertionsort();
			break;
		case '6':
			openFile("r");
			readFile();
			quickSort(railwayArray, 0, fieldsAmount-1);
			print();
			fclose(file);
			break;
		case '7':
			bruteForceSearch();
			break;
		case '8':
			openFile("r");
			readFile();
			quickSort(railwayArray, 0, fieldsAmount - 1);
			binarySearch();
			fclose(file);
			break;
		case '10':
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

void print() {
	for (int i = 0; i < fieldsAmount; i++) {
	printf("%s %d %d %d\n", railwayArray[i].finalDestination, railwayArray[i].numberTrain,
		railwayArray[i].freeSeats, railwayArray[i].time);
}
}

void printData() {

	openFile("r");
	readFile();
	print();
	fclose(file);
}

void openFile(string param) {
	if (locationName.length() != 0) {
		if ((file = fopen(locationName.c_str(), param.c_str())) == NULL) {
			printf("Error while opening \n");
			exit(1);
		}
	}
	else if ((file = fopen(location().c_str(), param.c_str())) == NULL) {
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
		fscanf(file, " %s %d%d%d\n", &railwayArray[fieldsAmount].finalDestination, &railwayArray[fieldsAmount].numberTrain,
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
	printf("Avaible trains to: %s \n", destination);
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

void quickSort(railway* arr, int first, int last) {
	if (first < last) {
		int left = first, right = last;
		int pivon = arr[(left + right) / 2].time;
		do {
			while (arr[left].time < pivon) left++;
			while (arr[right].time > pivon) right--;
			if (left <= right) {
				swap(arr[left], arr[right]);
				left++;
				right--;
			}
		} while (left <= right);
		quickSort(arr, first, right);
		quickSort(arr, left, last);
	}
}

void insertionsort() {
	openFile("r");
	readFile();
	for (int i = 1; i < fieldsAmount; i++) {
		for (int j = i; j > 0 && railwayArray[j].time < railwayArray[j - 1].time; j--) {
			swap(railwayArray[j - 1], railwayArray[j]);
		}
	}
	print();
	fclose(file);
}

void bruteForceSearch() {
	openFile("r");
	readFile();
	int key;
	printf("Enter time: ");
	cin >> key;
	for (int i = 0; i < fieldsAmount; i++) {
		if (railwayArray[i].time == key) {
			printf("%s %d %d %d\n", railwayArray[i].finalDestination, railwayArray[i].numberTrain,
				railwayArray[i].freeSeats, railwayArray[i].time);
		}
	}
	fclose(file);
	
}
void binarySearch(){
	int key;
	printf("Enter time: ");
	cin >> key;
	int left = 0, right = fieldsAmount - 1, center;
	while (left <= right) {
		center = (left + right) / 2;
		if (key > railwayArray[center].time) {
			left = center + 1;
		}
		else {
			right = center;
		}
		if (railwayArray[left].time == key) {
			printf("%s %d %d %d\n", railwayArray[left].finalDestination, railwayArray[left].numberTrain,
				railwayArray[left].freeSeats, railwayArray[left].time);
			break;

		}
		else {
			printf("Nothing found\n");
			break;
		}
	}
}


