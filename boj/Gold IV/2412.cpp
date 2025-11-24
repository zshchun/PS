#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int,int,int> tup;
#define endl "\n"
#define INF 123456789
int n, T, ans = INF;
vector<pa> a;
int visited[50001];
#define X first
#define Y second

void bfs() {
	int cur, x, y, d, lx, ly, ux, uy;
	queue<pa> q;
	q.push(pa(0,0));
	visited[0] = 1;
	while (!q.empty()) {
		tie(cur, d) = q.front();
		q.pop();
		tie(x, y) = a[cur];
		if (y == T)
			ans = min(ans, d);
		lx = max(0, x-2); ly = max(0, y-2);
		int s = lower_bound(a.begin(), a.end(), pa(lx, ly)) - a.begin();
		int e = upper_bound(a.begin(), a.end(), pa(x+2, y+2)) - a.begin();
		for (int next = s; next < e && next <= n; next++) {
			if (abs(a[next].X - a[cur].X) > 2 || abs(a[next].Y - a[cur].Y) > 2)
				continue;
			if (visited[next]) continue;
			visited[next] = visited[cur] + 1;
			q.push(pa(next, d+1));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i;
	cin >> n >> T;
	a.resize(n+1);
	for (i=1;i<=n;i++)
		cin >> a[i].X >> a[i].Y;
	a[0].X = a[0].Y = 0;
	sort(a.begin(), a.end());
	bfs();
	if (ans == INF)
		ans = -1;
	cout << ans << endl;
	return 0;
}
