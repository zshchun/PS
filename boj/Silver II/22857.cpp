#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int a[50001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, n, k, ans, cnt, r;
	cin >> n >> k;
	for (i=0;i<n;i++)
		cin >> a[i];

	ans = cnt = r = 0;
	for (i=0;i<n;i++) {
		while (r < n) {
			if ((a[r] % 2) == 1 && k <= 0)
				break;
			if ((a[r] % 2) == 1)
				k--;
			else
				cnt++;
			r++;
		}
		ans = max(cnt, ans);
		if ((a[i] % 2) == 1)
			k++;
		else
			cnt--;
	}
	cout << ans << endl;
	return 0;
}
