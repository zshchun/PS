#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int d[51];
int a[51];
vector<int> g[51];
vector<int> p[51];
int ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, n;
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> a[i];
		if (i) {
			g[a[i]].push_back(i);
			d[i] = d[a[i]] + 1;
		}
	}
	for (i=n-1;i>0;i--) {
		int mx = 0;
		sort(p[i].begin(), p[i].end(), greater<int>());
		for (j=0;j<p[i].size();j++)
			mx = max(mx, p[i][j] + j + 1);
		p[a[i]].push_back(mx);
	}

	sort(p[0].begin(), p[0].end(), greater<int>());
	for (i=0;i<p[0].size();i++)
		ans = max(ans, p[0][i] + i + 1);

	cout << ans << endl;

	return 0;
}
