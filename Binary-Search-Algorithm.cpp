#include <iostream>

using namespace std;

int binarySearch(int arr[], int search, int size)
{
	int Left = 0;
	int Right = size - 1;
	int Mid = (Left + Right) / 2;

	while (Left <= Right)
	{
		if (arr[Mid] == search)
			return Mid;
		else if (search < arr[Mid])
			Right = Mid - 1;
		else
			Left = Mid + 1;
		Mid = (Left + Right) / 2;
	}
	return size;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int size = sizeof(arr) / sizeof(arr[0]);
	
	cout << "Elements inside of the array are:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i];
		if (i < (size - 1))
			cout << ", ";
	}
	cout << endl;

	cout << "Enter a number to search: ";
	int search;
	cin >> search;

	int index = binarySearch(arr, search, size);

	if (index == size)
		cout << search << " Not found in this list." << endl;
	else
		cout << search << " Found at index: " << index << endl;

	return 0;
}