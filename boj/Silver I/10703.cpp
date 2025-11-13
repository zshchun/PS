#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

char m[3001][3001];
char n[3001][3001];
int x[3001];
int g[3001];
int ans = INF;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, r, s;
	fill_n(x, 3001, -INF);
	fill_n(g, 3001, INF);
	cin >> r >> s;
	for (i=0;i<r;i++) {
		for (j=0;j<s;j++) {
			cin >> m[i][j];
			n[i][j] = m[i][j];
			if (m[i][j] == 'X')
				x[j] = max(x[j], i);
			else if (m[i][j] == '#')
				g[j] = min(g[j], i);
		}
	}

	for (i=0;i<s;i++)
		if (x[i] != -INF && g[i] != INF)
			ans = min(ans, g[i] - x[i] - 1);

	for (i=r-1;i>=0;i--)
		for (j=0;j<s;j++)
			if (m[i][j] == 'X')
				swap(n[i][j], n[i+ans][j]);

	for (i=0;i<r;i++) {
		for (j=0;j<s;j++)
			cout << n[i][j];
		cout << endl;
	}
	return 0;
}
