#include <iostream>

using namespace std;

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

	int i = 0;
	for (; i < size; i++)
	{
		if (arr[i] == search)
		{
			cout << search << " found at positioin: " << i << endl;
			break;
		}
	}

	if (i == size)
		cout << search << " Not found in this List." << endl;

	return 0;
}