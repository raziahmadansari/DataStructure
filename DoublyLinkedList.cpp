#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	int key;
	Node* prev;
	Node* next;

	Node()
	{
		data = 0;
		key = 0;
		prev = nullptr;
		next = nullptr;
	}

	Node(int key, int data)
	{
		this->data = data;
		this->key = key;
		prev = nullptr;
		next = nullptr;
	}
};

class DoublyLinkedList
{
public:
	Node* head;

	DoublyLinkedList()
	{
		head = nullptr;
	}

	DoublyLinkedList(Node* node)
	{
		head = node;
	}

	// 1. Check if a node exists using key value
	Node* nodeExists(int key)
	{
		Node* temp = nullptr;
		Node* ptr = head;

		while (ptr != nullptr)
		{
			if (ptr->key == key)
			{
				temp = ptr;
				break;
			}
			ptr = ptr->next;
		}

		return temp;
	}

	// 2. Append a node to the list
	void appendNode(Node* node)
	{
		if (nodeExists(node->key) != nullptr)
			cout << "Node already exists with key value: " << node->key << ". Append another node with different key value." << endl;
		else
		{
			if (head == nullptr)
			{
				head = node;
				cout << "Node appended as Head Node." << endl;
			}
			else
			{
				Node* ptr = head;
				while (ptr->next != nullptr)
				{
					ptr = ptr->next;
				}
				ptr->next = node;
				node->prev = ptr;
				cout << "Node Appended." << endl;
			}
		}
	}

	// 3. Prepend Node - Attach node at the beginning of list
	void prependNode(Node* node)
	{
		if (nodeExists(node->key) != nullptr)
			cout << "Node already exists with key value: " << node->key << ". Append another node with different key value." << endl;
		else
		{
			if (head == nullptr)
			{
				head = node;
				cout << "Node Prepended as Head Node." << endl;
			}
			else
			{
				head->prev = node;
				node->next = head;

				head = node;
				cout << "Node Prepended." << endl;
			}
		}
	}

	// 4. Insert a node after a particular node using key value
	void insertNodeAfter(int key, Node* node)
	{
		Node* ptr = nodeExists(key);
		if (ptr == nullptr)
		{
			cout << "No Node exists with key value: " << key << endl;
		}
		else
		{
			if (nodeExists(node->key) != nullptr)
				cout << "Node already exists with key value: " << node->key << ". Append another node with different key value." << endl;
			else
			{
				cout << "Inserting the node..." << endl;

				Node* nextNode = ptr->next;
				// inserting node at the end
				if (nextNode == nullptr)
				{
					ptr->next = node;
					node->prev = ptr;
					cout << "Node Inserted at the End." << endl;
				}
				else
				{
					node->next = nextNode;
					nextNode->prev = node;
					
					node->prev = ptr;
					ptr->next = node;

					cout << "Node Inserted in Between." << endl;
				}
			}
		}
	}

	// 5. Delete a node by key
	void deleteNodeByKey(int key)
	{
		Node* ptr = nodeExists(key);
		if (ptr == nullptr)
			cout << "No Node exists with key value: " << key << endl;
		else
		{
			if (head->key == key)
			{
				head = head->next;
				head->prev = nullptr;
				cout << "Node UNLINKED with key value: " << key << endl;
			}
			else
			{
				Node* nextNode = ptr->next;
				Node* prevNode = ptr->prev;

				// deleting at the end
				if (nextNode == nullptr)
				{
					prevNode->next = nullptr;
					cout << "Node UNLINKED from the End of list." << endl;
				}
				else
				{
					prevNode->next = nextNode;
					nextNode->prev = prevNode;
					cout << "Node UNLINKED in Between of the list." << endl;
				}
			}
		}
	}

	// 6. Updating the data of node using key value
	void updateNodeByKey(int key, int data)
	{
		Node* ptr = nodeExists(key);
		if (ptr == nullptr)
		{
			cout << "No Node exists with key value: " << key << endl;
		}
		else
		{
			ptr->data = data;
			cout << "Node Data Updated Successfully." << endl;
		}
	}

	// 7. Printing Linked List
	void printList()
	{
		if (head == nullptr)
			cout << "No Nodes in Doubly Linked List." << endl;
		else
		{
			cout << "Nodes in Doubly Linked List are:" << endl;
			cout << "Format: [prev*|key|data|next*]" << endl;
			Node* temp = head;

			while (temp != nullptr)
			{
				cout << "[" << temp->prev << "|" << temp->key << "|" << temp->data << "|" << temp->next << "]";
				temp = temp->next;
				if (temp != nullptr)
					cout << " <--> ";
			}

			cout << endl;
		}
	}
};

int main()
{
	int key, k, data;
	int option;
	DoublyLinkedList obj;

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
			obj.appendNode(node);
			break;
		case 2:
			cout << "Prepend Node Operation\nEnter key and data:\n";
			cout << "key data - ";
			cin >> key >> data;
			node->key = key;
			node->data = data;
			obj.prependNode(node);
			break;
		case 3:
			cout << "Insert Node Operation\n";
			cout << "Enter key of existing node after which you want to insert this node: ";
			cin >> k;
			cout << "Enter key and data of New Node:\n";
			cout << "key data - ";
			cin >> key >> data;
			node->key = key;
			node->data = data;
			obj.insertNodeAfter(k, node);
			break;
		case 4:
			cout << "Delete Node Operation\n";
			cout << "Enter key of node you want to delete:\n";
			cout << "key - ";
			cin >> key;
			obj.deleteNodeByKey(key);
			break;
		case 5:
			cout << "Update Node Operation\n";
			cout << "Enter key of the node you want to update and its new value:\n";
			cout << "key new-value - ";
			cin >> key >> data;
			obj.updateNodeByKey(key, data);
			break;
		case 6:
			cout << "Print Doubly Linked List Operation\n";
			obj.printList();
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