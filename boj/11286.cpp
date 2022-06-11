#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct compare {
	bool operator() (int &lhs, int &rhs) {
		if (abs(lhs) == abs(rhs))
			return lhs > rhs;
		else
			return abs(lhs) > abs(rhs);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, v;
	cin >> T;
	priority_queue<int,vector<int>,compare> q;
	pair<int,int> p;
	while (T--) {
		cin >> v;
		if (v) {
			q.push(v);
		} else {
			if (q.empty()) {
				cout << "0\n";
			} else {
				cout << q.top() << '\n';
				q.pop();
			}
		}
	}
	return 0;
}

