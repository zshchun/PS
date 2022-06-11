#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N;
int v[10001];
int dfs(int n, int s, int e) {
	int root = v[n];
	if (n+1 < N && v[n+1] < root && v[n+1] > s)
		n = dfs(n+1, s, root);
	if (n+1 < N && v[n+1] > root && v[n+1] < e)
		n = dfs(n+1, root, e);
	cout << root << '\n' << flush;
	return n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i;
	while (cin >> i) {
		v[N++] = i;
	}
	dfs(0, 0, 9999999);
	return 0;
}

