#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void main() {
	ifstream student1("C:\\Users\\User\\Desktop\\in1.txt");
	ifstream student2("C:\\Users\\User\\Desktop\\in2.txt");
	ofstream out("C:\\Users\\User\\Desktop\\out.txt");
	string s1, s2;
	vector<string> v = {};
	while (getline(student1, s1)) {
		v.push_back(s1);
	}
	while (getline(student2, s2)) {
		v.push_back(s2);
	}
	for (int i = 0; i < v.size(); i++) {
		for (int j = i+1; j < v.size(); j++) {
			if (v[i] == v[j]) {
				v.erase(v.begin() + j);
			}
		}
	}
	for (string n : v) {
		out << n << endl;
	}
	student1.close();
	student2.close();
	out.close();

}
