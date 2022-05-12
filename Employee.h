#pragma once
#include "Record.h"

class Employee {
public:
	void listEmployees();
	void addEmployee();
	int modifyEmployee();
	int deleteEmployee();
private:
	Record rec;
};

