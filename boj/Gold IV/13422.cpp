#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int ans, all;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, n, m, k, l, r, sum, i;
	cin >> T;
	while (T--) {
		cin >> n >> m >> k;
		vector<int> a(n);
		for (i=0;i<n;i++)
			cin >> a[i];

		if (n == m) {
			ans = accumulate(a.begin(), a.end(), 0);
			if (ans < k)
				cout << "1\n";
			else
				cout << "0\n";
			continue;
		}

		ans = sum = r = 0;
		for (l=0;l<n;l++) {
			while (r - l < m) {
				sum += a[r%n];
				r++;
			}
			if (sum < k) ans++;
			sum -= a[l];
		}
		cout << ans << endl;
	}
	return 0;
}
