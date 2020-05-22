#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct film{
	string name;
	string author;
	int year;
	string genre;
};

int main()
{
	string s;
	int k = 0;
	vector<string> v = {};
	vector<string> v2 = {};
	vector<string> v3 = {};
	
	ifstream file("C:\\Users\\User\\Desktop\\films.txt");
	ofstream out("C:\\Users\\User\\Desktop\\list.txt");
	while (getline(file, s)) {
		v.push_back(s);
	}
	file.close();
	file.open("C:\\Users\\User\\Desktop\\films.txt", ios_base::in);
	while (file >> s) {
		if (k == 1) {
			v2.push_back(s);
			k = -3;
		}
		k = k + 1;
	}
	string h;
	for (int i = 0; i < v2.size(); i++) {
		for (int j = i + 1; j < v2.size(); j++) {
			if ((v2[i] == v2[j])&&(i!=(v2.size()-1))) {
				h = v2[i+1];
				v2[i + 1] = v2[j];
				v2[j] = h;
				h = v[i + 1];
				v[i + 1] = v[j];
				v[j] = h;

			}
		}
	}
	string genre;
	cout << "Which genre do you want to browse?" << endl;
	getline(cin, genre);
	file.close();
	file.open("C:\\Users\\User\\Desktop\\films.txt", ios_base::in);
	k = 0;
	while (file >> s) {
		if (k == 3) {
			v3.push_back(s);
			k = -1;
		}
		k = k + 1;
	}
	vector<string> v0 = {};
	file.close();
	file.open("C:\\Users\\User\\Desktop\\films.txt", ios_base::in);
	while (getline(file, s)) {
		v0.push_back(s);
	}
	for (int i = 0; i < v3.size(); i++) {
		if (genre == v3[i]) {
			cout << v0[i] << endl;
		}
	}
	for (string i : v) {
		out << i << endl;
	}
	out.close();
	file.close();
}
