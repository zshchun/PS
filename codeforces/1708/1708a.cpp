#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
#define MOD 1000000007
ll n, m, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, z, l, r;
	cin >> T;
	while(T--) {
		cin >> n;
		ans = 0;
		vector<ll> a(n);
		for (i=0;i<n;i++) {
			cin >> a[i];
		}
		for (i=1;i<n;i++) {
			if (a[i] % a[0]) break;
		}
		if (i == n)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
