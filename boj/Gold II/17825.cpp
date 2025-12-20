#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
#define END 32
int ans;
vector<int> g[END+1];
int score[33] = { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 13, 16, 19, 25, 22, 24, 28, 27, 26, 30, 35, 0 };
int dice[10];

int move(int x, int cnt) {
	if (x == END) return END;
	x = g[x].front();
	for (int i=0;i < cnt - 1 && x < END;i++)
		x = g[x].back();
	return x;
}

void dfs(int horse[4], int n, int sum) {
	int next[4];
	if (n == 10) {
		ans = max(ans, sum);
		return;
	}
	memcpy(next, horse, sizeof(int)*4);
	for (int i=0;i<4;i++) {
		next[i] = move(horse[i], dice[n]);
		bool dup = false;
		for (int j=0;j<4;j++)
			if (i != j && next[i] != END && next[i] == next[j])
				dup = true;
		if (!dup)
			dfs(next, n+1, sum+score[next[i]]);
		next[i] = horse[i];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, h[4] = {0, 0, 0, 0};
	g[5].push_back(21);
	g[21].push_back(22);
	g[22].push_back(23);
	g[23].push_back(24);

	g[10].push_back(25);
	g[25].push_back(26);
	g[26].push_back(24);

	g[15].push_back(27);
	g[27].push_back(28);
	g[28].push_back(29);
	g[29].push_back(24);

	g[24].push_back(30);
	g[30].push_back(31);
	g[31].push_back(20);
	g[20].push_back(32);
	for (i=0;i<20;i++)
		g[i].push_back(i+1);

	for (i=0;i<10;i++)
		cin >> dice[i];

	dfs(h, 0, 0);

	cout << ans << endl;
	return 0;
}
