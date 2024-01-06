#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF INT32_MAX
int N, M, limit;
int arr[100001];
// ceil(log2(100001)) = 16.60965
#define MAX_TREE_SIZE (1 << 18)
int tmax[MAX_TREE_SIZE];
int tmin[MAX_TREE_SIZE];
// segment tree

void segtree_init(int node, int s, int e) {
	if (s == e) {
		tmax[node] = tmin[node] = arr[s];
		return;
	}
	int left = node * 2;
	int right = node * 2 + 1;
	int m = (s + e) / 2;

	segtree_init(left, s, m);
	segtree_init(right, m + 1, e);

	tmax[node] = max(tmax[left], tmax[right]);
	tmin[node] = min(tmin[left], tmin[right]);
}

pa segtree_query(int node, int a, int b, int s, int e) {
	if (b < s || e < a) return pa(INF, 0);
	if (a <= s && e <= b) return pa(tmin[node], tmax[node]);

	int left = node * 2;
	int right = node * 2 + 1;
	int m = (s + e) / 2;

	pa l = segtree_query(left, a, b, s, m);
	pa r = segtree_query(right, a, b, m+1, e);
	return pa(min(l.first, r.first), max(l.second, r.second));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, a, b;
	pa ans;
	cin >> N >> M;

	for (i=1;i<=N;i++)
		cin >> arr[i];

	segtree_init(1, 1, N);

	for (i=0;i<M;i++) {
		cin >> a >> b;
		ans = segtree_query(1, a, b, 1, N);
		cout << ans.first << ' ' << ans.second << endl;
	}

	return 0;
}
