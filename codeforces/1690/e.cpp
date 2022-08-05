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
	ll T, i, j, k, x, v, ans;
	cin >> T;
	while(T--) {
		cin >> n >> k;
		vector<ll> a(n);
		ans = 0;
		for (i=0;i<n;i++) {
			cin >> a[i];
			ans += a[i] / k;
			a[i] = a[i] % k;
		}
		sort(a.begin(), a.end(), greater<ll>());
		for (i=0,j=n-1;i<j;i++) {
			while (i < j && a[i]+a[j] < k) {
				j--;
			}
			if (i >= j) break;
			ans++;
			j--;
		}

		cout << ans << endl;
	}
	return 0;
}
