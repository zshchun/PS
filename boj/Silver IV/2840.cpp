#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
int main() {
	ll n, k, i, j, idx;
	cin >> n >> k;
	vector<char> a(n);
	idx = 0;
	char c;
	bool ok = true;
	vector<ll> ascii(128);
	for (i=0;i<k;i++) {
		cin >> j;
		idx = (idx + j) % n;
		cin >> c;
		if (a[idx] && a[idx] != c)
			ok = false;
		if (!a[idx] && ascii[c])
			ok = false;
		ascii[c]++;
		a[idx] = c;
	}
	if (!ok) {
		cout << "!\n";
	} else {
		string s;
		for (i=0;i<n;i++) {
			j = (i + idx+1) %n;
			if (!a[j])
				a[j] = '?';
			s += a[j];
		}
		reverse(s.begin(), s.end());
		cout << s << '\n';
	}
	return 0;
}
