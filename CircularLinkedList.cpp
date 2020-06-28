#include <iostream>

using namespace std;

class Node
{
public:
	int key;
	int data;
	Node* next;

	Node()
	{
		key = 0;
		data = 0;
		next = nullptr;
	}

	Node(int key, int data)
	{
		this->key = key;
		this->data = data;
		next = nullptr;
	}
};

class CircularLinkedList
{
public:
	Node* head;

	CircularLinkedList()
	{
		head = nullptr;
	}

	// 1. check node exists or not using key value
	Node* nodeExists(int key)
	{
		Node* temp = nullptr;
		Node* ptr = head;

		if (ptr == nullptr)
			return temp;
		else
		{
			do
			{
				if (ptr->key == key)
				{
					temp = ptr;
					break;
				}
				ptr = ptr->next;
			} while (ptr != head);
			return temp;
		}
	}

	// 2. Append a node
	void appendNode(Node* node)
	{
		if (nodeExists(node->key) != nullptr)
		{
			cout << "Node already exists with the key value: " << node->key << endl;
			cout << "Append another node with different key value." << endl;
		}
		else
		{
			if (head == nullptr)
			{
				head = node;
				node->next = head;
				cout << "Node Appended as Head." << endl;
			}
			else
			{
				Node* ptr = head;
				while (ptr->next != head) // traversing till the end of list
					ptr = ptr->next;
				ptr->next = node;
				node->next = head;
				cout << "Node Appended." << endl;
			}
		}
	}

	// 3. Prepend a node
	void prependNode(Node* node)
	{
		if (nodeExists(node->key) != nullptr)
		{
			cout << "Node already exists with the key value: " << node->key << endl;
			cout << "Append another node with different key value." << endl;
		}
		else
		{
			if (head == nullptr)
			{
				head = node;
				node->next = head;
				cout << "Node Prepended as Head." << endl;
			}
			else
			{
				Node* ptr = head;
				while (ptr->next != head)
					ptr = ptr->next;
				ptr->next = node;
				node->next = head;
				head = node;
				cout << "Node Prepended." << endl;
			}
		}
	}

	// 4. Insert a node after a particular node using key value
	void insertNode(int key, Node* node)
	{
		Node* ptr = nodeExists(key);
		if (ptr == nullptr)
		{
			cout << "No node exists with key value: " << key << endl;
			cout << "Enter a valid Node Key." << endl;
		}
		else
		{
			if (nodeExists(node->key) != nullptr)
			{
				cout << "Node already exists with key value: " << node->key << endl;
				cout << "Enter another Node with different key value." << endl;
			}
			else
			{
				if (ptr->next == head)
				{
					node->next = head;
					ptr->next = node;
					cout << "Node Inserted at the End." << endl;
				}
				else
				{
					node->next = ptr->next;
					ptr->next = node;
					cout << "Node Inserted in between." << endl;
				}
			}
		}
	}

	// 5. Delete a node using key value
	void deleteNode(int key)
	{
		Node* ptr = nodeExists(key);
		
		if (ptr == nullptr)
		{
			cout << "No Node exists with the key value: " << key << ". Enter a valid key value." << endl;
		}
		else
		{
			if (ptr == head)
			{
				if (head->next == head)
				{
					head = nullptr;
					cout << "Head node Unlinked. List is Empty now." << endl;
				}
				else
				{
					Node* temp = head;
					while (temp->next != ptr)
						temp = temp->next;
					temp->next = ptr->next; // or head->next
					head = ptr->next; // or head->next
					cout << "Head Node Unlinked of key value: " << key << endl;
				}
			}
			else
			{
				Node* temp = head;
				while (temp->next != ptr)
					temp = temp->next;
				temp->next = ptr->next;
				cout << "Node Unlinked with key value: " << key << endl;
			}
		}
	}

	// 6. Update Node using key value
	void updateNode(int key, int data)
	{
		Node* ptr = nodeExists(key);
		if (ptr == nullptr)
			cout << "No Node Exists with key value: " << key << ". Operation Aborted." << endl;
		else
		{
			ptr->data = data;
			cout << "Node Data Updated Successfully." << endl;
		}
	}

	// 7. printList
	void printList()
	{
		if (head == nullptr)
			cout << "Circular Linked List is Empty." << endl;
		else
		{
			cout << "Nodes in the Circular Linked List are: (Format- [key|data|next*])" << endl;
			Node* temp = head;
			do
			{
				cout << "[" << temp->key << "|" << temp->data << "|" << temp->next << "]";
				temp = temp->next;
				if (temp != head)
					cout << " --> ";
			} while (temp != head);
			cout << endl;
		}
	}
};

int main()
{
	CircularLinkedList obj;
	int key, data, k;
	int option;

	do
	{
		cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"
			<< "1. appendNode\n"
			<< "2. prependNode\n"
			<< "3. insertNode\n"
			<< "4. deleteNode\n"
			<< "5. updateNode\n"
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
			obj.insertNode(k, node);
			break;
		case 4:
			cout << "Delete Node Operation\n";
			cout << "Enter key of node you want to delete:\n";
			cout << "key - ";
			cin >> key;
			obj.deleteNode(key);
			break;
		case 5:
			cout << "Update Node Operation\n";
			cout << "Enter key of the node you want to update and its new value:\n";
			cout << "key new-value - ";
			cin >> key >> data;
			obj.updateNode(key, data);
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