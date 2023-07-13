#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
string a[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, N, i, j, k, l, ans;
	cin >> T;
	while (T--) {
		cin >> N;
		for (i=0;i<N;i++)
			cin >> a[i];

		if (N > 32)
			N = 33;
		ans = INF;
		for (i=0;i<N;i++) {
			for (j=i+1;j<N;j++) {
				for (k=j+1;k<N;k++) {
					int score = 0;
					for (l=0;l<4;l++) {
						if (a[i][l] != a[j][l]) score++;
						if (a[i][l] != a[k][l]) score++;
						if (a[j][l] != a[k][l]) score++;
					}
					if (score < ans)
						ans = score;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
