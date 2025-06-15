#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll n, m, s, e, ans;
ll ind[10001];
ll mx[10001];
bool visited[10001];
vector<pa> g[10001];
vector<pa> rev[10001];

void topological_sort_max() {
	queue<ll> q;
	ll i, next, d, cur;
	q.push(s);
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		if (visited[cur]) continue;
		visited[cur] = 1;
		for (pa &pp: g[cur]) {
			tie(next, d) = pp;
			mx[next] = max(mx[next], mx[cur]+d);
			ind[next]--;
			if (!ind[next])
				q.push(next);
		}
	}
}

void topological_sort_count() {
	queue<ll> q;
	ll i, next, d, cur;
	q.push(e);
	visited[e] = 1;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (pa &pp: rev[cur]) {
			tie(next, d) = pp;
			if (mx[next] + d == mx[cur]) {
				ans++;
				if (!visited[next]) {
					visited[next] = 1;
					q.push(next);
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, u, v, d;
	cin >> n >> m;
	for (i=0;i<m;i++) {
		cin >> u >> v >> d;
		u--; v--;
		g[u].push_back(pa(v, d));
		rev[v].push_back(pa(u, d));
		ind[v]++;
	}
	cin >> s >> e;
	s--; e--;

	topological_sort_max();
	memset(visited, 0, sizeof(visited));
	topological_sort_count();

	cout << mx[e] << endl;
	cout << ans << endl;
	return 0;
}
