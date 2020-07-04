#include <iostream>
#include <map>

using namespace std;

void addElement(map<int, int>::iterator it, int &segmentCount1, int &segmentCount2) {
	++segmentCount1;
	if (it->second >= 2) {
		++segmentCount2;
	}
}
void removeElement(map<int, int>::iterator it, int &segmentCount1, int &segmentCount2) {
	--segmentCount1;
	if (it->second >= 2) {
		--segmentCount2;
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	map<int, int> counts;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		++counts[num];
	}
	map<int, int>::iterator it = counts.begin(), jt = counts.begin();
	int segmentCount1 = 0, segmentCount2 = 0;
	long long resCount = 0;
	while (it != counts.end()) {
		while (jt != counts.end() && (long long)jt->first <= (long long)it->first * k) {
			if (it != jt) {
				addElement(jt, segmentCount1, segmentCount2);
			}
			++jt;
		}
		long long cABC = (long long)segmentCount1 * (segmentCount1 - 1) / 2, 	// N?eoaai eiee?anoai o?iae (A, B, C), aaa i = A < B < C <= j
				  cAAB = it->second >= 2 ? segmentCount1 : 0,					// N?eoaai eiee?anoai o?iae (A, A, B), aaa i = A < B <= j
				  cABB = segmentCount2,											// N?eoaai eiee?anoai o?iae (A, B, B), aaa i = A < B <= j
				  cAAA = it->second >= 3 ? 1 : 0;								// N?eoaai eiee?anoai o?iae (A, A, A), aaa i = A <= j
//		cout << "[" << it->first << "; " << (jt == counts.end() ? -1 : jt->first) << "): "
//			 << "count1: " << segmentCount1 << " count2: " << segmentCount2
//			 << " ABC: " << cABC << " AAB: " << cAAB << " ABB: " << cABB << " AAA: " << cAAA << "\n";
		resCount += cABC * 6 + (cAAB + cABB) * 3 + cAAA;
		++it;
		if (it != jt)
			removeElement(it, segmentCount1, segmentCount2);
	}
	cout << resCount;
	return 0;
}
