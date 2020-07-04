#include <iostream>
#include <string>
#include <vector>

using namespace std;

int addLeftAffluent(char ch) {
	return (ch == 'L' || ch == 'B') ? 1 : 0;
}

int addRightAffluent(char ch) {
	return (ch == 'R' || ch == 'B') ? 1 : 0;
}

int main() {
	string river;
	cin >> river;
	vector<int> dpL(river.size() + 1), dpR(river.size() + 1);
	dpL[0] = 0;
	dpR[0] = 1;
	for (int i = 1; i <= river.size(); ++i) {
		int leftFromLeft = dpL[i - 1] + addLeftAffluent(river[i - 1]),
			rightFromRight = dpR[i - 1] + addRightAffluent(river[i - 1]);
		dpL[i] = min(leftFromLeft, rightFromRight + 1);
		dpR[i] = min(rightFromRight, leftFromLeft + 1);
	}
	cout << dpR[river.size()];
	return 0;
}
