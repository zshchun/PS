#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	vector<int> v, o;
	v.resize(T);
	v.reserve(T);
	for (int &x : v) {
		cin >> x;
		o.push_back(x);
	}
	sort(o.begin(), o.end());
	o.erase(unique(o.begin(), o.end()), o.end());
	for (size_t i=0;i<v.size();i++) {
		if (i) cout << ' ';
		cout << lower_bound(o.begin(), o.end(), v[i])-o.begin();
	}
	cout << '\n';
	return 0;
}

