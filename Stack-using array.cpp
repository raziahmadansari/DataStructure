#include <iostream>

const int SIZE = 5;

using namespace std;

class Stack
{
private:
	int top;
	int arr[SIZE];

public:
	Stack()
	{
		top = -1;
		for (int i = 0; i < SIZE; i++)
			arr[i] = 0;
	}

	bool isEmpty()
	{
		if (top == -1)
			return true;
		return false;
	}

	bool isFull()
	{
		if (top == SIZE - 1)
			return true;
		return false;
	}

	void push(int val)
	{
		if (isFull())
			cout << "Stack is full" << endl;
		else
		{
			top++;
			arr[top] = val;
			cout << val << " is inserted" << endl;
		}
	}

	int pop()
	{
		if (isEmpty())
		{
			cout << "Stack underflow" << endl;
			return 0;
		}
		else
		{
			int popValue = arr[top];
			arr[top] = 0;
			top--;
			return popValue;
		}
	}

	int count()
	{
		return (top + 1);
	}

	int peek(int pos)
	{
		if (isEmpty())
		{
			cout << "Stack underflow" << endl;
			return 0;
		}
		else
		{
			return arr[pos];
		}
	}

	void change(int val, int pos)
	{
		if (pos <= top && pos >= 0)
		{
			arr[pos] = val;
			cout << val << " is inserted at " << pos << endl;
		}
		else
		{
			cout << "Entered position is invalid" << endl;
		}
	}

	void display()
	{
		cout << "All values in the stacks are:" << endl;
		cout << "Top -->" << endl;
		
		for (int i = top; i >= 0; i--)
		{
			cout << arr[i] << endl;
		}

		cout << "<-- Bottom" << endl;
	}
};

int main()
{
	Stack s1;
	int option, position, value;

	do
	{
		cout << "What operation you want to do...? select option, Enter 0 to exit" << endl;
		cout << "1. Push" << endl;
		cout << "2. Pop" << endl;
		cout << "3. isEmpty" << endl;
		cout << "4. isFull" << endl;
		cout << "5. peek" << endl;
		cout << "6. count" << endl;
		cout << "7. change" << endl;
		cout << "8. display" << endl;
		cout << "9. clear screen" << endl;
		cout << "0. Exit" << endl << endl;

		cin >> option;

		switch (option)
		{
		case 1:
			cout << "Enter a value to insert in stack: ";
			cin >> value;
			s1.push(value);
			break;
		case 2:
			cout << "Pop function called - Popped value: " << s1.pop() << endl;
			break;
		case 3:
			if (s1.isEmpty())
				cout << "Stack is Empty" << endl;
			else
				cout << "Stack is not Empty" << endl;
			break;
		case 4:
			if (s1.isFull())
				cout << "Stack is Full" << endl;
			else
				cout << "Stack is not Full" << endl;
			break;
		case 5:
			cout << "Enter the position you want to peek: ";
			cin >> position;
			cout << "Peek function called - value at position " << position << " is " << s1.peek(position) << endl;
			break;
		case 6:
			cout << "Count Function called - Number of items in stack are: " << s1.count() << endl;
			break;
		case 7:
			cout << "Enter a Value: ";
			cin >> value;
			cout << "Enter position where you want to insert: ";
			cin >> position;
			cout << "change Function called" << endl;
			s1.change(value, position);
			break;
		case 8:
			cout << "display Function called" << endl;
			s1.display();
			break;
		case 9:
			system("cls");
			break;
		default:
			cout << "Enter proper option number :(" << endl << endl;
		}

		cout << endl << endl;
	} while (option != 0);

	return 0;
}