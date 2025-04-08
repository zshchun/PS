#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int ans;
int a[11];
int b[11];

void dfs(int n, int score) {
	if (n == 10) {
		if (score >= 5)
			ans++;
		return;
	}

	for (int i=1;i<=5;i++) {
		if (n >= 2 && a[n-2] == i && a[n-1] == i)
			continue;
		a[n] = i;
		dfs(n+1, score + (b[n] == i));
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i;
	for (i=0;i<10;i++)
		cin >> b[i];
	
	dfs(0, 0);
	cout << ans << endl;

	return 0;
}
