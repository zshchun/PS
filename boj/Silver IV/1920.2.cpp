#include <bits/stdc++.h>
using namespace std;
int N;
int d[100001];
int binary_search(int n) {
	int l = 0;
	int r = N;
	int m = 0;
	while (l <= r) {
		m = (l + r) / 2;
		if (d[m] > n) {
			r = m-1;
		} else if (d[m] < n) {
			l = m+1;
		} else {
			break;
		}
	}
	if (d[m] == n)
		return 1;
	else
		return 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, v, M;
	cin >> N;
	for (i=0;i<N;i++)
		cin >> d[i];
	cin >> M;
	sort(d, d+N);
	for (i=0;i<M;i++) {
		cin >> v;
		cout << binary_search(v) << '\n';
	}

	return 0;
}
