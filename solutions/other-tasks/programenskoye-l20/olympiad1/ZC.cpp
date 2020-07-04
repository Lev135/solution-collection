#include <iostream>
#include <vector>
#include <algorithm>

const long long infty = (long long)1e18;

using namespace std;

vector<int> readArray() {
	int n;
	cin >> n;
	vector<int> res(n);
	for (int i = 0; i < n; ++i) {
		cin >> res[i];
	}
	return res;
}

template<class T>
void printArray(const vector<T> &arr, const char *name) {
	cout << "*************** " << name << " ******************\n";
	for (int i = 0; i < arr.size(); ++i) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

vector<long long> prefDistances(const vector<int> &coords) {
	vector<long long> res(coords.size());
	if (coords.empty()) {
		return res;
	}
	res[0] =  0;
	for (int i = 1; i < res.size(); ++i) {
		res[i] = res[i - 1] + (long long)i * abs(coords[i] - coords[i - 1]);
	}
	return res;
}

vector<long long> sufDistances(vector<int> coords) {
	reverse(coords.begin(), coords.end());
	vector<long long> res = prefDistances(coords);
	reverse(res.begin(), res.end());
	return res;
}


int main() {
	vector<int> coords = readArray();
	vector<long long> prefDist = prefDistances(coords), sufDist = sufDistances(coords);
//	printArray(prefDist, "prefDist");
//	printArray(sufDist, "sufDist");
	int minI = -1;
	long long minV = infty;
	for (int i = 0; i < coords.size(); ++i) {
		long long curDist = prefDist[i] + sufDist[i];
		if (curDist < minV) {
			minV = curDist;
			minI = i;
		}
	}
	cout << coords[minI];
	return 0;
}