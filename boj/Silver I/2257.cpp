#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int v, n;
	string s;
	cin >> s;
	vector<int> a(1);
	for (char &c : s) {
		if (c == '(') {
			a.push_back(0);
		} else if (c == ')') {
			while (1) {
				v = a.back();
				a.pop_back();
				if (a.empty()) a.push_back(0);
				n = a.back();
				a.back() += v;
				if (n == 0)
					break;
			}
		} else if (c == 'H') {
			a.push_back(1);
		} else if (c == 'C') {
			a.push_back(12);
		} else if (c == 'O') {
			a.push_back(16);
		} else {
			a.back() *= c - '0';
		}
	}
	cout << accumulate(a.begin(), a.end(), 0) << endl;

	return 0;
}
