#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, M, cnt, scc;
vector<int> g[20002];
vector<int> ans;
stack<int> st;
int visited[20002];
int low[20002];
int used[20002];
int sccid[20002];

// 2-SAT, Tarzan SCC
void dfs(int u) {
	visited[u] = low[u] = ++cnt;
	st.push(u);
	used[u] = 1;
	for (int &v : g[u]) {
		if (!visited[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if (used[v]) {
			low[u] = min(low[u], visited[v]);
		}
	}

	if (low[u] == visited[u]) {
		scc++;
		while (!st.empty()) {
			int cur = st.top();
			st.pop();
			used[cur] = 0;
			sccid[cur] = scc;
			if (u == cur) break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, a, b;
	bool possible = true;

	cin >> N >> M;
	for (i=0;i<M;i++) {
		cin >> a >> b;
		a = a > 0 ? (a-1)*2 : (~a)*2+1;
		b = b > 0 ? (b-1)*2 : (~b)*2+1;
		g[a^1].push_back(b);
		g[b^1].push_back(a);
	}

	for (i=0;i<N*2;i++)
		if (!visited[i])
			dfs(i);

	for (i=0;i<N;i++) {
		if (sccid[i*2] == sccid[i*2+1]) {
			possible = false;
			break;
		} else if (sccid[i*2] < sccid[i*2+1]) {
			ans.push_back(1);
		} else {
			ans.push_back(0);
		}
	}

	if (possible) { 
		cout << "1\n";
		for (int &v : ans)
			cout << v << ' ';
		cout << endl;
	} else {
		cout << "0\n";
	}

	return 0;
}
