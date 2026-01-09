#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
#define endl "\n"
#define INF 123456789
int ans;

int bm[] = { 0x310, 0x720, 0x640, 0x131, 0x272, 0x464, 0x013, 0x027, 0x046 };
bool visited[1<<12];

void bfs(int init) {
	queue<pa> q;
	q.push(pa(init, 0));
	visited[init] = 1;
	while (!q.empty()) {
		auto &[cur, cnt] = q.front();
		q.pop();
		if (cur == 0) {
			ans = cnt;
			break;
		}
		for (int i=0;i<9;i++) {
			int next = cur ^ bm[i];
			if (visited[next]) continue;
			visited[next] = 1;
			q.push(pa(next, cnt+1));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int P, i, j, k;
	char c;
	cin >> P;
	while (P--) {
		k = 0;
		memset(visited, 0, sizeof(visited));
		for (i=0;i<3;i++) {
			for (j=0;j<3;j++) {
				cin >> c;
				if (c == '*')
					k |= (1 << ((i * 4) + j));
			}
		}
		bfs(k);
		cout << ans << endl;
	}
	return 0;
}
