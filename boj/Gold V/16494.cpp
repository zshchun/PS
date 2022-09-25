#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

ll arr[21];
ll N, M, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	ll i, j, k, part, prev;
	for (i=0;i<N;i++)
		cin >> arr[i];

	ans = -1234567890;
	for (i=0;i<(1<<N);i++) {
		k = 0;
		part = 0;
		prev = 0;
		if (__builtin_popcount(i) < M)
			continue;
		for (j=0;j<N;j++) {
			if ((i>>j)&1) {
				k += arr[j];
				if (prev != 1)
					part++;
				prev = 1;
			} else
				prev = 0;
		}
		if (part <= M)
			ans = max(ans, k);
	}

	cout << ans << endl;
	return 0;
}
