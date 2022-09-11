#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, i, x;
	map<int,int> m;
	vector<int> v;
	cin >> T;
	v.reserve(T);
	for (i=0;i<T;i++) {
		cin >> x;
		v.push_back(x);
		if (!m.count(x)) {
			m.insert(make_pair(x, 0));
		}
	}
	i = 0;
	for (auto &j : m) {
		j.second = i++;
	}
	for (i=0;i<T;i++) {
		if (i) cout << ' ';
		cout << m[v[i]];
	}
	cout << '\n';
	return 0;
}

