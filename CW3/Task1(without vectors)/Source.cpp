#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct film {
	string name;
	string author;
	int year;
	string genre;
};

int main()
{
	string s;
	int k = 0;
	int p = 0;
	int index = 0;
	ifstream file("C:\\Users\\User\\Desktop\\films.txt");
	ofstream out("C:\\Users\\User\\Desktop\\list.txt");
	while (getline(file, s)) {
		p = p + 1;
	}
	string* arr = new string[p];
	string* arr2 = new string[p];
	file.close();
	file.open("C:\\Users\\User\\Desktop\\films.txt", ios_base::in);
	for (int i = 0; i < p; i++) {
		getline(file, s);
		arr[i] = s;
	}
	file.close();
	file.open("C:\\Users\\User\\Desktop\\films.txt", ios_base::in);
	for (int i = 0; i < p*4; i++) {
		getline(file, s);
		if (k == 2) {
			arr2[index] = s;
			index = index + 1;
			k = -1;
		}
	}
	string h;
	for (int i = 0; i < p; i++) {
		for (int j = i + 1; j < p; j++) {
			if ((arr2[i] == arr2[j]) && (i != (p - 1))) {
				h = arr2[i + 1];
				arr2[i + 1] = arr2[j];
				arr2[j] = h;
				h = arr[i + 1];
				arr[i + 1] = arr[j];
				arr[j] = h;

			}
		}
	}
	for (int i = 0; i < p; i++) {
		out << arr[i] << endl;
	}
	string genre;
	cout << "Which genre do you want to browse?" << endl;
	getline(cin, genre);
	file.close();
	file.open("C:\\Users\\User\\Desktop\\films.txt", ios_base::in);
	k = 0;
	index = 0;
	string* arr3 = new string[p];
	while (file >> s) {
		if (k == 3) {
			arr3[index] = s;
			index = index + 1;
			k = -1;
		}
		k = k + 1;
	}
	string* arr4 = new string[p];
	index = 0;
	file.close();
	file.open("C:\\Users\\User\\Desktop\\films.txt", ios_base::in);
	while (getline(file, s)) {
		arr4[index] = s;
		index = index + 1;
	}
	for (int i = 0; i < p; i++) {
		if (genre == arr3[i]) {
			cout << arr4[i] << endl;
		}
	}
	out.close();
	file.close();
}
