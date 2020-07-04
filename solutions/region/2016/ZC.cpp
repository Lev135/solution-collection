#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int mMod 1e9 + 7;

vector<int> toVector(const string &str) {
	vector<int> res(str.size());
	for (int i = 0; i < str.size(); ++i) {
		res[i] = str[i] - '0';
	}
	return res;
}

int interestingPrefixSize(const string &nStr) {
	for (int i = 1; i < nStr.size(); ++i) {
		if (nStr[i] < nStr[i - 1]) {
			return i;
		}
	}
	return nStr.size();
}

int countInteresting(const vector<int> &rStr) {
	if (rStr.empty()) {
		return 0;
	}
	vector<vector<int> > dp(rStr.size(), vector<int>(10)); 	
		// dp[i][m] --- количество неубывающих последовательностей длины i, 
		// первый член которых не менее m
	for (int c = 0; c < 10; ++c) {
		dp[0][c] = 1;
	}
	for (int i = 1; i < rStr.size(); ++i) {
		for (int m = 0; m < 10; ++m) {
			for (int c = m; c < 10; ++c) {
				dp[i][m] += dp[i - 1][c];
				dp[i][m] %= mMod;
			}
		}
	}
	int res = 0;
	for (int c = 0; c < rStr[0]; ++c) {
		res += dp[rStr.size() - 1][c];
		res %= mMod;
	}
	for (int i = 0; i < rStr.size(); ++i) {
		if (i > 0 && rStr[i - 1] > rStr[i]) {
			break;
		}
		if (i + 1 < rStr.size()) {
			for (int c = rStr[i]; c < rStr[i + 1]; ++c) {
				res += dp[rStr.size() - i - 2][c];
				res %= mMod;
			}
		}
		else {
			++res;
			res %= mMod;
		}
	}
	return res;
	
}

bool isInteresting(const string &nStr) {
	return interestingPrefixSize(nStr) == nStr.size();
}

int main() {
	string lStr, rStr;
	cin >> lStr >> rStr;
	vector<int> lV = toVector(lStr), rV = toVector(rStr);
	cout << (countInteresting(rV) + mMod - countInteresting(lV) + (isInteresting(lStr) ? 1 : 0)) % mMod;
	return 0;
}
