#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

vector<pa> o;
int a[6][3];
int score[6][3];
bool ans;

void backtrack(int n) {
	if (n == o.size()) {
		if (memcmp(a, score, sizeof(a)) == 0)
			ans = true;
		return;
	}
	auto [x, y] = o[n];
	a[x][0]++; a[y][2]++;
	backtrack(n+1);
	a[x][0]--; a[y][2]--;

	a[x][1]++; a[y][1]++;
	backtrack(n+1);
	a[x][1]--; a[y][1]--;

	a[x][2]++; a[y][0]++;
	backtrack(n+1);
	a[x][2]--; a[y][0]--;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t, i, j;
	for (i=0;i<5;i++)
		for (j=i+1;j<6;j++)
			o.push_back(pa(i, j));
	
	for (t=0;t<4;t++) {
		for (i=0;i<6;i++)
			for (j=0;j<3;j++)
				cin >> score[i][j];
		ans = false;
		backtrack(0);
		cout << ans << ' ';
	}

	return 0;
}
