#pragma once
#include <iostream>
#include <vector>
#include <string>

const std::string recordFile = "Employee.rec";

class Record
{
public:
	Record();
	Record(std::string nm,
		std::string ad,
		std::string ph,
		std::string ds,
		float bs,
		float hr,
		float al);
	
	std::vector<Record> loadRecords();
	void addRecord();
	int modifyRecord();
	int deleteRecord();
	void printRecord();
	int getLastEmpId();
	int getEmpCode() { return empCode; }
	void setEmpCode(int code) { empCode = code; }

private:
	int empCode;
	std::string name, address, phone, dsg;
	float basic, hra, allowance;
};

