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
	private:
	Node* head;
	Node* tail;
};

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
	if(head == nullptr) tail = new_head;
	new_head->next = head;
	head=new_head;
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
	//
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	int value = 0;
	while (list.pop_front(&value))
	{
		cout << value << endl;
	}
	system("pause");
	return 0;
}