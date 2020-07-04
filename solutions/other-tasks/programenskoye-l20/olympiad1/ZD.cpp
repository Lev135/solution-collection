#include <iostream>
#include <stack>
#include <vector>

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

int main() {
	vector<int> cost = readArray();
	vector<int> res(cost.size());
	cost.push_back(-1);
	stack<int> tmp;
	for (int i = 0; i < cost.size(); ++i) {
		int curCost = cost[i];
		while (!tmp.empty() && cost[tmp.top()] > curCost) {
			res[tmp.top()] = i;
			tmp.pop();
		}
		tmp.push(i);
	}
	for (int i = 0; i < res.size(); ++i) {
		if (res[i] < res.size()) {
			cout << res[i] << " ";
		}
		else {
			cout << "-1 ";
		}
	}
	return 0;
}
