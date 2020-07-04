#include <iostream>

using namespace std;

int main() {
	int floorsCount, floor, k;
	cin >> floorsCount >> floor >> k;
	--floor;
	int l = floor / k * k, r = l + k;
	int lCost = (floor - l) * 200, rCost = (r - floor) * 100;
	if (r >= floorsCount || lCost < rCost) {
		cout << lCost;
	}
	else {
		cout << rCost;
	}
	return 0;
}

