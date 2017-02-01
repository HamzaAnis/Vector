// Name        : LouisLab12.cpp



#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "intsequence.h"

using namespace std;

void pause_215(bool have_newline);

int main()
{
	int size = 0;
	const int RANGE = 100;   // the num in the sequence is in [0, 99]
	while (true)
	{
		// Ask the user for the size of the sequence until the user enters "Q" to quit
		cout << "Enter the number of integers in the sequence (Enter 'q' to stop):";
		cin >> size;
		cin.ignore(256, '\n');

		if (cin.fail())
		{
			cin.clear();
			string input_to_check;
			cin >> input_to_check;
			if (input_to_check == "Q" || input_to_check == "q")
				break;
			cout << "Invalid number!" << endl;
			continue;
		}
		if (size <= 0)
		{
			cout << "The number should be positive!" << endl;
			continue;
		}
		// the size is valid, create an instance of mySequence
		IntSequence mySequence;
		srand(time(NULL));
		for (int i = 0; i < size; i++)
		{
			int num = rand() % RANGE;
			mySequence.insert(num);
		}
		mySequence.print();

		int key = 0;
		while (true)
		{
			cout << "Enter the integer you want to search for(Enter 'q' to stop):";
			cin >> key;
			cin.ignore(256, '\n');
			if (cin.fail())
			{
				cin.clear();
				string input_to_check;
				cin >> input_to_check;
				if (input_to_check == "Q" || input_to_check == "q")
					break;
				cout << "Invalid number!" << endl;
				continue;
			}
			// using the sequence search algorithm to search for the key
			cout << "Sequential Searching..." << endl;
			int index = mySequence.sequential_search(key);
			if (index == -1)
				cout << "Key not Found" << endl;
			else
				cout << "Key found at index " << index << endl;

			// using the binary search algorithm to search for the key
			// the condition is the sequence is sorted in non-decreasing order first
			cout << "Unsorted ";
			mySequence.print();
			// using the bubble sorting algorithm to sort the sequence in non-decreasing order
			mySequence.bubble_sort();
			cout << "Sorted ";
			mySequence.print();
			cout << "Binary Searching..." << endl;
			index = mySequence.binary_search(key);
			if (index == -1)
				cout << "Key not Found" << endl;
			else
				cout << "Key found at index " << index << endl;

			// shuffle the numbers in the sequence for the next searching iteration
			cout << "Shuffle the numbers in the sequence..." << endl;
			mySequence.shuffle();
			mySequence.print();
		}
	}
	cout << "Thank you for using my program." << endl;
	pause_215(true);
	return 0;
}

void pause_215(bool have_newline)
{
	if (have_newline) {
		// Ignore the newline after the user's previous input.
		cin.ignore(256, '\n');
	}

	// Prompt for the user to press ENTER, then wait for a newline.
	cout << endl << "Press ENTER to continue." << endl;
	cin.ignore(256, '\n');
}
