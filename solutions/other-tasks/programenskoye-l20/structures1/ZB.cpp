#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int marksCount = 3;

struct Pupil {
	string surname, name;
	int marks[marksCount];
};

Pupil scanPupil() {
	Pupil res;
	cin >> res.name >> res.surname;
	for (int i = 0; i < marksCount; ++i) {
		cin >> res.marks[i];
	}
	return res;
}

vector<Pupil> scanPupils() {
	int n;
	cin >> n;
	vector<Pupil> res(n);
	for (int i = 0; i < n; ++i) {
		res[i] = scanPupil();
	}
	return res;
}

void printPupils(const vector<Pupil> &pupils) {
	cout << "\n******************************\nPrinting pupils (size: " << pupils.size() << ")\n";
	for (int i = 0; i < pupils.size(); ++i) {
		cout << pupils[i].name << "  " << pupils[i].surname << ":   ";
		for (int j = 0; j < marksCount; ++j) {
			cout << pupils[i].marks[j] << " ";
		}
		cout << "\n";
	}
	cout << "\n******************************\n";
}

int main() {
	vector<Pupil> pupils = scanPupils();
//	printPupils(pupils);
	for (int i = 0; i < pupils.size(); ++i) {
		bool f = true;
		for (int j = 0; j < marksCount; ++j) {
			if (pupils[i].marks[j] < 4) {
				f = false;
				break;
			}
		}
		if (f) {
			cout << pupils[i].name <<" " << pupils[i].surname << "\n";
		}
	}
	return 0;
}
