#include <iostream>
#include <windows.h>

using namespace std;

void printArray(int arr[], int size, int step)
{
	cout << "Step[" << step << "]. --> ";
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
	Sleep(700);
}

void swap(int* first, int* second)
{
	int* temp = second;
	second = first;
	first = temp;
}

void bubbleSort(int arr[], int size)
{
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (arr[j + 1] < arr[j])
				swap(arr[j + 1], arr[j]);
		}
		printArray(arr, size, i + 1);
	}
}

int main()
{
	int arr[] = { 20, 15, 25, 10, 55, 44 };
	int size = sizeof(arr) / sizeof(arr[0]);

	cout << "Unsorted Array - " << endl;
	printArray(arr, size, -1);

	bubbleSort(arr, size);

	cout << "Sorted Array   - " << endl;
	printArray(arr, size, -1);

	return 0;
}