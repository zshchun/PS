#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int p[1000001];

int find(int x) {
	if (p[x] < 0)
		return x;
	p[x] = find(p[x]);
	return p[x];
}

void _union(int x, int y) {
	int a = find(x);
	int b = find(y);
	if (a != b) {
		p[a] += p[b];
		p[b] = a;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, t, n, m, k, i, u, v;
	cin >> T;
	for (t=1;t<=T;t++) {
		cin >> n >> k;
		fill_n(p, 1000001, -1);
		for (i=0;i<k;i++) {
			cin >> u >> v;
			_union(u, v);
		}
		cin >> m;
		cout << "Scenario " << t << ":\n";
		for (i=0;i<m;i++) {
			cin >> u >> v;
			if (find(u) == find(v))
				cout << "1\n";
			else
				cout << "0\n";
		}
		cout << endl;
	}

	return 0;
}
