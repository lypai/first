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
	private:
	Node* head;
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
int main()
{
	List list;
	for (int i = 0; i <= 5; i++)
	{
		list.push_front(i);
		cout << "pushed " << i << ", size: " << list.size() << endl;
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		int value = 0;
		list.pop_front(&value);
		cout << "popped " << value << ", size: " << list.size() << endl;
	}
	system("pause");
	return 0;
}