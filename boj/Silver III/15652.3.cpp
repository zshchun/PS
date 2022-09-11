#include <bits/stdc++.h>
using namespace std;
int N, M;
int d[9];
void backtrack(int n, int m) {
	int i;
	if (m == M) {
		for (i=0;i<M;i++) {
			cout << d[i] << ' ';
		}
		cout << "\n";
		return;
	}
	for (i=n;i<=N;i++) {
		d[m] = i;
		backtrack(i, m+1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	backtrack(1, 0);
	return 0;
}
