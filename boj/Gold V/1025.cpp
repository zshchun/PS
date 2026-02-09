#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
ll ans = -1;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, k, l, n, m, x, y, z;
	unordered_set<ll> q;
	for (i=0;i*i<1'000'000'000;i++)
		q.insert(i*i);
	cin >> n >> m;
	string s[n];
	for (i=0;i<n;i++)
		cin >> s[i];
	for (i=0;i<n;i++) {
		for (j=0;j<m;j++) {
			for (k=-n;k<=n;k++) {
				for (l=-m;l<=m;l++) {
					if (k == 0 && l == 0) continue;
					string t;
					x = j;
					y = i;
					while (x >= 0 && y >= 0 && x < m && y < n) {
						t += s[y][x];
						y += k;
						x += l;
						z = stoi(t);
						if (q.count(z) > 0 && z > ans)
							ans = z;
					}
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}
