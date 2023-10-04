#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
unordered_map<string, int> imap;
int V;
#define INF 123456789
#define S 0
#define T 1

struct Edge {
	int to, c, f;
	Edge *mirror;
	Edge(): Edge(-1, 0) {}
	Edge(int _to, int _c): to(_to), c(_c), f(0), mirror(NULL) {}
	int remain() {
		return c - f;
	}
	void add(int _f) {
		f += _f;
		mirror->f -= _f;
	}
};

int idx(string s) {
	if (imap.count(s))
		return imap[s];
	return (imap[s] = imap.size() + 1);
}

int main() {
	int TC, tc, i, j, k, u, v, N;
	cin >> TC;
	for (tc=1;tc<=TC;tc++) {
		cin >> N;
		string line, s;
		cin.ignore(10000, '\n');

		vector<vector<int>> lines(N);
		imap.clear();

		// flow, minimum-cut
		for (i=0;i<N;i++) {
			getline(cin, line);
			stringstream ss(line);
			while (ss >> s) {
				lines[i].push_back(idx(s));
			}
		}
		int ans = 0;
		vector<Edge*> g[imap.size()*2+2];
		for (int x: lines[0]) {
			u = S;
			v = x * 2;
			Edge *e1 = new Edge(v, INF);
			Edge *e2 = new Edge(u, 0);
			e1->mirror = e2;
			e2->mirror = e1;
			g[u].push_back(e1);
			g[v].push_back(e2);
		}

		for (int x: lines[1]) {
			u = x * 2 + 1;
			v = T;
			Edge *e1 = new Edge(v, INF);
			Edge *e2 = new Edge(u, 0);
			e1->mirror = e2;
			e2->mirror = e1;
			g[u].push_back(e1);
			g[v].push_back(e2);
		}
		for (i=1;i<=imap.size();i++) {
			u = i * 2;
			v = u + 1;
			Edge *e1 = new Edge(v, 1);
			Edge *e2 = new Edge(u, 0);
			e1->mirror = e2;
			e2->mirror = e1;
			g[u].push_back(e1);
			g[v].push_back(e2);
		}

		for (i=2;i<N;i++) {
			for (j=0;j<lines[i].size();j++) {
				for (k=j+1;k<lines[i].size();k++) {
					u = lines[i][j] * 2 + 1;
					v = lines[i][k] * 2;
					Edge *e1 = new Edge(v, INF);
					Edge *e2 = new Edge(u, 0);
					e1->mirror = e2;
					e2->mirror = e1;
					g[u].push_back(e1);
					g[v].push_back(e2);

					u = lines[i][k] * 2 + 1;
					v = lines[i][j] * 2;
					Edge *e3 = new Edge(v, INF);
					Edge *e4 = new Edge(u, 0);
					e3->mirror = e4;
					e4->mirror = e3;
					g[u].push_back(e3);
					g[v].push_back(e4);
				}
			}
		}

		while (1) {
			bool visited[(imap.size()+1)*2] = {0};
			visited[S] = 1;
			queue<int> q;
			q.push(S);
			Edge *pp[(imap.size()+1)*2];

			while (!q.empty()) {
				int cur = q.front();
				q.pop();
				if (cur == T)
					break;
				for (auto &e: g[cur]) {
					int next = e->to;
					if (next && !visited[next] && e->remain() > 0) {
						visited[next] = 1;
						pp[next] = e;
						q.push(next);
					}
				}
			}
			if (!visited[T]) break;

			int flow = INF;
			for (i=T; i != S; i=pp[i]->mirror->to)
				flow = min(flow, pp[i]->remain());

			for (i=T; i != S;  i=pp[i]->mirror->to)
				pp[i]->add(flow);
			ans += flow;
		}
		cout << "Case #" << tc << ": " << ans << '\n';
	}
	return 0;
}
