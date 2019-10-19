//Brett Silvey
//This is my own work

#include <iostream>
#include <fstream>	//allows for files to be input and output
#include <string>

using namespace std;

void findLS();
void getSum();
void factorial();
void detPalindrome();
void primeNum();
void findAvg();
void part7();

int main() {

	findLS();
	getSum();
	factorial();
	detPalindrome();
	primeNum();
	findAvg();
	part7();

	return 0;
}

void findLS() {
	//take input from user
	cout << "Please enter 5 integers: ";
	int n1, n2, n3, n4, n5;
	cin >> n1 >> n2 >> n3 >> n4 >> n5;
	//create integers 
	int largest, smallest;

	//run comparisons
	largest = INT_MIN;
	if (largest < n1) largest = n1;
	if (largest < n2) largest = n2;
	if (largest < n3) largest = n3;
	if (largest < n4) largest = n4;
	if (largest < n5) largest = n5;

	smallest = INT_MAX;
	if (smallest > n1) smallest = n1;
	if (smallest > n2) smallest = n2;
	if (smallest > n3) smallest = n3;
	if (smallest > n4) smallest = n4;
	if (smallest > n5) smallest = n5;

	//output smallest and largest
	cout << "Smallest Integer: " << smallest << endl;
	cout << "Largest Integer: " << largest << endl;
}

void getSum() {
	int sum = 0;
	//loop through and find sum of 50 integers divided by 7
	for (int i = 1; i <= 50; i++) {
		sum = sum + (i * 7);
	}
	cout << "Sum of 50 integers divisible by 7: " << sum << endl;
}

void factorial() {
	//create and take user input
	int userNum, factorial = 1;
	cout << "please enter a number: ";
	cin >> userNum;
	//perform calculations for factorial
	for (int i = 1; i <= userNum; i++) {
		factorial = factorial * i;
		cout << factorial << " ";
	}
	cout << "" << endl;
	cout << "This is the factorial of your number: " << factorial << endl;
}

void detPalindrome() {
	//determine variables
	char string[20];
	int length;
	int counter = 0;
	//ask for input
	cout << "Please enter a string: ";
	cin >> string;
	length = strlen(string);
	//loop through each character in the character array
	for (int i = 0; i < length; i++) {
		//loop through and check to see if characters match
		if (string[i] != string[length - i - 1]) {
			counter = 1;
			break;
		}
	}
	//if counter = 1, no palindrome
	if (counter) {
		cout << string << " is is not a palindrome." << endl;
	}
	//otherwise, this is a palindrome
	else {
		cout << string << " is is a palindrome." << endl;
	}
}

void primeNum() {
	//accept input from the user
	cout << "Please enter a number: ";
	int num;
	cin >> num;
	//create integers that modulus by two and three for user input
	int integer = num % 2;
	int integer2 = num % 3;
	//if our integer (which is modulus of 2) = 0, not prime
	if (integer == 0) {
		cout << "this is not a prime number." << endl;
	}
	//if our integer2 (which is modulus of 3) = 0, not prime
	else if (integer2==0){
		cout << "This is not a prime number." << endl;
	}
	//otherwise it is prime
	else {
		cout << "this is a prime number" << endl;
	}
}

void findAvg() {
	//take in user input
	cout << "Please enter five numbers: ";
	double n1, n2, n3, n4, n5;
	cin >> n1 >> n2 >> n3 >> n4 >> n5;
	//set integers into an array
	double arr2[] = { n1, n2, n3, n4, n5 };
	double sum = 0;
	double average;
	double arraySize = sizeof(arr2) / sizeof(double);
	//add all of the integers
	for (int i = 0; i < arraySize; i++) {
		sum = sum + arr2[i];
	}
	//divide the sum by the size of the array
	average = sum/arraySize;
	cout << "The sum of the array is: " << sum << endl;
	cout << "The average of the array is : " << average << endl;
}

void part7() {
	//get number from user
	int size;
	cout << "enter the size: ";
	cin >> size;
	//verify number is positive
	if (size <= 0) {
		cout << "This number is too small.";
		exit(1);
	}
	//create & open file
	ifstream fIn("Text.txt");
	//Verify the file exists
	if (!fIn) {
		cout << "file not found";
		exit(1);
	}

	//make array for the string and ask for space
	string * strArr = new string[size];

	int index = 0;
	string str;

	//read the strings from the file
	while (index < size) {
		//read in a string
		fIn >> str;
		//now put it in the array
		strArr[index] = str;
		index++;
	}

	//determine the longest string
	string longest = strArr[0];
	int i = 1;
	cout << size;
	//go through the array and see if there is a larger one
	while (i < size) {
		if (longest.size() < strArr[i].size()) {
			longest = strArr[i];
		}
		i++;
	}
	cout << longest << endl;
}