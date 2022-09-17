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
		cin >> n;
		vector<ll> a(n);
		for (i=0;i<n;i++) {
			cin >> a[i];
		}
		string s;
		for (i=0;i<n;i++) {
			cin >> k;
			cin >> s;
			reverse(s.begin(), s.end());
			for (j=0;j<k;j++) {
				if (s[j] == 'D') {
					a[i]++;
					if (a[i] > 9) a[i] = 0;
				} else if (s[j] == 'U') {
					a[i]--;
					if (a[i] < 0) a[i] = 9;
				}
			}
		}
		for (i=0;i<n;i++)
			cout << a[i] << ' ';
		cout << endl;
	}
	return 0;
}
