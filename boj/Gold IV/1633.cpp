#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
#define endl "\n"
#define INF 123456789
int ans;
int dp[1001][16][16];
vector<pa> v;

int dfs(int i, int w, int b) {
	if (i == v.size())
		return 0;
	if (dp[i][w][b]) return dp[i][w][b];
	int &ret = dp[i][w][b];
	if (w < 15)
		ret = max(ret, dfs(i+1, w+1, b)+v[i].first);
	if (b < 15)
		ret = max(ret, dfs(i+1, w, b+1)+v[i].second);
	return ret = max(ret, dfs(i+1, w, b));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, w, b;
	while (cin >> i >> j) {
		v.push_back(pa(i, j));
	}
	cout << dfs(0, 0, 0) << endl;
	return 0;
}
