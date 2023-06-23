#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
ll A, B, N, M, ans;
bool visited[100001];

void bfs() {
	ll cur, nth, next;
	queue<pa> q;
	q.push(pa(N, 0));
	visited[N] = 1;
	ll mx[] = { A, B };
	ll dx[] = { A, -A, B, -B, 1, -1 };
	while (!q.empty()) {
		tie(cur, nth) = q.front();
		q.pop();
		if (cur == M) {
			ans = nth;
			break;
		}
		for (ll x : mx) {
			next = cur * x;
			if (next <= 100000 && !visited[next]) {
				q.push(pa(next, nth + 1));
				visited[next] = 1;
			}
		}
		for (ll x : dx) {
			next = cur + x;
			if (next <= 100000 && next >= 0 && !visited[next]) {
				q.push(pa(next, nth + 1));
				visited[next] = 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> A >> B >> N >> M;
	bfs();
	cout << ans << endl;
	return 0;
}
