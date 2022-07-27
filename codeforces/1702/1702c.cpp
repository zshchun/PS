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
		vector<ll> a(n);
		vector<ll> b(n);
		for (i=0;i<n;i++) {
			cin >> a[i];
			b[i] = a[i];
		}
		sort(b.begin(), b.end());
		b.erase(unique(b.begin(), b.end()), b.end());
		vector<ll> s(b.size(), 0);
		vector<ll> e(b.size(), 0);
		for (i=0;i<n;i++) {
			j = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
			e[j] = i+1;
			if (!s[j]) s[j] = i+1;
		}
		for (i=0;i<k;i++) {
			ll from, to;
			cin >> from >> to;
			ll f = lower_bound(b.begin(), b.end(), from) - b.begin();
			ll t = lower_bound(b.begin(), b.end(), to) - b.begin();
			if (f < b.size() && t < b.size() && b[f] == from && b[t] == to && s[f] && e[t] && s[f] < e[t]) 
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
	return 0;
}
