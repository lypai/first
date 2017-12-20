#include <iostream>
#include <string>
using namespace std;
class Person
{
	public:
	string name;
	string surname;
	int age;
};
void print(Person* person)
{
	cout << person->name << " " << person->surname <<" is " << person->age << " years old" << endl;
}
int main()
{
	Person person;
	person.name = "Harry";
	person.surname = "Potter";
	person.age = 23;
	cout << "Meet " << person.name << endl;
	print(&person);
	system("pause");
	return 0;
}