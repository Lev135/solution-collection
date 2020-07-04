/*
	Comment
*/

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

int sumMarks(const Pupil &pupil) {
	int res = 0;
	for (int j = 0; j < marksCount; ++j) {
		res += pupil.marks[j];
	}
	return res;
}

void sortSumMarks(vector<Pupil> &pupils) {
	for (int i = 0; i < pupils.size(); ++i) {
		for (int j = 1; j < pupils.size(); ++j) {
			if (sumMarks(pupils[j]) > sumMarks(pupils[j - 1])) {
				swap(pupils[j - 1], pupils[j]);
			}
		}
	}
}

void printPupil(const Pupil &pupil) {
	cout << pupil.name << " " << pupil.surname << "\n";
}

void printPupilNames(const vector<Pupil> &pupils) {
	for (int i = 0; i < pupils.size(); ++i) {
		printPupil(pupils[i]);
	}
}

int main() {
	vector<Pupil> pupils = scanPupils();
//	printPupils(pupils);
	sortSumMarks(pupils);
	printPupilNames(pupils);
	
	return 0;
}
