#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int p[100001];
int N, M, ans;

// union-find
int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
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
	int i, u, v;
	cin >> N >> M;

	fill_n(p, 100001, -1);
	for (i=0;i<M;i++) {
		cin >> u >> v;
		u--; v--;
		// check cycle
		if (find(u) != find(v))
			_union(u, v);
		else
			ans++;
	}
	set<int> grp;
	for (i=0;i<N;i++)
		grp.insert(find(i));

	cout << ans + grp.size() - 1 << endl;
	return 0;
}
