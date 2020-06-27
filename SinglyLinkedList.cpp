#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	int key; // key is used to uniquely distinguish each node
	Node* next;

	Node()
	{
		data = 0;
		key = 0;
		next = nullptr;
	}

	Node(int key, int data)
	{
		this->key = key;
		this->data = data;
		this->next = nullptr;
	}
};

class SinglyLinkedList
{
public:
	Node* head;

	SinglyLinkedList()
	{
		head = nullptr;
	}

	SinglyLinkedList(Node* n) // pass by address
	{
		head = n;
	}

	// 1. check if node exists using key value
	Node* nodeExists(int key)
	{
		Node* temp = nullptr;

		Node* ptr = head;

		while (ptr != nullptr)
		{
			if (ptr->key == key)
			{
				temp = ptr;
			}
			ptr = ptr->next;
		}

		return temp;
	}

	// 2. append a node to the list
	void appendNode(Node* node)
	{
		if (nodeExists(node->key) != nullptr)
		{
			cout << "Node already exists with key value : " << node->key << ". Append another node with different key value." << endl;
		}
		else
		{
			if (head == nullptr) // appending the first node
			{
				head = node;
			}
			else // list contains atleast 1 node
			{
				Node* ptr = head;
				while (ptr->next != nullptr)
					ptr = ptr->next;
				ptr->next = node;
			}
			cout << "Node appended" << endl;
		}
	}

	// 3. Prepend Node - Attach the node at the beginning
	void prependNode(Node* node)
	{
		if (nodeExists(node->key) != nullptr)
		{
			cout << "Node already exists with key value : " << node->key << ". Append another node with different key value." << endl;
		}
		else
		{
			node->next = head;
			head = node;
			cout << "Node prepended." << endl;
		}
	}

	// 4. Insert a node after a particular node
	void insertNodeAfter(int key, Node* node) // key is after which node we want to attach new node
	{
		Node* ptr = nodeExists(key);
		if (ptr == nullptr)
			cout << "No node exists with key value: " << key << endl;
		else
		{
			if (nodeExists(node->key) != nullptr)
			{
				cout << "Node already exists with key value : " << node->key << ". Append another node with different key value." << endl;
			}
			else
			{
				node->next = ptr->next;
				ptr->next = node;
				cout << "Node inserted." << endl;
			}
		}
	}

	// 5. Delete node by unique key
	void deleteNodeByKey(int key)
	{
		if (head == nullptr)
			cout << "Singly Linked List already Empty. Can't delete." << endl;
		else if (head != nullptr)
		{
			if (head->key == key)
			{
				head = head->next;
				cout << "Node Unlinked from the list." << endl;
			}
			else
			{
				Node* temp = nullptr;
				Node* prevptr = head;
				Node* currentptr = head->next;

				while (currentptr->next != nullptr)
				{
					if (currentptr->key == key)
					{
						temp = currentptr;
						//currentptr = nullptr; // when we get the required node we make currentptr as null to exit from loop
						break;
					}
					else
					{
						prevptr = prevptr->next;
						currentptr = currentptr->next;
					}
				}

				if (temp != nullptr)
				{
					prevptr->next = temp->next;
					cout << "Node UNLINKED with key value: " << key << endl;
				}
				else
					cout << "Node doesn't exist with key value: " << key << endl;
			}
		}
	}

	// 6. Update node by key
	void updateNodeByKey(int key, int data)
	{
		Node* ptr = nodeExists(key); // if the pointer exist with the passed key value then ptr will have the address
									 // of that node else it will hold nullptr or NULL.
		if (ptr != nullptr)
		{
			ptr->data = data;
			cout << "Node Data updated successfully." << endl;
		}
		else
			cout << "Node doesn't exist with key value: " << key << endl;
	}

	// 7. print
	void printList()
	{
		if (head == nullptr)
			cout << "No Nodes in Singly Linked List." << endl;
		else
		{
			cout << "\nKey and Values in Singly Linked List: [key|value]" << endl;
			Node* temp = head;

			while (temp != nullptr)
			{
				cout << "[" << temp->key << "|" << temp->data << "]";
				temp = temp->next;
				if (temp != nullptr)
					cout << " --> ";
			}
			cout << endl;
		}
	}
};

int main()
{
	SinglyLinkedList s;
	int option;
	int key, k, data;

	do
	{
		cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"
			<< "1. appendNode\n"
			<< "2. prependNode\n"
			<< "3. insertNodeAfter\n"
			<< "4. deleteNodeByKey\n"
			<< "5. updateNodeByKey\n"
			<< "6. print\n"
			<< "7. clear screen\n"
			<< "0. exit\n\n";

		cin >> option;
		Node* node = new Node(); // dynamic memory allocation (heap memory)
		//Node node; // This is static memory allocation (stack memory)

		switch (option)
		{
		case 1:
			cout << "Append Node Operation\nEnter key and data:\n";
			cout << "key data - ";
			cin >> key >> data;
			node->key = key;
			node->data = data;
			s.appendNode(node);
			break;
		case 2:
			cout << "Prepend Node Operation\nEnter key and data:\n";
			cout << "key data - ";
			cin >> key >> data;
			node->key = key;
			node->data = data;
			s.prependNode(node);
			break;
		case 3:
			cout << "Insert Node Operation\n";
			cout << "Enter key of existing node after which you want to insert this node: ";
			cin >> k;
			cout << "Enter key and data of New Node:\n";
			cout << "key data - ";
			cin >> key >> data;
			s.insertNodeAfter(k, node);
			break;
		case 4:
			cout << "Delete Node Operation\n";
			cout << "Enter key of node you want to delete:\n";
			cout << "key - ";
			cin >> key;
			s.deleteNodeByKey(key);
			break;
		case 5:
			cout << "Update Node Operation\n";
			cout << "Enter key of the node you want to update and its new value:\n";
			cout << "key new-value - ";
			cin >> key >> data;
			s.updateNodeByKey(key, data);
			break;
		case 6:
			cout << "Print Singly Linked List Operation\n";
			s.printList();
			break;
		case 7:
			system("cls");
			break;
		default:
			cout << "Select a valid option. :(" << endl;
		}
	} while (option != 0);

	return 0;
}