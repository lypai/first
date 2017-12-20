#include <iostream>
#include <string>
using namespace std;

class ShopItemOrder
{
public : 
		ShopItemOrder(string _name, double _price, int _count)
		{
			name = _name;
			unit_price = _price;
			ordered_items_count = _count;
		}
		void print()
		{
			cout << "Item name: " << name << "\nItem unit price: "
				<< unit_price << "\nNumber of items ordered: "
				<< ordered_items_count << endl;
		}
		double get_total_price()
		{
			return unit_price * ordered_items_count;
		}
		string get_name()
		{
			return name;
		}
		void set_name(string new_name)
		{
			name = new_name;
		}
		double get_unit_price()
		{
			return unit_price;
		}
		void set_unit_price(double new_price)
		{
			unit_price = new_price;
		}
		int get_ordered_count()
		{
			return ordered_items_count;
		}
		void set_ordered_count(int new_count)
		{
			ordered_items_count = new_count;
		}
private: 
	    string name;
		double unit_price;
		int ordered_items_count;

		 
};

int main()
{
	ShopItemOrder order("Apple", 20.00, 2);
	order.print();
	cout << "Total price: " << order.get_total_price() << endl;
	order.set_unit_price(15.00);
	cout << "Now unit price: " << order.get_unit_price() << endl;
	order.print();
	cout << "Now total price: " << order.get_total_price() << endl;
	system("pause");
	return 0;
}