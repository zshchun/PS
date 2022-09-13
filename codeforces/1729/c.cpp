#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __uint128_t u128;
typedef pair<ll,ll> pa;
#define endl "\n"
#define MOD 1000000007
#define INF (1LL<<60)
ll n, m, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll TC, i, j, k;
	cin >> TC;
	while(TC--) {
		string s;
		cin >> s;
		char beg = s[0];
		char end = s[s.size()-1];
		multimap<char, ll> b;
		for (i=1;i<=s.size();i++) {
			b.insert(make_pair(s[i-1], i));
		}
		ans = 0;
		m = 0;
		bool rev = false;
		if (beg > end) {
			swap(beg, end);
			rev = true;
		}
		char prev = beg;
		vector<ll> path;
		for (auto it=b.begin();it!=b.end();it++) {
			char x = it->first;
			ll y = it->second;
			if (x >= beg && x <= end) {
				ans += abs(prev - x);
				m++;
				prev = x;
				path.push_back(y);
			}
		}
		if (rev) {
			reverse(path.begin(), path.end());
			swap(beg, end);
		}
		for (i=0;i<path.size();i++) {
			if (path[i] == 1)
				swap(path[0], path[i]);
			else if (path[i] == s.size())
				swap(path[i], path[path.size()-1]);
		}
		cout << ans << " " << m << endl;
		for (i=0;i<path.size();i++) {
			cout << path[i] << ' ';
		}
		cout << endl;

	}
	return 0;
}
