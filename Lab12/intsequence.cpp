#include <iostream>
#include "intsequence.h"

using namespace std;
IntSequence::IntSequence()
{
	sequence.clear();
}

IntSequence::IntSequence(const IntSequence &other)
{
	this->sequence = other.sequence;
}

IntSequence& IntSequence::operator= (const IntSequence &other)
{
	this->sequence = other.sequence;
	return *this;
}



void IntSequence::insert(int item)
{
	sequence.push_back(item);
}

int IntSequence::getSize() const
{
	return sequence.size();
}

bool IntSequence::isEmpty() const
{
	if (sequence.size())
		return true;
	else
		return false;
}

void IntSequence::print() const
{
	for (int i = 0; i <(int)sequence.size(); i++)// cast to int the size of the vector
	{
		cout << sequence[i] << " ";
	}
	cout << endl;
}
void IntSequence::bubble_sort()
{


	int i, j;
	int temp;             // for swapping
	int numLength = sequence.size();
	for (i = 1; (i <= numLength); i++)
	{
		for (j = 0; j < (numLength - 1); j++)
		{
			if (sequence[j + 1] < sequence[j])      // ascending order
			{
				temp = sequence[j];             // swap elements
				sequence[j] = sequence[j + 1];
				sequence[j + 1] = temp;
			}


		}
	}


}

void IntSequence::selection_sort()
{
	int min, temp;
	int n = sequence.size();

	for (int i = 0; i < n - 1; i++)
	{
		min = i;//set min to the current index of array

		for (int j = i + 1; j < n; j++)
		{

			if (sequence[j] < sequence[min])
				min = j;
			//min will keep track of the index that min is in, this is needed when a swap happens
		}

		//if min no longer equals i than a smaller value must have been found, so a swap must occur
		if (min != i)
		{
			temp = sequence[i];
			sequence[i] = sequence[min];
			sequence[min] = temp;
			cout << "Min " << sequence[i] << ",swap with  " << sequence[min] << ":\n";
		}
	}
}

void IntSequence::merge_sort(int leftMost, int rightMost)
{
	int mid;
	if (leftMost<rightMost)
	{
		mid = (leftMost + rightMost) / 2;
		merge_sort(leftMost, mid);
		merge_sort(mid + 1, rightMost);
		merge_sort_helper(leftMost, mid, rightMost);

		cout << "Sub vector 1:\n";
		for (int i = leftMost; i <= mid; i++)
		{
			cout << sequence[i] << " ";
		}
		cout << "\nSub vector 2:\n";
		for (int i = mid + 1; i <= rightMost; i++)
		{
			cout << sequence[i] << " ";
		}
		cout << "\nMerged vector:\n";
		for (int i = leftMost; i <= rightMost; i++)
		{
			cout << sequence[i] << " ";
		}
		cout << endl;
	}
}


void IntSequence::merge_sort_helper(int leftMost, int mid, int rightMost)
{
	int h, i, j, k;
	vector<int> temp(sequence.size());
	h = leftMost;
	i = leftMost;
	j = mid + 1;

	while ((h <= mid) && (j <= rightMost))
	{
		if (sequence[h] <= sequence[j])
		{
			temp[i] = sequence[h];
			h++;
		}
		else
		{
			temp[i] = sequence[j];
			j++;
		}
		i++;
	}
	if (h > mid)
	{
		for (k = j; k <= rightMost; k++)
		{
			temp[i] = sequence[k];
			i++;
		}
	}
	else
	{
		for (k = h; k <= mid; k++)
		{
			temp[i] = sequence[k];
			i++;
		}
	}
	for (k = leftMost; k <= rightMost; k++)
	{
		sequence[k] = temp[k];
	}
}


int IntSequence::sequential_search(int key) const
{
	int indexNumber = -1; //-1 if not found

	int size = (int)sequence.size();
	for (int i = size - 1; i >0; i--)  // cast to int the size of the vector
	{
		if (sequence[i] == key)   // if match is found
		{
			indexNumber = i;    // break out of for loop
		}
	}
	return indexNumber;
}



void IntSequence::shuffle()
{
	int index;
	int size = sequence.size();
	for (int i = size - 1; i > 0; i--)
	{

		//will create a unique random value evry time
		srand(time(NULL));
		index = rand() % size;
		/*Swap*/
		int temp;
		temp = sequence[i];
		sequence[i] = sequence[index];
		sequence[index] = temp;
		/*Swap*/
	}
}

int IntSequence::binary_search(int key)
{

	int leftIndex = 0;
	int rightIndex = sequence.size() - 1;
	int index = binary_search_helper(key, leftIndex, rightIndex);

	return index;
}

int IntSequence::binary_search_helper(int key, int leftindex, int rightindex)
{
	int index;
	if (leftindex > rightindex)
		index = -1;

	else
	{
		int mid = (leftindex + rightindex) / 2;

		if (key == sequence[mid])
			index = mid;
		else

			if (key < sequence[mid])
				index = binary_search_helper(key, leftindex, mid - 1);
			else
				index = binary_search_helper(key, mid + 1, rightindex);
	}
	return index;
}


IntSequence::~IntSequence()
{

}
