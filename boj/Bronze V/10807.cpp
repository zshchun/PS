#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int a[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, n, v, ans = 0;
	cin >> n;
	for (i=0;i<n;i++)
		cin >> a[i];
	cin >> v;
	for (i=0;i<n;i++)
		if (a[i] == v)
			ans++;
	cout << ans << endl;

	return 0;
}
