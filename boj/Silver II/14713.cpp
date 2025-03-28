#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
unordered_map<string, string> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i;
	cin >> n;
	string line, s;
	getline(cin, s);
	queue<string> q[n];
	for (i=0;i<n;i++) {
		getline(cin, line);
		istringstream is(line);
		while (is >> s)
			q[i].push(s);
	}

	while (cin >> s) {
		for (i=0;i<n;i++) {
			if (q[i].empty()) continue;
			if (q[i].front() == s) {
				q[i].pop();
				break;
			}
		}
		if (i == n) {
			cout << "Impossible\n";
			return 0;
		}
	}
	for (i=0;i<n;i++) {
		if (!q[i].empty()) {
			cout << "Impossible\n";
			return 0;
		}
	}
	cout << "Possible\n";
	return 0;
}
