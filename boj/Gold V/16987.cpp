#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int N, ans;
int s[9];
int w[9];

void backtrack(int cur, int broken) {
	if (cur == N) {
		ans = max(ans, __builtin_popcount(broken));
		return;
	}

	if (broken & (1 << cur) || __builtin_popcount(broken) == N-1) {
		backtrack(cur+1, broken);
		return;
	}
	for (int i=0;i<N;i++) {
		if (i == cur) continue;
		if (broken & (1 << i)) continue;
		s[i] -= w[cur];
		s[cur] -= w[i];
		int bits = 0;
		if (s[i] <= 0) bits |= 1 << i;
		if (s[cur] <= 0) bits |= 1 << cur;
		backtrack(cur+1, broken | bits);
		s[i] += w[cur];
		s[cur] += w[i];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> N;
	for (i=0;i<N;i++)
		cin >> s[i] >> w[i];
	backtrack(0, 0);
	cout << ans << endl;
	return 0;
}
