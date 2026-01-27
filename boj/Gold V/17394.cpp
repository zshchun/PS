#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
#define MAX 500000
int T, ans;
bool not_prime[MAX+1];
bool visited[MAX+1];

void bfs(int n, int a, int b) {
	queue<pa> q;
	int cur, cnt;
	q.push(pa(n, 0));
	visited[n] = 1;
	while (!q.empty()) {
		tie(cur, cnt) = q.front();
		q.pop();
		if (cur >= a && cur <= b && !not_prime[cur]) {
			ans = cnt;
			break;
		}
		if (cur && !visited[cur/3]) {
			q.push(pa(cur/3, cnt+1));
			visited[cur/3] = 1;
		}
		if (cur && !visited[cur/2]) {
			q.push(pa(cur/2, cnt+1));
			visited[cur/2] = 1;
		}
		if (cur+1 < MAX && !visited[cur+1]) {
			q.push(pa(cur+1, cnt+1));
			visited[cur+1] = 1;
		}
		if (cur-1 >= 0 && !visited[cur-1]) {
			q.push(pa(cur-1, cnt+1));
			visited[cur-1] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, a, b, i, j;
	for (i=2;i*i<=MAX;i++) {
		if (not_prime[i]) continue;
		for (j=i+i;j<=MAX;j+=i)
			not_prime[j] = 1;
	}

	cin >> T;
	while (T--) {
		ans = INF;
		memset(visited, 0, sizeof(visited));

		cin >> n >> a >> b;
		bfs(n, a, b);
		if (ans == INF)
			cout << "-1\n";
		else
			cout << ans << endl;
	}
	return 0;
}
