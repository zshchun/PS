#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789.0
ll a[501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, N, K, k;
	double avg, r, diff, temp;
	cin >> N >> K;
	for (i=0;i<N;i++)
		cin >> a[i];

	double ans = INF;
	for (k=K;k<=N;k++) {
		for (i=0;i<N-k+1;i++) {
			avg = 0;
			diff = 0;
			for (j=i;j<i+k;j++)
				avg += a[j];
			avg /= k;
			for (j=i;j<i+k;j++) {
				r = a[j] - avg;
				diff += r * r;
			}
			diff /= k;
			temp = sqrt(diff);
			if (ans > temp)
				ans = temp;
		}
	}
	cout << setprecision(11) << ans << endl;

	return 0;
}
