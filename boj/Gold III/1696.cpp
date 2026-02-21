#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef pair<string,string> ps;
#define endl "\n"
#define INF 123456789
#define L first
#define R second
int idx, odd;
map<string, int> ids;
vector<pa> a;
int p[500001];
int deg[500001];

int get_id(string &s) {
	if (ids.find(s) != ids.end())
		return ids[s];
	ids[s] = idx++;
	return ids[s];
}

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

// Eulerian path
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, u, v;
	bool possible = true;
	string s, t;
	fill_n(p, 250001, -1);
	while (cin >> s >> t) {
		u = get_id(s);
		v = get_id(t);
		a.push_back(pa(u, v));
		deg[u]++; deg[v]++;
		_union(u, v);
	}
	int root = -1;
	for (i=0;i<idx;i++) {
		if (deg[i] & 1)
			odd++;
		if (deg[i] > 0) {
			if (root == -1) {
				root = find(i);
			} else if (find(i) != root) {
				possible = false;
				break;
			}
		}
	}
	if (odd != 0 && odd != 2)
		possible = false;

	if (possible)
		cout << "Possible\n";
	else
		cout << "Impossible\n";
	return 0;
}
