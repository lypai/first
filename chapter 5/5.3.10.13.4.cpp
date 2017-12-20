#include <iostream>
#include <string>
using namespace std;

class FlightBooking {
	public:
	static const int LIMIT = 105;
	FlightBooking(int id, int capacity, int reserved);
	FlightBooking();
	void printStatus();
	bool reserveSeats(int number_ob_seats);
	bool cancelReservations(int number_ob_seats);	int getId() { return id; };
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
FlightBooking::FlightBooking()
{
	id = 0;
	capacity = 0;
	reserved = 0;
}
bool FlightBooking::reserveSeats(int number_ob_seats)
{
	if (((reserved + number_ob_seats)*100./capacity) > LIMIT) {
		cout << "Cannot perform this operation: capacity reached" << endl;
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
	FlightBooking booking[10];
	int flightCount = 0;
	string command = "";
	string quit = "quit";
	bool isFlights = false;
		for(int i = 0; i < 10; i++)
		{
			if(booking[i].getId() != 0) 
			{					
				booking[i].printStatus();
				isFlights = true;
			}
		}
		if(!isFlights) cout << "No flights in the system" << endl;
	
	while (command != quit)
	{
		cout << "What would you like to do?: ";
		cin >> command;
		if(command == quit) break;
		int id = 0;
		cin >> id;
	    if(command == "create")
		{
			int cap;
			cin >> cap;
			if(flightCount < 10)
			{
				for(int i = 0; i < 10; i++)
				{
					if(booking[i].getId() == 0) 
					{
						booking[i] = FlightBooking(id, cap, 0);		
						flightCount++;
						break;
					}				
				}
				
			}
			else cout << "Cannot perform this operation" << endl;

		}
		if(command == "delete")
		{
			bool deleted = false;
			for(int i = 0; i < 10; i++)
			{
				if(booking[i].getId() == id) 
				{
					booking[i] = FlightBooking();	
					deleted = true;
				}				
			}
			if(!deleted) cout << "Cannot perform this operation: flight "
				<< id << " not found" << endl;
		}
		if(command == "add")
		{
			bool added = false;
			int res;
			cin >> res;
			for(int i = 0; i < 10; i++)
			{
				if(booking[i].getId() == id)
				{
					booking[i].reserveSeats(res);
					added = true;
				}
			}
			if(!added) cout << "Cannot perform this operation: flight "
				<< id << " not found" << endl;
		}
		if(command == "cancel")
		{
			int n;
			cin >> n;
			for(int i = 0; i < 10; i++)
			{
				if(booking[i].getId() == id)
				{
					booking[i].cancelReservations(n);
				}
			}			
		}
		isFlights = false;
		for(int i = 0; i < 10; i++)
		{
			if(booking[i].getId() != 0) 
			{					
				booking[i].printStatus();
				isFlights = true;
			}
		}
		if(!isFlights) cout << "No flights in the system" << endl;
	}
	system("pause");
	return 0;
}