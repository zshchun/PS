#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __uint128_t u128;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
#define MOD 1000000007
ll n, m, ans;
string t;
vector<string> s;
vector<pl> hist;

void check(ll beg, ll end) {
	ll i, j, idx, pos;
	bool ok = false;
	ll mx = 0;
	for (i=beg;i<=end;i++) {
		for (j=0;j<s.size();j++) {
			if (t.substr(i, s[j].size()) == s[j]) {
				if (i+s[j].size() > mx) {
					ok = true;
					idx = j;
					pos = i;
					mx = i + s[j].size();
				}
			}
		}
	}
	if (ok) {
		ans++;
		hist.push_back(pl(idx+1, pos+1));
		if (pos+s[idx].size() == t.size()) return;
		check(max(beg+1, pos+1), mx);
	} else {
		ans = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, z, l, r;
	cin >> T;
	while(T--) {
		cin >> t;
		cin >> n;
		ans = 0;
		s.resize(n);
		hist.clear();
		for (i=0;i<n;i++)
			cin >> s[i];
		check(0, 0);
		if (ans == 0) {
			cout << "-1\n";
		} else {
			cout << ans << endl;
			for (auto &h: hist)
				cout << h.first << ' ' << h.second << endl;
		}
	}
	return 0;
}
