#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int N;
int t[10001];
void solve(int s, int e) {
	if (s >= e) return;
	int root = t[s];
	int m = upper_bound(t+s+1, t+e, root)-t;
	solve(s+1, m);
	solve(m, e);
	cout << root << '\n';
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i;
	while (cin >> i)
		t[N++] = i;
	solve(0, N);
	return 0;
}

