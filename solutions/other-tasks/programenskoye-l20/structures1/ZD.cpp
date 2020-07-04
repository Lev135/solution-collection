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

int thirdMaxSumMarks(const vector<Pupil> &pupils) {
	int m1 = 0, m2 = 0, m3 = 0;
	for (int i = 0; i < pupils.size(); ++i) {
		int curSum = sumMarks(pupils[i]);
		if (curSum > m1) {
			m3 = m2;
			m2 = m1;
			m1 = curSum;
		}
		else if (curSum > m2) {
			m3 = m2;
			m2 = curSum;
		}
		else if (curSum > m3) {
			m3 = curSum;
		}
	}
	return m3;
}

void printPupil(const Pupil &pupil) {
	cout << pupil.name << " " << pupil.surname << "\n";
}

void printMaxSumMarksPupils(const vector<Pupil> &pupils) {
	int max3S = thirdMaxSumMarks(pupils);
	for (int i = 0; i < pupils.size(); ++i) {
		if (sumMarks(pupils[i]) >= max3S) {
			printPupil(pupils[i]);	
		}
	}
}

int main() {
	vector<Pupil> pupils = scanPupils();
//	printPupils(pupils);
	printMaxSumMarksPupils(pupils);
	
	return 0;
}
