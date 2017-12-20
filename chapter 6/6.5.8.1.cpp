#include<iostream>
#include<string>
using namespace std;

class IPAddress
{
private: string ip;
public: IPAddress(string _ip)
		{
			ip = _ip;
		}
		IPAddress()
		{
			ip = "";
		}
		string ToString()
		{
			return ip;
		}
};

class Network
{
private: IPAddress* elements;
		 int elno;
public: void AddIP(IPAddress _ip);
		void Print();
		Network();
};

Network::Network()
{
	elements = NULL;
	elno = 0;
}
void Network::AddIP(IPAddress _ip)
{
	if(elno == 0)
	{
		elno = 1;
		elements = new IPAddress[1];
		elements[0] = _ip;
	}
	else
	{
		IPAddress *newElements = new IPAddress[elno + 1];
		for(int i = 0; i < elno; i++)
		{
			newElements[i] = elements[i];
		}
		newElements[elno] = _ip;
		elno++;
		delete[] elements;
		elements = newElements;		
	}
}

void Network::Print()
{
	for(int i = 0; i < elno; i++)
	{
		cout << elements[i].ToString() << endl;
	}
}

int main()
{
	Network net1 = Network();
	net1.AddIP(IPAddress("1.1.1.1"));
	net1.AddIP(IPAddress("2.2.2.2"));
	net1.AddIP(IPAddress("3.3.3.3"));
	cout << "Network 1:" << endl;
	net1.Print();
	Network net2 = Network();
	net2.AddIP(IPAddress("3.3.3.3"));
	net2.AddIP(IPAddress("4.4.4.4"));
	net2.AddIP(IPAddress("5.5.5.5"));
	cout << "Network 2:" << endl;
	net2.Print();
	system("pause");
	return 0;
}