#include <iostream>
#include <windows.h>

using namespace std;

void printArray(int arr[], int size, int step)
{
	cout << "Step[" << step << "]. --> ";
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
	Sleep(500);
}

void insertionSort(int arr[], int size)
{
	int i, key, j;
	for (i = 1; i < size; i++)
	{
		key = arr[i]; // for temporarily storing the value of current index
		j = i - 1;
		
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j -= 1;
		}

		arr[j + 1] = key;
		printArray(arr, size, i);
	}
}

int main()
{
	int arr[] = { 10, 5, 15, 9, 25, 56, 23 };
	decltype(sizeof(arr[0])) size = sizeof(arr) / sizeof(arr[0]);

	cout << "Unsorted Array - ";
	for (decltype(arr[0]) x : arr)
		cout << x << " ";
	cout << endl;

	insertionSort(arr, size);

	cout << "Sorted Array   - ";
	for (decltype(arr[0]) x : arr)
		cout << x << " ";
	cout << endl;

	return 0;
}