#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int a[21];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, i, j, sum, mx = 0;
	cin >> N;
	for (i=0;i<N;i++) {
		cin >> a[i];
	}
	set<int> s;
	for (i=1;i<1<<N;i++) {
		sum = 0;
		for (j=0;j<N;j++) {
			if (i & (1<<j)) {
				sum += a[j];
			}
		}
		mx = max(mx, sum);
		s.insert(sum);
	}
	int ans = 1;
	while (1) {
		if (s.count(ans) == 0)
			break;
		ans++;
	}
	cout << ans << endl;
	return 0;
}
