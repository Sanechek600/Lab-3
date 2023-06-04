#include <windows.h>
#include <vehicle/vehicle.h>
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

void menu(VehicleList VL) {
	system("cls");
	VL.print(cout);
	cout << "1 - Insert an element into the list at the specified index" << endl;
	cout << "2 - Remove an element from the list at the specified index" << endl;
	cout << "3 - Add an element" << endl;
	cout << "4 - Search for a vehicle with minimal cost of transportation" << endl;
	cout << "5 - View tranportation costs" << endl;
	cout << "6 - End session" << endl;
	cout << "> ";
}

int main() {
	VehicleList VL = VehicleList();
	shared_ptr<Train> train = make_shared<Train>("stdtrain", 10);
	shared_ptr<Plane> plane = make_shared<Plane>("stdplane", 10, 0);
	shared_ptr<Ship> ship = make_shared<Ship>("stdship", 10, 0.95);
	int input = 0;
	int idx, type;
	while (input != 6) {
		menu(VL);
		cin >> input;
		float dist = 0;
		float mass = 0;
		switch (input) {
		case 1:
			system("cls");
			VL.print(cout);
			cout << "Isertion index: ";
			cin >> idx;
			cout << "Select type (0-Train, 1-Plane, 2-Ship): ";
			cin >> type;
			switch (type) {
			case 0:
				cin >> train;
				VL.insert(train, idx);
				break;
			case 1:
				cin >> plane;
				VL.insert(plane, idx);
				break;
			case 2:
				cin >> ship;
				VL.insert(ship, idx);
				break;
			}
			break;
		case 2:
			system("cls");
			VL.print(cout);
			cout << "Removal index: ";
			cin >> idx;
			VL.remove(idx);
			break;
		case 3:
			system("cls");
			VL.print(cout);
			cout << "Select type (0-Train, 1-Plane, 2-Ship): ";
			cin >> type;
			switch (type) {
			case 0:
				cin >> train;
				VL.add(train);
				break;
			case 1:
				cin >> plane;
				VL.add(plane);
				break;
			case 2:
				cin >> ship;
				VL.add(ship);
				break;
			}
			break;
		case 4:
			system("cls");
			VL.print(cout);
			cout << "Distance (km): ";
			cin >> dist;
			cout << "Mass of cargo (kg): ";
			cin >> mass;
			idx = index_of_min_cost(VL, mass, dist);
			cout << "Vehicle with minimal tranportation cost: " << VL[idx].get()->get_name() << endl;
			break;
		case 5:
			system("cls");
			VL.print(cout);
			cout << "Index of needed vehicle: ";
			cin >> idx;
			cout << "Distance (km): ";
			cin >> dist;
			cout << "Mass of cargo (kg): ";
			cin >> mass;
			cout << "Cost of transportaion: " << VL[idx].get()->compute_cost(mass, dist) << endl;
			break;
		}
		if (input != 6)
			system("pause");
	}
}