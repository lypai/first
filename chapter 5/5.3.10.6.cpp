#include <iostream>
#include<string>
using namespace std;
class FarmAnimal{
	public:
	FarmAnimal(double water_consumption);
	double getWaterConsumption();
	// ...
	protected:
	double water_consumption;
};
FarmAnimal::FarmAnimal(double _water_consumption) {
	water_consumption = _water_consumption;
}
double FarmAnimal::getWaterConsumption() {
	return water_consumption;
}

class Sheep : public FarmAnimal{
public: Sheep(double weight);
};

Sheep::Sheep(double weight): FarmAnimal((weight/10.) * 1.1)
{}

class Cow : public FarmAnimal{
public: Cow(double weight);
};

Cow::Cow(double weight): FarmAnimal((weight/100.) * 8.6)
{}

class Horse : public FarmAnimal{
public: Horse(double weight);
};

Horse::Horse(double weight): FarmAnimal((weight/100.) * 6.8)
{}

class ConsumptionAccumulator
{
	public:
	ConsumptionAccumulator();
	double getTotalConsumption();
	void addConsumption(FarmAnimal animal);
	private:
	double total_consumption;
};
ConsumptionAccumulator::ConsumptionAccumulator() :
total_consumption(0)
{
}
double ConsumptionAccumulator::getTotalConsumption()
{
	return total_consumption;
}void ConsumptionAccumulator::addConsumption(FarmAnimal animal)
{
	total_consumption += animal.getWaterConsumption();
}
int main()
{
	ConsumptionAccumulator accumulator;
	string animal;
	int weight;
	
	int i = 0;
	while(i<3)
	{
		cin >> animal;
		cin >> weight;
		if(animal == "cow") 
		{
			Cow cow(weight);
			accumulator.addConsumption(cow);
		}
		if(animal == "horse") 
		{
			Horse horse(weight);
			accumulator.addConsumption(horse);
		}
		if(animal == "sheep") 
		{
			Sheep sheep(weight);
			accumulator.addConsumption(sheep);
		}
		i++;
	}
	cout << accumulator.getTotalConsumption() << endl;
	system("pause");
	return 0;
}