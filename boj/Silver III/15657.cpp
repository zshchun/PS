#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int N, M;
int ns[9];
int a[9];
void backtrack(int c, int n) {
	int i;
	if (c == M) {
		for (i=0;i<M;i++)
			cout << a[i] << ' ';
		cout << '\n';
		return;
	}
	for (i=n;i<=N;i++) {
		a[c] = ns[i];
		backtrack(c+1, i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i;
	cin >> N >> M;
	for (i=1;i<=N;i++)
		cin >> ns[i];
	sort(ns+1, ns+N+1);
	backtrack(0, 1);
	return 0;
}

