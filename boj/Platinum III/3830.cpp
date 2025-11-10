#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 12345678901234
#define MAX (1<<18)
int N, M;
int p[100001];
int d[100001];

ll find(int x) {
	if (p[x] < 0) return x;
	int pp = find(p[x]);
	d[x] += d[p[x]];
	return p[x] = pp;
}

void _union(int x, int y, int w) {
	int a = find(x);
	int b = find(y);
	if (a != b) {
		p[a] += p[b];
		p[b] = a;
		d[b] = d[x] - d[y] + w;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	char c;
	int i, j, a, b, w;
	while (1) {
		cin >> N >> M;
		memset(d, 0, sizeof(d));
		fill_n(p, 100001, -1);
		if (N == 0 && M == 0) break;
		for (i=0;i<M;i++) {
			cin >> c;
			if (c == '!') {
				cin >> a >> b >> w;
				_union(a, b, w);
			} else if (c == '?') {
				cin >> a >> b;
				if (find(a) != find(b))
					cout << "UNKNOWN\n";
				else
					cout << d[b] - d[a] << endl;
			}

		}
	}
	return 0;
}
