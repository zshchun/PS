#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

pa a[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, N, i;
	cin >> T;
	while (T--) {
		cin >> N;
		for (i=0;i<N;i++)
			cin >> a[i].first >> a[i].second;

                sort(a, a+N);
                ll lowest = a[0].second;
                ll ans = 1;
                for (i=1;i<N;i++) {
                        if (a[i].second < lowest) {
				ans++;
				lowest = a[i].second;
			}
                }
		cout << ans << endl;

	}
	return 0;
}
