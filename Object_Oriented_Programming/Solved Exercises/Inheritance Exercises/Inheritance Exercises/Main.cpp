#include <iostream>
#include <string.h>
#include "Building.h"
#include "Warehouse.h"
#include "House.h"
#include "Temple.h"
#include "ReverseBonus.h"

int main() {

	Warehouse w ("East Warehouse", 10, 20, 30);
	House h ("Agripa's house", 2, 5, 10);
	Temple t("Mercury's Temple", "Mercury", 3);

	std::cout << "Warehouse name: " << w.getName() << std::endl << std::endl;
	std::cout << "House name: " << h.getName() << std::endl << std::endl;
	std::cout << "Temple name: " << t.getName() << std::endl << std::endl;

	std::cout << "---- East Warehouse ---" << std::endl;
	w.printResources();
	std::cout << "---- Agripa's house ---" << std::endl;
	h.printHouse();
	std::cout << "---- Mercury's Temple ---" << std::endl;
	t.printTemple();

	int array[5] = { 2,4,-6,5,8 };

	for (int i = 0; i < 5; i++) {

		std::cout << " " << *(array + i) << std::flush;
	}

	reverse(array);
	std::cout << std::endl;

	for (int i = 0; i < 5; i++) {

		std::cout << " " << *(array + i) << std::flush;
	}

	std::cout << std::endl;

	system("pause");
	return 0;
}