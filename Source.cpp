#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool filesAreEqual(fstream*,fstream*);
int sizeOfFile(fstream*);
int main() {
	fstream file1;fstream file2;
	string first;string second;
	string line1;string line2;
	
	cout << "enter the #1st file name (with extenstion .txt or .doc): ";
	cin >> first;
	file1.open(first, ios::trunc | ios::in | ios::ate);

	cout << "enter the #2nd file name (with extenstion .txt or .doc): ";
	cin >> second;
	file2.open(second,ios::trunc| ios::in |ios::ate);

	int sizeOfFile1 = sizeof(file1);
	cout << sizeOfFile1 << endl;
	int sizeOfFile2 = sizeof(&file2);
	int count = 1;
	while (getline(file1, line1) && getline(file2, line2)) {

		if(sizeOfFile1== sizeOfFile2){
		for (int i = 0; i < sizeOfFile1; i++) {
			if (line1[i] == line2[i]) {
				return 0;
				if (line1[i] == '\0'){
					count++;
				}
			}
			else {
				cout << "the files are not identical ";
				cout << "the error at line "<<count; 
				cout << line1;
				break;
			}
		}
		//cout << "the files are identical" ;
		}
		else {
			"the files are not the same length";
			break;
		}

	}



	//if (file_1.is_open()&&file_2.is_open()) {
	//	if (filesAreEqual(&file_1,&file_2)) {
	//		cout << "files are edintical";
	//	}
	//}
	//else {

	//	cout << "the files can not be opened";
	//}


	return 0;
}
//std::string line;
//while (std::getline(infile, line))
//{
//	std::istringstream iss(line);
//	int a, b;
//	if (!(iss >> a >> b)) { break; } // error
//
//	// process pair (a,b)
//}
bool filesAreEqual(fstream* a, fstream* b) {
	int sizeOfFile1 = sizeOfFile(a);
	int sizeOfFile2 = sizeOfFile(b);
	int line = 0;
	if (sizeOfFile1 == sizeOfFile2) {
		int bufferSize = sizeOfFile1;
		char * bufferOfFile1 = new char[bufferSize];
		char * bufferOfFile2 = new char[bufferSize]; 

		a->read(bufferOfFile1 , bufferSize);
		b->read(bufferOfFile2 , bufferSize);

		if (memcmp(bufferOfFile1, bufferOfFile2, bufferSize)!=0) {

			cout << "files are not identical"<<endl;
			cout << "the difference is at line " << line;
			delete[]bufferOfFile1;
			delete[]bufferOfFile2;
			return false;
		}

		delete[]bufferOfFile1;
		delete[]bufferOfFile2;
		return true;
	}

	else {
		cout << "files are not identical";
		return false;
	}

	return false;
}
int sizeOfFile(fstream* file) {
	file->seekg(0, ios::end);
	int sizeOfFile = file->tellg();
	file->seekg(0, ios::beg);
	return sizeOfFile;
}
