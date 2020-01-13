#include <iostream>
#include <string>

class Node
{
public:
	void *data;
	Node *next;
	Node(void *d, Node* n = NULL)
	{
		data = d;
		next = n;
	}
	~Node()
	{
		delete data;
		delete next;
	}
};

class LinkedList
{
private:
	Node* head;
	int size;

public:

	LinkedList()
	{
		head = NULL;
		size = 0;
	}

	~LinkedList()
	{
		delete head;
	}

	void insertFirst(void *data)
	{
		head = new Node(data, head);
		size++;
	}

	void insertLast(void *data)
	{
		Node* node = new Node(data);
		Node* current = NULL;

		if (head == NULL)
		{
			head = node;
		}

		else
		{
			current = head;
			while (current->next)
			{
				current = current->next;
			}
			current->next = node;
		}

		size++;
	}

	void insertAt(int index, void *data)
	{
		if (index > 0 && index > size)
		{
			return;
		}
		if (index == 0)
		{
			head = new Node(data, head);
			return;
		}

		Node* node = new Node(data);
		Node* previous = NULL;
		Node* current = head;
		int count = 0;

		while (count < index)
		{
			previous = current;
			count++;
			current = current->next;
		}
		node->next = current;
		previous->next = node;
		size++;
	}

	void removeAt(int index)
	{
		if (index < 0 || index > size)
		{
			std::cout << "Out of bounds." << std::endl;
			return;
		}
		Node* current = head;
		Node* previous = NULL;
		int count = 0;
		if (index == 0)
		{
			head = current->next;
		}
		else
		{
			while (count < index)
			{
				count++;
				previous = current;
				current = current->next;
			}
			previous->next = current->next;
		}
		size--;
	}

	void getAt(int index)
	{
		int count = 0;
		Node* current = head;
		if (index < 0 || index > size)
		{
			std::cout << "Out of bounds." << std::endl;
			return;
		}
		while (current != NULL)
		{
			if (count == index)
			{
				std::cout << *(std::string*)current->data << std::endl;
				return;
			}
			count++;
			current = current->next;
		}
	}

	void clearList()
	{
		head = NULL;
		size = 0;
	}

	void printList()
	{
		Node* current = head;
		while (current)
		{
			std::cout << *(std::string*)current->data << std::endl;
			current = current->next;
		}
	}

	int getSize()
	{
		return size;
	}
};

int main(void)
{
	LinkedList* head = new LinkedList;
	std::string msg = "Hello world";
	std::string msg2 = "Goodbye world";
	std::string msg3 = "I'm last";
	std::string msg4 = "I was placed here";

	head->insertFirst(&msg);
	head->insertFirst(&msg2);
	head->insertLast(&msg3);
	head->insertAt(2, &msg4);

	head->printList();
	std::cout << head->getSize() << std::endl;
	std::cout << "" << std::endl;

	head->removeAt(2);
	head->printList();
	std::cout << head->getSize() << std::endl;
	head->getAt(2);

	system("pause");
}