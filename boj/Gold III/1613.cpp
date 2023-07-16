#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int n, k;
int a[401][401];
vector<int> ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, u, v, s;
	cin >> n >> k;
	for (i=0;i<k;i++) {
		cin >> u >> v;
		a[u][v] = 1;
	}

	// floyd-warshall
	for (k=1;k<=n;k++) {
		for (i=1;i<=n;i++) {
			for (j=1;j<=n;j++) {
				if (a[i][k] && a[k][j])
					a[i][j] = 1;
			}
		}
	}
	
	cin >> s;
	while (s--) {
		cin >> u >> v;
		if (a[u][v]) {
			cout << "-1\n";
		} else if (a[v][u]) {
			cout << "1\n";
		} else {
			cout << "0\n";
		}
	}
	return 0;
}
