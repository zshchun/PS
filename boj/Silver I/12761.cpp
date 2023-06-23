#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
ll A, B, N, M, ans;
bool visited[100001];

void bfs() {
	ll cur, nth;
	queue<pa> q;
	q.push(pa(N, 0));
	while (!q.empty()) {
		tie(cur, nth) = q.front();
		q.pop();
		if (cur == M) {
			ans = nth;
			break;
		}
		if (visited[cur]) continue;
		visited[cur] = 1;
		if (cur * A <= M)
			q.push(pa(cur * A, nth + 1));
		if (cur * B <= M)
			q.push(pa(cur * B, nth + 1));
		if (cur + A <= M)
			q.push(pa(cur + A, nth + 1));
		if (cur + B <= M)
			q.push(pa(cur + B, nth + 1));
		if (cur + 1 <= M)
			q.push(pa(cur + 1, nth + 1));
		if (cur - A >= 0)
			q.push(pa(cur - A, nth + 1));
		if (cur - B >= 0)
			q.push(pa(cur - B, nth + 1));
		if (cur - 1 >= 0)
			q.push(pa(cur - 1, nth + 1));
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
