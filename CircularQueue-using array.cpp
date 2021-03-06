#include <iostream>

const int SIZE = 5;

using namespace std;

class CircularQueue
{
private:
	int front;
	int rear;
	int arr[SIZE] = { 0 };
	int itemCount;

public:
	CircularQueue()
	{
		front = rear = -1;
		itemCount = 0;
	}

	bool isEmpty()
	{
		if (front == -1 && rear == -1)
			return true;
		return false;
	}

	bool isFull()
	{
		if ((rear + 1) % SIZE == front)
			return true;
		return false;
	}

	void enqueue(int val)
	{
		if (isFull())
		{
			cout << "Queue is Full";
			return;
		}
		else if (isEmpty())
			rear = front = 0;
		else
			rear = (rear + 1) % SIZE;
		arr[rear] = val;
		itemCount++;
	}

	int dequeue()
	{
		int x;

		if (isEmpty())
		{
			cout << "Queue is Empty" << endl;
			return 0;
		}
		else if (front == rear) // Only one element is in Queue
		{
			x = arr[front];
			arr[front] = 0;
			front = rear = -1;
			itemCount = 0; // Queue is empty now
			return x;
		}
		else
		{
			x = arr[front];
			arr[front] = 0;
			front = (front + 1) % SIZE;
			itemCount--;
			return x;
		}
	}

	int count()
	{
		return itemCount;
	}

	void display()
	{
		cout << "Elements in Queue are:" << endl;
		cout << "First --> ";
		for (int i = 0; i < SIZE; i++)
		{
			cout << arr[i] << " --> ";
		}
		cout << "rear" << endl;
	}
};

int main()
{
	CircularQueue q1;
	int option, value;

	do
	{
		cout << "\nWhat operation you want to perform? Select option number, Enter 0 to quit." << endl;
		cout << "1. Enqueue" << endl
			<< "2. Dequeue" << endl
			<< "3. isEmpty" << endl
			<< "4. isFull" << endl
			<< "5. count" << endl
			<< "6. display" << endl
			<< "7. Clear Screen" << endl
			<< "0. Exit" << endl;
		cin >> option;

		switch (option)
		{
		case 1:
			cout << "Enter a value: ";
			cin >> value;
			cout << "Enqueue Function called" << endl;
			q1.enqueue(value);
			break;
		case 2:
			cout << "Dequeue Function called" << endl;
			cout << "Dequeued value : " << q1.dequeue() << endl;
			break;
		case 3:
			cout << "isEmpty Function called" << endl;
			if (q1.isEmpty())
				cout << "Queue is Empty" << endl;
			else
				cout << "Queue is not Empty" << endl;
			break;
		case 4:
			cout << "isFull Function called" << endl;
			if (q1.isFull())
				cout << "Queue is Full" << endl;
			else
				cout << "Queue is not Full" << endl;
			break;
		case 5:
			cout << "count Function called" << endl;
			cout << "Elements in Queue are: " << q1.count() << endl;
			break;
		case 6:
			cout << "display Function called" << endl;
			q1.display();
			break;
		case 7:
			system("cls");
			break;
		default:
			cout << "Select a valid option :(" << endl;
		}
	} while (option != 0);

	return 0;
}