// Hayden Lammons
// HLammons1@cnm.edu
// New Delete Demo

// Driver.cpp

#include <iostream>
#include <string>
using namespace std;

class Box
{
public:
	int id{ 0 };
	Box() { cout << "\n Constructor called"; }
	Box(int newId) : id{ newId } {}
	~Box() { cout << "\n Destructor called"; }
	void WriteBox() { "\n This is the " + to_string(id) + " box object"; }
};

int main()
{
	cout << "\n Allocate memory dynamically for any data type" << endl;

	double* pValue = nullptr;
	pValue = new double;

	delete pValue;
	pValue = nullptr;

	cout << "\n This works for any class too";
	Box* pBox = new Box;
	pBox->WriteBox();

	delete pBox;
	pBox = nullptr;

	cout << "\n Creating a new array on the free store";
	Box* ppBox = nullptr;
	ppBox = new Box[3];

	for (int i{ 0 }; i < 3; i++)
	{
		Box newBox{ i };
		ppBox[i] = newBox;
		ppBox[i].WriteBox();
	}

	delete[] ppBox;
	ppBox = nullptr;

	cout << "\n Dynamic array with dynamic object elements";

	Box** newArray = new Box * [3];
	for (int i{ 0 }; i < 3; i++)
	{
		Box* myBox = new Box{ i };
		newArray[i] = myBox;
		newArray[i]->WriteBox();
	}

	for (int i{ 0 }; i < 3; i++)
	{
		delete newArray[i];
		newArray[i] = nullptr;
	}

	delete[] newArray;
	newArray = nullptr;



	return 0;
}