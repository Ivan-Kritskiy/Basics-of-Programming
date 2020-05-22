#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void main() {
	ifstream student1("C:\\Users\\User\\Desktop\\in1.txt");
	ifstream student2("C:\\Users\\User\\Desktop\\in2.txt");
	ofstream out("C:\\Users\\User\\Desktop\\out.txt");
	string s1, s2;
	int p = 0;
	int p1 = 0;
	while (getline(student1, s1)) {
		p = p + 1;
	}
	while (getline(student2, s2)) {
		p1 = p1 + 1;

	}
	string* arr = new string[p];
	string* arr2 = new string[p1];
	student1.close();
	student2.close();
	student1.open("C:\\Users\\User\\Desktop\\in1.txt", ios_base::in);
	student2.open("C:\\Users\\User\\Desktop\\in2.txt", ios_base::in);
	for (int i = 0; i < p; i++) {
		getline(student1, s1);
		arr[i] = s1;
	}
	for (int i = 0; i < p1; i++) {
		getline(student2, s1);
		arr2[i] = s1;
	}
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < p1; j++) {
			if (arr[i] == arr2[j]) {
				arr2[j] = "";
			}
		}
	}
	for (int i = 0; i < p; i++) {
		out << arr[i]<< endl;
	}
	for (int i = 0; i < p1; i++) {
		out << arr2[i] << endl;
	}
	student1.close();
	student2.close();
	out.close();
	delete[] arr;
	delete[] arr2;

}
