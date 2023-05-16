#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

int main() {
	ll N, i, j;
	string s;
	cin >> N;
	vector<pair<ll, string>> a;
	for (i=0;i<N;i++) {
		cin >> s;
		ll x = 0;
		for (j=0;j<(unsigned int)s.size();j++) {
			if (s[j] >= '0' && s[j] <= '9') {
				x += s[j] - '0';
			}
		}
		a.push_back(pair<ll,string>(x, s));
	}
	sort(a.begin(), a.end(), [&](const pair<ll,string> &lhs, const pair<ll,string> &rhs) {
		if (lhs.second.size() == rhs.second.size()) {
			if (lhs.first == rhs.first) {
				return lhs.second < rhs.second;
			} else {
				return lhs.first < rhs.first;
			}
		} else {
			return lhs.second.size() < rhs.second.size();
		}
	});
	for (pair<ll,string> &ss : a) {
		cout << ss.second << endl;
	}
	return 0;
}
