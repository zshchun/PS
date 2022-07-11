#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
#define MOD 1000000007
ll n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, z, l, r, ans;
	cin >> T;
	while(T--) {
		cin >> n >> k;
		ans = 0;
		vector<ll> a(n);
		vector<ll> b(n);
		map<ll,ll> s;
		map<ll,ll> e;
		for (i=0;i<n;i++) {
			cin >> a[i];
		}
		for (i=0;i<n;i++) {
			e[a[i]] = i+1;
			if (s.find(a[i]) == s.end())
				s[a[i]] = i+1;
		}
		for (i=0;i<k;i++) {
			cin >> l >> r;
			auto ss = s.find(l);
			auto ee = e.find(r);
			if (ss != s.end() && ee != e.end() && ss->second < ee->second)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
	return 0;
}
