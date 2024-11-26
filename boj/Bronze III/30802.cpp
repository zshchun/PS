#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int a[6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, N, T, P, ans = 0;

	cin >> N;
	for (i=0;i<6;i++)
		cin >> a[i];
	cin >> T >> P;

	for (i=0;i<6;i++) {
		ans += (a[i] + T - 1) / T;
	}
	cout << ans << endl;
	cout << N / P << " " << N % P << endl;

	return 0;
}
