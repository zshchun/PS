#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

ll N, ans;
ll cost[11];
ll order[11];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, status, sum, prev, next;
	cin >> N;

	for (i=0;i<N;i++) {
		cin >> cost[i];
	}
	for (i=0;i<N-2;i++) {
		order[i] = i+1;
	}
	do {
		status = 0;
		sum = 0;
		for (i=1;i<=N-2;i++) {
			for (j=0;j<N-2;j++) {
				if (order[j] == i) {
					prev = j + 1 - 1;
					next = j + 1 + 1;
					while (status & (1<<prev)) prev--;
					while (status & (1<<next)) next++;
					status |= (1 << (j+1));
					sum += cost[prev] * cost[next];
					break;
				}
			}
		}
		if (sum > ans)
			ans = sum;
	} while (next_permutation(order, order+(N-2)));

	cout << ans << endl;

	return 0;
}
