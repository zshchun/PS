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
	ll TC, i, j, k, x, y;
	cin >> TC;
	while(TC--) {
		cin >> n >> m;
		ans = 0;
		vector<ll> a(m);
		priority_queue<ll> pq1;
		priority_queue<ll> pq2;
		for (i=0;i<m;i++)
			cin >> a[i];
		sort(a.begin(), a.end());
		for (i=0;i<a.size()-1;i++) {
			x = a[i+1] - a[i] - 1;
			if (x == 0) continue;
			pq2.push(x);
		}
		x = a[0] - 1 + n+1 - a[m-1] - 1;
		if (x)
			pq2.push(x);

		ll turn = 0;
		while (!pq1.empty() || !pq2.empty()) {
			ll r;
			if (pq1.empty()) y = 2;
			else if (pq2.empty()) y = 1;
			else if (pq1.top()-turn >= pq2.top()-turn*2) y = 1;
			else y = 2;
			if (y == 1) {
				x = pq1.top();
				r = x - turn;
				pq1.pop();
				if (r <= 0) continue;
				ans += r;
			} else {
				x = pq2.top();
				r = x - turn * 2;
				pq2.pop();
				if (r <= 0) continue;
				pq1.push(x - turn - 1);
				ans++;
			}
			turn++;
		}
		cout << n - ans << endl;
	}
	return 0;
} 
