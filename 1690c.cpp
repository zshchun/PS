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
	ll T, i, j, x, v, ans;
	cin >> T;
	while(T--) {
		cin >> n;
		vector<ll> a(n);
		vector<ll> b(n);
		ans = 0;
		for (i=0;i<n;i++) {
			cin >> a[i];
		}
		for (i=0;i<n;i++) {
			cin >> b[i];
			if (i > 0) {
				a[i] = max(b[i-1], a[i]);
			}
		}
		for (i=0;i<n;i++) {
			if (i>0) cout << " ";
			cout << b[i] - a[i];
		}
		cout << endl;
	}
	return 0;
}
