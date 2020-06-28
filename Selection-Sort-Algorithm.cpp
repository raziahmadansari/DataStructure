#include <iostream>

using namespace std;

void selectionSort(int arr[], int size)
{
	int min = 0;
	for (int i = 0; i < size - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[min])
				min = j;
		}
		// swapping the values
		if (min != i)
		{
			int temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}

int main()
{
	int arr[] = { 1, 20, 5, 10, 23, 2, 15 };

	int size = sizeof(arr) / sizeof(arr[0]);

	cout << "unsorted array - ";
	for (int x : arr)
		cout << x << " ";
	cout << endl;
	
	selectionSort(arr, size);

	cout << "sorted array   - ";
	// using foreach loop to print the array
	for (int x : arr)
		cout << x << " ";
	cout << endl;

	return 0;
}