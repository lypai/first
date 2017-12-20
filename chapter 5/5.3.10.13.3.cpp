#include <iostream>
#include <string>
using namespace std;

class FlightBooking {
	public:
	static const int LIMIT = 105;
	FlightBooking(int id, int capacity, int reserved);
	void printStatus();
	bool reserveSeats(int number_ob_seats);
	bool cancelReservations(int number_ob_seats);
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
	double pers = _reserved * 100. / _capacity;
	if(pers > LIMIT)
	{
		capacity = _capacity;
		reserved = LIMIT * _capacity/ 100;
	}
	else 
		{ 
			capacity = _capacity;
			reserved = _reserved;
	}
}
bool FlightBooking::reserveSeats(int number_ob_seats)
{
	if (((reserved + number_ob_seats)*100./capacity) > LIMIT) {
		cout << "Cannot perform this operation" << endl;
		return false;
	}
	reserved += number_ob_seats;
	return true;
}
bool FlightBooking::cancelReservations(int number_ob_seats)
{
	if(reserved - number_ob_seats >= 0) 
	{
		reserved -= number_ob_seats;
		return true;
	}
	cout << "Cannot perform this operation" << endl;
	return false;
}

int main() {
	int reserved = 0,
	capacity = 0;
	cout << "Provide flight capacity: ";
	cin >> capacity;
	cout << "Provide number of reserved seats: ";
	cin >> reserved;
	FlightBooking booking(1, capacity, reserved);
	string command = "";
	string quit = "quit";
	while (command != quit)
	{
	booking.printStatus();
	cout << "What would you like to do?: ";
	cin >> command;
	if(command == quit) break;
	int number = 0;
	cin >> number;
	
	if(command == "add") booking.reserveSeats(number);
	if(command == "cancel") booking.cancelReservations(number);
	}
	system("pause");
	return 0;
}