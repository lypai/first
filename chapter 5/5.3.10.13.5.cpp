#include <iostream>
#include <string>
using namespace std;

class GymMember{
	public:
	static const int LIMIT = 105;
	GymMember(int id, string name, int monthCount);
	GymMember();
	void printMember();	int getId() { return id; };	bool Cancel();	bool Extend(int month);
	private:
	int id;
	string name;
	int monthCount;
};

GymMember::GymMember(int _id, string _name, int _monthCount)
{
	id = _id;
	name = _name;
	monthCount = _monthCount;
}

GymMember::GymMember()
{
	id = 0;
	name = "";
	monthCount = 0;
}

void GymMember::printMember()
{
	cout << "Member " << id << " : " << name 
		<< ", subscription valid for " << monthCount << " months" << endl;
}

bool GymMember::Cancel()
{
	monthCount = 0;
	return false;
}

bool GymMember::Extend(int _month)
{
	if(_month > 0)
	{
		monthCount += _month;
		return true;
	}
	else cout << "Cannot perform this operation" << endl;
	return false;
}
 
void PrintMembers(GymMember membs[])
{
	bool isMembers = false;
	for(int i = 0; i < 10; i++)
	{
		if(membs[i].getId() != 0) 
		{
			membs[i].printMember();
			isMembers = true;
		}
	}
	if(!isMembers) cout << "No members in the system" << endl;
}

int main()
{
	const int MAX_MEMB_COUNT = 10;
	int membCount = 0;
	GymMember members[MAX_MEMB_COUNT];
	string command = "";
	PrintMembers(members);
	while (command != "quit")
	{
		cout << "What would you like to do?: ";
		cin >> command;
		if(command == "quit") break;
		int id;
		cin >> id;
		if(command == "cancel")
		{
			int canceled = false;
			for(int i = 0; i < MAX_MEMB_COUNT; i++)
			{
				if(members[i].getId() == id)
				{
					members[i].Cancel();
					canceled = true;
				}
			}
			if(!canceled) cout << "Cannot perform this opeation: member " 
				<< id << " not found" << endl;
		}
		if(command == "delete")
		{
			int deleted = false;
			for(int i = 0; i < MAX_MEMB_COUNT; i++)
			{
				if(members[i].getId() == id)
				{
					members[i] = GymMember();
					deleted = true;
					membCount--;
				}
			}
			if(!deleted) cout << "Cannot perform this opeation: member " 
				<< id << " not found" << endl;
		}
		if(command == "create")
		{
			string name;
			getline(cin, name);
			int created = false;
			if(membCount < 10)
			{
				for(int i = 0; i < MAX_MEMB_COUNT; i++)
				{
					if(members[i].getId() == 0)
					{
						members[i] = GymMember(id, name, 0);
						created = true;
						membCount++;
						break;
					}
				}
			}
			if(!created) cout << "Cannot perform this opeation: member " 
				<< id << " not found" << endl;
		}
		if(command == "extend")
		{
			int n;
			cin >> n;
			int extended = false;
			
				for(int i = 0; i < MAX_MEMB_COUNT; i++)
				{
					if(members[i].getId() == id)
					{
						members[i].Extend(n);
						extended = true;
					}
				}			
			if(!extended) cout << "Cannot perform this opeation" << endl;
		}
		PrintMembers(members);		
	}
	system("pause");
	return 0;
}