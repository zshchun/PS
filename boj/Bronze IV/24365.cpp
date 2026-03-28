#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a[3], i, avg = 0, ans = 0;
	for (i=0;i<3;i++) {
		cin >> a[i];
		avg += a[i];
	}
	avg /= 3;
	for (i=1;i<3;i++)
		ans += (a[i] - avg) * i;
	cout << ans << endl;

	return 0;
}
