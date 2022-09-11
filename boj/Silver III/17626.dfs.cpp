#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[225];
int dfs(int i, int x) {
	if (x == 0) return 0;
	if (i > 224) return 999;
	if (x < a[i]) return 999;
	return min(dfs(i+1, x), dfs(i, x-a[i])+1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, i;
	cin >> N;
	for (i=1;i<=224;i++) {
		a[i] = i*i;
	}

	cout << dfs(1, N) << '\n';
	return 0;
}

