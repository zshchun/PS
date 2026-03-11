#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, M, K;
vector<int> g[100001];
int ind[100001];
int built[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int u, v, i;
	cin >> N >> M >> K;
	for (i=0;i<M;i++) {
		cin >> u >> v;
		g[u].push_back(v);
		ind[v]++;
	}
	bool possible = true;
	for (i=0;i<K;i++) {
		cin >> u >> v;
		if (u == 1) {
			if (ind[v]) {
				possible = false;
				break;
			}
			built[v]++;
			if (built[v] == 1) 
				for (int x : g[v])
					ind[x]--;
		} else if (u == 2) {
			if (built[v] == 0) {
				possible = false;
				break;
			}
			built[v]--;
			if (built[v] == 0)
				for (int x : g[v])
					ind[x]++;
		}
	}
	if (possible)
		cout << "King-God-Emperor\n";
	else
		cout << "Lier!\n";
	return 0;
}
