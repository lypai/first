#include <iostream>
using namespace std;
class Node
{
	public:
	Node(int val);
	~Node();
	int value;
	Node* next;
};
Node::Node(int val) : value(val), next(nullptr)
{
//cout << "+Node" << endl;
}
Node::~Node()
{
//cout << "-Node" << endl;
}
class List
{
	public:
	List();
	~List();
	int size();	void push_front(int value);
	bool pop_front(int *value);
	void push_back(int value);
	bool pop_back(int *value);
	int at(int index);
	void insert_at(int index, int value);
	void remove_at(int index);
	private:
	Node* head;
	Node* tail;
};

void printList(List list)
{
	for (int i = 0; i < list.size(); i++)
	{
		cout << "list[" << i << "] == " << list.at(i) << endl;
	}
	cout << "end of print" << endl;
}

int List::at(int index)
{
	Node* current = head;
	int val = 0;
	int i = 0;
	while(current->next != nullptr)
	{
		if(i == index)
		{
			return current->value;
		}
		current = current->next;
		i++;
	}
	return current->value;
}

void List::insert_at(int index, int value)
{
	Node* current = head;
	int val = 0;
	int i = 0;
	while(current->next != tail)
	{
		if(i == (index - 1))
		{
			Node* next = current->next;
			Node* inserted = new Node(value);
			current->next = inserted;
			inserted->next = next;
			break;
		}
		current = current->next;
		i++;
	}
}

void List::remove_at(int index)
{
	Node* current = head;
	int val = 0;
	int i = 0;
	while(current->next != tail)
	{
		if(i == (index - 1))
		{
			current->next = current->next->next;
			break;
		}
		current = current->next;
		i++;
	}
}

int List::size()
{
	int size = 0;
	Node* temp = head;
	while(temp != nullptr)
	{
		temp = temp->next;
		size++;
	}
	return size;
}

List::~List()
{
	while(head != nullptr)
	{
		push_front(0);
	}
}
List::List() : head(nullptr)
{
}void List::push_front(int value)
{	
	Node* new_head = new Node(value);
	if(head == nullptr) {
		head = new_head;
		tail = new_head;
	}
	//new_head->next = head;
	//head=new_head;
	tail->next = new_head;
	tail = new_head;
}

bool List::pop_front(int *value)
{
	if (head == nullptr)
		return false;
	Node* current = head;
	*value = head->value;
	head = head->next;
	delete current;
	return true;
}

bool List::pop_back(int *value)
{
	if (head == nullptr || tail == nullptr)
		return false;
	Node* current = head;	
	if(current->next == nullptr)
	{
		*value = head->value;
		tail = nullptr;
		head = nullptr;
		delete tail;
		delete head;
	}
	else
	{
		while(current->next != tail)
		{
			current = current->next;		
		}
		tail = current;
		*value = current->next->value;
		current->next = nullptr;
		delete current->next;
	}
	return true;
}

void List::push_back(int value)
{
	Node* second_head = new Node(value);
	if(head == nullptr) 
	{
		head = second_head;
		tail = second_head;
	}
	else
	{
		tail->next = second_head;
		tail = second_head;
	}
}

int main()
{
	List list;
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);
	printList(list);
	list.remove_at(2);
	printList(list);
	cout << endl;
	list.insert_at(1, 6);
	printList(list);
	system("pause");
	return 0;
}