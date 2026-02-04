#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef tuple<int,int,int> tup;
#define endl "\n"
#define INF 123456789
int N, K, ans = INF;
int a[101][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, x, cnt;
	cin >> N >> K;
	for (i=0;i<N;i++)
		for (j=0;j<3;j++)
			cin >> a[i][j];

	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			for (k=0;k<N;k++) {
				cnt = 0;
				for (x=0;x<N;x++)
					if (a[i][0] >= a[x][0] && a[j][1] >= a[x][1] && a[k][2] >= a[x][2])
						cnt++;
				if (cnt >= K)
					ans = min(ans, a[i][0] + a[j][1] + a[k][2]);
			}
		}
	}
	cout << ans << endl;

	return 0;
}
