#include <iostream>
using namespace std;
class FarmAnimal{
	public:
	FarmAnimal(double water_consumption);
	double getWaterConsumption();
	// ...
	protected:
	double water_consumption;
};
FarmAnimal::FarmAnimal(double water_consumption) {
	this->water_consumption = water_consumption;
	cout << "Constructor of FarmAnimal, argument(water consumption): " << water_consumption << endl;
}
double FarmAnimal::getWaterConsumption() {
	return water_consumption;
}
class DummyAnimal : public FarmAnimal{
public:
DummyAnimal();
};
DummyAnimal::DummyAnimal() : FarmAnimal(10.0)
{
	cout << "Constructor of DummyAnimal, argument(no arguments, but water consumption): " << water_consumption << endl;
}
class DoublingAnimal : public FarmAnimal
{
public:
DoublingAnimal(double given_water_consumption);
};
DoublingAnimal::DoublingAnimal(double given_water_consumption)
: FarmAnimal(2 * given_water_consumption) {
	cout << "Constructor of DoublingAnimal, argument(given water consumption): " 
		<<given_water_consumption << ", water consumption: " << water_consumption << endl;

}
void printConsumption(FarmAnimal animal)
{
	cout << "This animal consumes " << animal.getWaterConsumption()
	<< " liters of water" << endl;
}
int main()
{
	FarmAnimal animalA(5);
	DummyAnimal animalB;
	DoublingAnimal animalC(21);
	cout << "animalA consumes " << animalA.getWaterConsumption()
	<< " liters of water." << endl;
	cout << "What about the others?" << endl;
	printConsumption(animalB);
	printConsumption(animalC);
	system("pause");
	return 0;
}