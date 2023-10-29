#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N;
bool palin[2501][2501];
int dp[2501];

int dfs(int cur) {
	if (cur >= N) return 0;
	if (dp[cur] != INF)
		return dp[cur];

	int &ret = dp[cur];

	for (int i=0;cur+i<N;i++) {
		if (palin[cur][cur+i])
			ret = min(ret, dfs(cur+i+1)+1);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, beg, end;
	string s;
	cin >> s;
	N = s.size();
	for (i=0;i<N;i++) {
		palin[i][i] = true;
		if (i && s[i-1] == s[i])
			palin[i-1][i] = true;
	}
	fill(dp, dp+N+1, INF);

	for (end=2;end<N;end++) {
		for (beg=0;beg<end;beg++) {
			if (s[beg] == s[end] && palin[beg+1][end-1])
				palin[beg][end] = true;
		}
	}

	cout << dfs(0) << endl;

	return 0;
}
