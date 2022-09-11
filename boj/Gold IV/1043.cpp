#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int p[51];
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
	int N, M, L, i, j, x, prev;
	cin >> N >> M;
	for (i=0;i<50;i++)
		p[i] = -1;
	cin >> L;
	for (i=0;i<L;i++) {
		cin >> x;
		if (i) _union(prev, x);
		else _union(0, x);
		prev = x;
	}
	vector<int> v[M];
	for (i=0;i<M;i++) {
		cin >> L;
		for (j=0;j<L;j++) {
			cin >> x;
			v[i].push_back(x);
			if (j) _union(prev, x);
			prev = x;
		}
	}
	int ans = 0;
	for (i=0;i<M;i++) {
		if (v[i].size() && find(0) != find(v[i][0]))
			ans++;
	}
	cout << ans << '\n';

	return 0;
}

