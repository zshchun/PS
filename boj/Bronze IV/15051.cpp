#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int a[3], ans = INF;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, dj, dk;
	for (i=0;i<3;i++)
		cin >> a[i];
	for (i=0;i<3;i++) {
		j = (i + 1) % 3;
		k = (i + 2) % 3;
		dj = abs(i - j);
		dk = abs(i - k);
		ans = min(ans, a[j] * dj * 2 + a[k] * dk * 2);
	}
	cout << ans << endl;
	return 0;
}
