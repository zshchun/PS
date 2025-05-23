#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int n, ans;
int a[300001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int i, prev = 0;
	for (i=0;i<n;i++)
		cin >> a[i];

	ans = n;
	for (i=n-1;i>=0;i--)
		if (a[i] == ans)
			ans--;
	cout << ans << endl;
	return 0;
}
