#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define MAX (1000001)
int N;
int tree[MAX * 4];
int segment_tree(int s, int e, int n) {
	if (s == e) return tree[n];
	int m = (s+e) / 2;
	segment_tree(s, m, n*2);
	segment_tree(m+1, e, n*2+1);
}

int query(int s, int e, int n, int idx) {
	if (s == e) return s;
	int m = (s+e) / 2;
	if (idx <= tree[n*2])
		return query(s, m, n*2, idx);
	else
		return query(m+1, e, n*2+1, idx-tree[n*2]);
}

void update(int s, int e, int n, int idx, int d) {
	if (idx < s || e < idx) return;
	tree[n] += d;
	if (s == e) return;
	int m = (s+e) / 2;
	update(s, m, n*2, idx, d);
	update(m+1, e, n*2+1, idx, d);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, a, b, c, v;
	cin >> N;
	for (i=0;i<N;i++) {
		cin >> a >> b;
		if (a == 1) {
			v = query(1, MAX, 1, b);
			cout << v << endl;
			update(1, MAX, 1, v, -1);
		} else if (a == 2) {
			cin >> c;
			update(1, MAX, 1, b, c);
		}
	}
	return 0;
}
