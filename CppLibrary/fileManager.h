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
		void memoryToFile();
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
		cout << " \n error reading the file "+ file << "\n";
	}
	fileObj.close();
};

template <typename dataclass>
void fileManager<dataclass>::memoryToFile() {
	fstream fileObj = fstream(file, ios::trunc | ios::out);
	if (!fileObj.fail()){
		for (int i = 0; i < inMemoryFile.getSize(); i++) {
			fileObj << inMemoryFile[i]->data;
		}
	}
	else{
		cout << " \n error writing the file "+ file << "\n";
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
		cout << "error writting the file ";
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
		cout << "error writting the file ";
	}
	fileObj.close();
};