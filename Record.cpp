#include "Record.h"
#include <fstream>
#include <sstream>

Record::Record() {
	empCode = 0;
	name = "";
	address = "";
	phone = "";
	dsg = "";
	basic = 0;
	hra = 0;
	allowance = 0;
}

Record::Record(std::string nm,
	std::string ad,
	std::string ph,
	std::string ds,
	float bs,
	float hr,
	float al) {
	empCode = getLastEmpId()+1;
	name = nm;
	address = ad;
	phone = ph;
	dsg = ds;
	basic = bs;
	hra = hr;
	allowance = al;
}

std::vector<Record> Record::loadRecords() {
	std::vector<Record> employees;
	std::ifstream fin;
	fin.open(recordFile);
	std::string line;
	while (std::getline(fin, line)) {
		std::stringstream ss(line);
		Record emp;

		ss >> emp.empCode
			>> emp.name
			>> emp.address
			>> emp.phone
			>> emp.dsg
			>> emp.basic
			>> emp.hra
			>> emp.allowance;
		employees.push_back(emp);
	}
	fin.close();
	return employees;
}

void Record::addRecord() {
	std::ofstream fout;
	fout.open(recordFile, std::ios_base::app);
	fout << empCode << " "
		<< name << " "
		<< address << " "
		<< phone << " "
		<< dsg << " "
		<< basic << " "
		<< hra << " "
		<< allowance << std::endl;
	fout.close();
}

int Record::modifyRecord() {
	int ret = 1;
	std::vector<Record> employees = loadRecords();
	std::ofstream fout;
	fout.open(recordFile, std::ios_base::out);
	for (int itr = 0; itr < employees.size(); ++itr) {
		if (employees[itr].empCode == empCode) {
			ret = 0;
			fout << empCode << " "
				<< name << " "
				<< address << " "
				<< phone << " "
				<< dsg << " "
				<< basic << " "
				<< hra << " "
				<< allowance << std::endl;
		}
		else {
			fout << employees[itr].empCode << " "
				<< employees[itr].name << " "
				<< employees[itr].address << " "
				<< employees[itr].phone << " "
				<< employees[itr].dsg << " "
				<< employees[itr].basic << " "
				<< employees[itr].hra << " "
				<< employees[itr].allowance << std::endl;
		}
	}
	fout.close();
	return ret;
}

int Record::deleteRecord() {
	int ret = 1;
	std::vector<Record> employees = loadRecords();
	for (int itr = 0; itr < employees.size(); ++itr) {
		if (employees[itr].empCode == empCode) {
			ret = 0;
			employees.erase(employees.begin() + itr);
			break;
		}
	}

	std::ofstream fout;
	fout.open(recordFile, std::ios_base::out);
	for (int itr = 0; itr < employees.size(); ++itr) {
		fout << employees[itr].empCode << " "
			<< employees[itr].name << " "
			<< employees[itr].address << " "
			<< employees[itr].phone << " "
			<< employees[itr].dsg << " "
			<< employees[itr].basic << " "
			<< employees[itr].hra << " "
			<< employees[itr].allowance << std::endl;
	}
	fout.close();
	return ret;
}

void Record::printRecord() {
	std::cout << "Employee Code: "<< empCode << ", "
		<< "Employee Name: " << name << std::endl;
}

int Record::getLastEmpId() {
	std::vector<Record> recs = loadRecords();
	if (recs.empty())
		return 0;
	return recs[recs.size() - 1].empCode;
}