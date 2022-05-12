#include "Employee.h"

void Employee::listEmployees() {
	std::vector<Record> records = rec.loadRecords();
	if (records.empty()) {
		std::cout << "No Record Found!" << std::endl;
		return;
	}
	std::cout << "---- List of Employees ----" << std::endl;
	for (int itr = 0; itr < records.size(); ++itr) {
		records[itr].printRecord();
	}
	std::cout << "-------- List Ends --------" << std::endl;

	//std::cout << "listEmployees() called" << std::endl;
}

void Employee::addEmployee() {
	std::string name;
	std::string address;
	std::string phone;
	std::string dsg;
	float basic;
	float hra;
	float allowance;
	std::cout << "Please Enter the Employee Name: ";
	std::cin >> name;
	std::cout << "Please Enter the Employee Address: ";
	std::cin >> address;
	std::cout << "Please Enter the Employee Phone: ";
	std::cin >> phone;
	std::cout << "Please Enter the Employee designation: ";
	std::cin >> dsg;
	std::cout << "Please Enter the Employee Salary basic: ";
	std::cin >> basic;
	std::cout << "Please Enter the Employee Salary hra: ";
	std::cin >> hra;
	std::cout << "Please Enter the Employee Salary Allowances: ";
	std::cin >> allowance;
	Record rec(name, address, phone, dsg, basic, hra, allowance);
	rec.addRecord();
	//std::cout << "addEmployee() called" << std::endl;
}

int Employee::modifyEmployee() {
	int code;
	std::cout << "Please Enter the Employee Code to Modify the Record: ";
	std::cin >> code;
	Record rec1;
	if (rec1.getLastEmpId() < code) {
		return 1;
	}
	else {
		std::string name;
		std::string address;
		std::string phone;
		std::string dsg;
		float basic;
		float hra;
		float allowance;
		std::cout << "Please Enter the Employee Name: ";
		std::cin >> name;
		std::cout << "Please Enter the Employee Address: ";
		std::cin >> address;
		std::cout << "Please Enter the Employee Phone: ";
		std::cin >> phone;
		std::cout << "Please Enter the Employee designation: ";
		std::cin >> dsg;
		std::cout << "Please Enter the Employee Salary basic: ";
		std::cin >> basic;
		std::cout << "Please Enter the Employee Salary hra: ";
		std::cin >> hra;
		std::cout << "Please Enter the Employee Salary Allowances: ";
		std::cin >> allowance;
		Record rec(name, address, phone, dsg, basic, hra, allowance);
		rec.setEmpCode(code);
		return rec.modifyRecord();
	}
	//std::cout << "modifyEmployee() called" << std::endl;
}

int Employee::deleteEmployee() {
	int code;
	std::cout << "Please Enter the Employee Code to Delete the Record: ";
	std::cin >> code;
	Record rec;
	if (rec.getLastEmpId() < code) {
		return 1;
	}
	else {
		rec.setEmpCode(code);
		return rec.deleteRecord();
	}
	//std::cout << "deleteEmployee() called" << std::endl;
}