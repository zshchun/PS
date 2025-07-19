#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int ans[80001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, n;
	for (i=3;i<=80000;i++) {
		ans[i] = ans[i-1];
		if ((i % 3) == 0 || (i % 7) == 0)
			ans[i] += i;
	}
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> j;
		cout << ans[j] << endl;
	}

	return 0;
}
