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
		g[v].push_back(u);
	}
	for (i=0;i<K;i++) {
		cin >> u >> v;
		if (u == 1) {
			for (int x : g[v]) {
				if (built[x] == 0) {
					cout << "Lier!\n";
					return 0;
				}
			}
			built[v]++;
		} else if (u == 2) {
			if (built[v] == 0) {
				cout << "Lier!\n";
				return 0;
			}
			built[v]--;
		}
	}
	cout << "King-God-Emperor\n";
	return 0;
}
