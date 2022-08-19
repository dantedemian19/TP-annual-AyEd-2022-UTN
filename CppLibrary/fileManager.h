#pragma once
#include <fstream>
#include "./dynamicTypes.h"

using std::ios;using std::fstream;

template <typename dataclass>
class fileManager {
	private:
		string file;
	public:
		void declare(string fileName = "data", string fileExtension="bat") {
			file = fileName + "." + fileExtension;
		};
		linkList<dataclass> inMemoryFile; 
		// void read(dataclass data);
		void readToMemory();
		void write(dataclass data);
		void reWrite(dataclass data);
};

template <typename dataclass>
void fileManager<dataclass>::readToMemory() {
	inMemoryFile.purgeAll();
	fstream fileObj = fstream(file, ios::in);
	dataclass temp;
	if (!fileObj.fail()){
		while (!fileObj.eof()) {
			fileObj >> temp;
			inMemoryFile.addToEnd(temp);
		}
	}
	else{
		cout << "error reading the file";
	}
	fileObj.close();
};

template <typename dataclass>
void fileManager<dataclass>::reWrite(dataclass data) {
	fstream fileObj = fstream(file, ios::trunc | ios::out);
	if (!fileObj.fail()) {
		fileObj << data;
	}
	else {
		cout << "error writting the file";
	}
	fileObj.close();
};

template <typename dataclass>
void fileManager<dataclass>::write(dataclass data) {
	fstream fileObj = fstream(file, ios::app | ios::out);
	if (!fileObj.fail()) {
		fileObj << data;
	}
	else {
		cout << "error writting the file";
	}
	fileObj.close();
};