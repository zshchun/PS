#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
ll n, m;
int cnt[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, x, ans;
	cin >> T;
	while(T--) {
		cin >> n;
		vector<ll> a(n*2);
		vector<ll> r(n*2);
		for (i=0;i<n*2;i++)
			cin >> a[i];
		sort(a.begin(), a.end());
		bool ok = false;
		for (i=0;i<n * 2 - 1;i++) {
			for (k=0;k<n*2;k++) cnt[a[k]] = 0;
			for (k=0;k<n*2;k++) cnt[a[k]]++;
			ll x = a[i] + a[n*2-1];
			j = n * 2 - 1;
			for (k=0;k<n;k++) {
				while (cnt[a[j]] == 0 && j > 0) j--;
				ll s = x - a[j];
				cnt[s]--;
				cnt[a[j]]--;
				r[k*2] = s;
				r[k*2+1] = a[j];
				if (cnt[s] < 0 || cnt[a[j]] < 0) {
					break;
				}
				x = max(s, a[j]);
			}
			if (k == n) {
				ok = true;
				break;
			}
		}
		for (k=0;k<n*2;k++) cnt[a[k]] = 0;
		if (ok) {
			cout << "YES\n";
			cout << r[0] + r[1] << endl;
			for (i=0;i<n;i++) {
				cout << r[i*2] << ' ' << r[i*2+1] << endl;
			}
		} else
			cout << "NO\n";
	}
	return 0;
}
