#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N, ans;
int a[1001];
enum mode {
	INC,
	DEC
};
void dfs(int pos, int last, int acc, mode dir) {
	if (dir == INC)
		dfs(pos, last, acc, DEC);
	if (pos == N) return;
	dfs(pos+1, last, acc, dir);
	if ((dir == INC && last < a[pos]) || (dir == DEC && last > a[pos])) {
		acc++;
		last = a[pos];
		if (ans < acc)
			ans = acc;
		dfs(pos+1, last, acc, dir);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i=0;i<N;i++) {
		cin >> a[i];
	}
	dfs(0, 0, 0, INC);
	cout << ans << '\n';
	return 0;
}

