#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int N, K;
int a[100001];
int tree[262144+1];

int convert(int i) {
	if (i > 0)
		return 1;
	else if (i < 0)
		return -1;
	return 0;
}

int segment_tree(int s, int e, int n) {
	if (s == e)
		return tree[n] = a[s];
	int m = (s + e) / 2;
	return tree[n] = segment_tree(s, m, n*2) * segment_tree(m+1, e, n*2+1);
}

int mul(int s, int e, int n, int l, int r) {
	if (r < s || e < l) return 1;
	if (l <= s && e <= r) return tree[n];
	int m = (s + e) / 2;
	return mul(s, m, n*2, l, r) * mul(m+1, e, n*2+1, l, r);
}

int update(int s, int e, int n, int idx, int d) {
	if (idx < s || e < idx) return tree[n];
	if (s == e) return tree[n] = d;
	int m = (s + e) / 2;
	return tree[n] = update(s, m, n*2, idx, d) * update(m+1, e, n*2+1, idx, d);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, x;
	char c;
	while (cin >> N) {
		cin >> K;

		for (i=0;i<N;i++) {
			cin >> j;
			a[i] = convert(j);
		}

		segment_tree(0, N-1, 1);

		for (i=0;i<K;i++) {
			cin >> c >> j >> k;
			if (c == 'C') {
				j--;
				a[j] = convert(k);
//				segment_tree(0, N-1, 1);
				update(0, N-1, 1, j, convert(k));
			} else if (c == 'P') {
				j--; k--;
				x = mul(0, N-1, 1, j, k);
				if (x < 0) cout << "-";
				else if (x > 0) cout << '+';
				else cout << "0";
			}
		}
		cout << endl;
	}

	return 0;
}
