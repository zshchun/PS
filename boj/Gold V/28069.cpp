#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, K, ans = 0;
bool visited[2000001];

void bfs() {
	queue<pa> q;
	q.push(pa(0, 0));
	visited[0] = 1;

	while (!q.empty()) {
		auto [n, cnt] = q.front();
		q.pop();

		if (n == N && cnt <= K)
			ans = 1;
		if (n >= N) continue;

		if (!visited[n+1]) {
			visited[n+1] = 1;
			q.push(pa(n+1, cnt+1));
		}
		if (!visited[n+n/2]) {
			visited[n+n/2] = 1;
			q.push(pa(n+n/2, cnt+1));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, n;
	cin >> N >> K;
	bfs();
	if (ans)
		cout << "minigimbob" << endl;
	else
		cout << "water" << endl;

	return 0;
}
