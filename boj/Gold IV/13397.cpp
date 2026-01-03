#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
#define endl "\n"
#define INF 123456789
int a[5001];
int N, M;

int check(int m) {
	int cnt = 1, mx = a[0], mn = a[0];
	for (int i=1;i<N;i++) {
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
		if (mx - mn > m) {
			cnt++;
			mx = a[i];
			mn = a[i];
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, l = 0, r = 0;
	cin >> N >> M;
	for (i=0;i<N;i++) {
		cin >> a[i];
		r = max(a[i], r);
	}

	while (l <= r) {
		int m = (l + r) / 2;
		if (check(m) > M) {
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	cout << l << endl;
	return 0;
}
