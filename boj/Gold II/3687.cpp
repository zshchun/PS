#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 10000000000000000ull
int T;
string mx;
ll mn = INF;
int cost[7][2] = { {7, 8}, {6, 6}, {6, 0}, {5, 2}, {4, 4}, {3, 7}, {2, 1} };
// int cost[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
//		   0, 1, 2, 3, 4, 5, 6, 7, 8, 9
//		  -1,-1, 1, 7, 4, 2,0/6,8, 

void dfs(int x, ll s) {
	if (s > INF) return;
	if (x == 0 && s < mn)
		mn = s;
	if (x < 2 || s > mn)
		return;
	if (s != 0 && x > 20) {
		dfs(x - 7, s * 10 + 8);
		dfs(x - 6, s * 10);
		return;
	}
	for (int i=0;i<7;i++) {
		if (x < cost[i][0]) continue;
		ll ns = s * 10 + cost[i][1];
		if (ns == 0) continue;
		dfs(x-cost[i][0], ns);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, v;
	cin >> T;
	while (T--) {
		cin >> v;
		mx = "";
		mn = INF;
		dfs(v, 0);
		if (v & 1) {
			mx = "7";
			v -= 3;
		}
		while (v) {
			mx += "1";
			v -= 2;
		}
		cout << mn << " " << mx << endl;
	}
	return 0;
}
