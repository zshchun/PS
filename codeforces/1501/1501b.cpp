#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
ll n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, x, ans;
	cin >> T;
	while(T--) {
		cin >> n;
		vector<ll> a(n+2, 0);
		for (i=1;i<=n;i++) {
			cin >> x;
			a[max(1ll, i-x+1)]++;
			a[i+1]--;
		}
		for (i=1;i<=n;i++) {
			a[i] += a[i-1];
			cout << (a[i] ? "1 " : "0 ");
		}
		cout << endl;
	}
	return 0;
}
