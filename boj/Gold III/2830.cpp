#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll N, ans;
ll zero[21];
ll one[21];
ll a[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> N;
	for (i=0;i<N;i++) {
		cin >> a[i];
		for (j=0;j<20;j++)
			if (a[i] & (1ull << j))
				one[j]++;
	}

	for (j=0;j<20;j++)
		zero[j] = N - one[j];

	for (j=0;j<20;j++)
		ans += zero[j] * one[j] * (1ull << j);

	cout << ans << endl;
	return 0;
}
