#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 1234567890
int N, M;
int a[100001];
int tree[262145];
int segment_tree(int s, int e, int n) {
	if (s == e) return tree[n] = s;
	int m = (s+e)/2;
	int q = segment_tree(s, m, n*2);
	int w = segment_tree(m+1, e, n*2+1);
	if (a[q] <= a[w])
		tree[n] = q;
	else
		tree[n] = w;
	return tree[n];
}

int query(int s, int e, int n, int l, int r) {
	if (r < s || e < l) return N-1;
	if (l <= s && e <= r)
		return tree[n];
	int m = (s+e)/2;
	int q = query(s, m, n*2, l, r);
	int w = query(m+1, e, n*2+1, l, r);
	if (a[q] <= a[w])
		return q;
	else
		return w;
}

void update(int s, int e, int n, int idx, int d) {
	if (idx < s || e < idx) return;
	if (s == e) {
		tree[n] = s;
		a[s] = d;
		return;
	}
	int m = (s+e)/2;
	update(s, m, n*2, idx, d);
	update(m+1, e, n*2+1, idx, d);
	if (a[tree[n*2]] <= a[tree[n*2+1]])
		tree[n] = tree[n*2];
	else
		tree[n] = tree[n*2+1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, t;
	cin >> N;
	for (i=0;i<N;i++)
		cin >> a[i];

	a[N] = INF;
	N++;

	cin >> M;
	segment_tree(0, N-1, 1);

	for (i=0;i<M;i++) {
		cin >> t >> j >> k;
		if (t == 1) {
			j--;
			update(0, N-1, 1, j, k);
		} else if (t == 2) {
			j--; k--;
			cout << query(0, N-1, 1, j, k) + 1 << endl;
		}
	}

	return 0;
}
