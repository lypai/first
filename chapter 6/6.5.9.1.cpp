#include<iostream>
#include<string>
using namespace std;

class Engine
{
private: double type;
public: Engine(double _type)
		{
			type = _type;
		}
		void Print()
		{
			cout << "Engine: " << type << endl;
		}
		Engine()
		{
			type = 0.0;
		}
};

class Body
{
private: string color;
public: Body(string _color)
		{
			color = _color;
		}
		void Print()
		{
			cout << "Body: " << color << endl;
		}
		Body()
		{
			color = "";
		}
};

class Chassis
{
private: string type;
public: Chassis(string _type)
		{
			type = _type;
		}
		void Print()
		{
			cout << "Chassis: " << type << endl;
		}
		Chassis()
		{
			type = "";
		}
};

class Wheel
{
private: string size;
public: Wheel(string _size)
		{
			size = _size;
		}
		void Print()
		{
			cout << "Wheel: " << size << endl;
		}
		Wheel()
		{
			size = "0";
		}
};

class Light
{
private: string type;
public: Light(string _type)
		{
			type = _type;
		}
		void Print()
		{
			cout << "Light: " << type << endl;
		}
		Light()
		{
			type = "";
		}
};

class Car
{
public: Engine engine;
		 Wheel *wheels;
		 Chassis chassic;
		 Light *lights;
		 Body body;
		 int wheelCount, lightCount;
	     void Print()
		{
			engine.Print();
			for(int i = 0; i < 4; i++)
				wheels[i].Print();
			chassic.Print();
			for(int i = 0; i < 10; i++)
				lights[i].Print();
			body.Print();
		}
		 void AddEngine(Engine eng)
		 {
			 engine = eng;
		 }
		 void AddChassis(Chassis chs)
		 {
			 chassic = chs;
		 }
		 void AddBody(Body bd)
		 {
			 body = bd;
		 }
		 void AddWheel(Wheel w)
		 {
			if(wheelCount < 4)
			{
				wheels[wheelCount] = w;
			    wheelCount++;
			}
		 }
		  void AddLight(Light light)
		 {
			 if(lightCount < 10)
			 {
				 lights[lightCount] = light;
				 lightCount++;
			 }
		 }
		 Car()
		 {
			 engine = Engine(0.0);
			 body = Body("");
			 chassic = Chassis("");
			 wheels = new Wheel[4];
			 lights = new Light[10];
			 wheelCount = 0;
			 lightCount = 0;
		 }
		 
		
};



int main()
{
	Car car = Car();
	car.AddEngine(Engine(1.0));
	car.AddWheel(Wheel("16inches"));
	car.AddWheel(Wheel("16inches"));
	car.AddWheel(Wheel("16inches"));
	car.AddWheel(Wheel("16inches"));
	car.AddChassis(Chassis("Normal"));
	car.AddLight(Light("Type 1"));
	car.AddLight(Light("Type 1"));
	car.AddLight(Light("Type 2"));
	car.AddLight(Light("Type 2"));
	car.AddLight(Light("Type 3"));
	car.AddLight(Light("Type 3"));
	car.AddLight(Light("Type 4"));
	car.AddLight(Light("Type 4"));
	car.AddLight(Light("Type 5"));
	car.AddLight(Light("Type 5"));
	car.AddBody(Body("Black"));
	car.Print();
	system("pause");
	return 0;
}