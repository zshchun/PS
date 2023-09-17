#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N;
int a[1001];
int visited[1001];

void bfs() {
	int i;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == N)
			return;
		for (i=1;i<=a[cur];i++) {
			int next = cur + i;
			if (next > N)
				continue;
			if (visited[next] == 0 || visited[cur] + 1 < visited[next]) {
				visited[next] = visited[cur] + 1;
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i;
	cin >> N;
	for (i=1;i<=N;i++)
		cin >> a[i];
	if (N == 1) {
		cout << "0\n";
		return 0;
	}

	bfs();
	if (visited[N] == 0)
		cout << "-1\n";
	else
		cout << visited[N] << endl;

	return 0;
}
