#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

vector<int> g[51];
bool visited[51];
int cnt, ans, N;

void dfs(int x, int n) {
	if (n > 2) return;
//	if (visited[x]) return;
	visited[x] = 1;
	for (int y : g[x]) {
		dfs(y, n + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	string s;
	cin >> N;
	for (i=0;i<N;i++) {
		cin >> s;
		for (j=0;j<N;j++) {
			if (s[j] == 'Y') {
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}
	for (i=0;i<N;i++) {
		cnt = 0;
		memset(visited, 0, sizeof(visited));
		dfs(i, 0);
		for (j=0;j<N;j++)
			if (visited[j]) cnt++;
		ans = max(ans, cnt);
	}
	cout << ans - 1 << endl;
	return 0;
}
