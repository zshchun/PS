#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int a[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
        int i, j, k, n, x, y, m, u, v;
        cin >> n >> x >> y >> m;

        for (i=1;i<=n;i++) {
                for (j=1;j<=n;j++) {
                        a[i][j] = INF;
                }
        }

        for (i=0;i<m;i++) {
                cin >> u >> v;
                a[u][v] = 1;
                a[v][u] = 1;
        }

        // floyd-warshall
        for (k=1;k<=n;k++) {
                for (i=1;i<=n;i++) {
                        for (j=1;j<=n;j++) {
                                if (a[i][k] + a[k][j] < a[i][j])
                                        a[i][j] = a[i][k] + a[k][j];
                        }
                }
        }
        if (a[x][y] == INF)
                cout << "-1\n";
        else
                cout << a[x][y] << endl;
	return 0;
}
