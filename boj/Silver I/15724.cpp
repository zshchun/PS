#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll N, M, K;
ll a[1025][1025];
ll s[1025][1025];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, y1, x1, y2, x2;;
	cin >> N >> M;
	for (i=1;i<=N;i++) {
		for (j=1;j<=M;j++) {
			cin >> a[i][j];
			s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
		}
	}

	cin >> K;
	for (i=0;i<K;i++) {
		cin >> y1 >> x1 >> y2 >> x2;
		y1--; x1--;
		ll sum = s[y2][x2] - s[y1][x2] - s[y2][x1] + s[y1][x1];
		cout << sum << endl;
	}
	return 0;
}
