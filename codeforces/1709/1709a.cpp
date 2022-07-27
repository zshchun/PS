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
		vector<ll> a(4, 0);
		for (i=1;i<=3;i++) {
			cin >> a[i];
		}
		ans = 0;
		while (n != 0) {
			n = a[n];
			ans++;
		}
		if (ans >= 3)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
