#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int N, M;
int a[9];
void dfs(int c, int n) {
	int i;
	if (c == M) {
		for (i=0;i<M;i++)
			cout << a[i] << ' ';
		cout << '\n';
		return;
	}
	for (i=n;i<=N;i++) {
		a[c] = i;
		dfs(c+1, i);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	dfs(0, 1);
	return 0;
}
