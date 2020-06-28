#include <iostream>

using namespace std;

int linearSearch(int* arr, int search, int size)
{
	int i = 0;
	for (; i < size; i++)
		if (arr[i] == search)
			return i;
	return i;
}

int main()
{
	int size;
	cout << "Enter size of Array: ";
	cin >> size;

	int* arr = new int[size];
	cout << "Enter " << size << " items to the array: ";

	for (int i = 0; i < size; i++)
		cin >> arr[i];

	int search;
	cout << "Enter Value you want to search: ";
	cin >> search;

	int index = linearSearch(arr, search, size);

	if (index == size)
		cout << search << " Not found in this List." << endl;
	else
		cout << search << " found at position: " << i << endl;

	delete[] arr;
	arr = nullptr;

	return 0;
}
