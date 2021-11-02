
#include <iostream>
#include "String.h"

int main() {

	/*char temp[] = "Hello World";
	String string1{ temp };
	std::cout << string1 << std::endl;

	String string2 = "Hello World2";
	std::cout << string2 << std::endl;

	String string3{ string2 };
	std::cout << string3 << std::endl;

	String inputTest;
	std::cin >> inputTest;
	std::cout << inputTest.length() << std::endl;

	String clearTest = "Hello World";
	std::cout << "Clear: " << clearTest << std::endl;
	clearTest.clear();
	std::cout << "Clear: " << clearTest << std::endl;*/

	String add1 = "Foo";
	String add2 = "Foo";
	String add3;
	add3 = add1 + add2;
	std::cout << "combined: " << add3 << std::endl;

	if (add1 == add2) {
		std::cout << "true" << std::endl;
	}
	else {
		std::cout << "false" << std::endl;
	}


	return 0;
}

