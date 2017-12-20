#include <iostream>
using namespace std;

class FlightBooking {
	public:
	FlightBooking(int id, int capacity, int reserved);
	void printStatus();
	private:
	int id;
	int capacity;
	int reserved;
};
void FlightBooking::printStatus()
{
	cout.precision(0);
	double pers = (reserved*100./capacity);
	cout << "Flight " << id << " : " << reserved << "/" 
		<< capacity << " ("  << fixed << pers << "%) seats reserved" << endl;
}
FlightBooking::FlightBooking(int _id, int _capacity, int _reserved)
{
	id = _id;
	capacity = _capacity;
	reserved = _reserved;
}
int main() {
	int reserved = 0,
	capacity = 0;
	std::cout << "Provide flight capacity: ";
	std::cin >> capacity;
	std::cout << "Provide number of reserved seats: ";
	std::cin >> reserved;
	FlightBooking booking(1, capacity, reserved);
	booking.printStatus();
	system("pause");
	return 0;
}