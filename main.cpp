
#include "Employee.h"

void printMain() {
	std::cout << std::endl << "Hot Keys:" << std::endl;
	std::cout << "L - List All Employees' Record" << std::endl;
	std::cout << "A - Add New Employee Record" << std::endl;
	std::cout << "M - Modify Existing Employee's Record" << std::endl;
	std::cout << "D - Delete Existing Employee's Record" << std::endl;
}

void clearScreen() {
	std::cout << "\x1B[2J\x1B[H";
}

int main()
{
	std::cout << "Welcome to ABC Enterprise's Employee Management System" << std::endl;
	while (true) {
		printMain();
		char c;
		std::cin >> c;
		if ((char)c == 'q' || (char)c == 'Q') {
			std::cout << "Thanks for Visiting. Have a Nice Day!" << std::endl;
			break;
		}
		Employee ems;
		switch ((char)c)
		{
		case 'L':
		case 'l':
			clearScreen();
			ems.listEmployees();
			break;

		case 'A':
		case 'a':
			ems.addEmployee();
			clearScreen();
			std::cout << "Record added successfully" << std::endl;			
			break;

		case 'M':
		case 'm':
			clearScreen();
			if (!ems.modifyEmployee()) {
				std::cout << "Record Modified Successfully. " << std::endl;
			}
			else {
				std::cout << "Employee not found. Kindly Use the Correct Employee Code.";
			}
			break;

		case 'D':
		case 'd':
			clearScreen();
			if (!ems.deleteEmployee()) {
				std::cout << "Record Deleted Successfully" << std::endl;
			}
			else {
				std::cout << "Employee not found. Kindly Use the Correct Employee Code.";
			}			
			break;

		default:
			clearScreen();
			std::cout << "Not a valid hot-key, Please try again!" << std::endl;			
			break;
		}
	}
	return 0;
}