#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int a[300001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, N, M, l, r, mid, ans = 0;
	cin >> N >> M;

	for (i=0;i<M;i++) {
		cin >> a[i];
	}

	sort(a, a+M);

	// binary search
	l = 1;
	r = a[M-1];
	while (l <= r) {
		mid = (l + r) / 2;
		int child = 0;
		for (i=0;i<M;i++)
			child += (a[i] + mid - 1) / mid;
		if (child <= N) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << l << endl;

	return 0;
}
