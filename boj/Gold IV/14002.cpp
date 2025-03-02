#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int n, ans, last;
int a[1001];
int dp[1001];
int p[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;

	cin >> n;
	for (i=1;i<=n;i++)
		cin >> a[i];

	for (i=1;i<=n;i++) {
		for (j=0;j<i;j++) {
			if (a[i] > a[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				p[i] = j;
				if (ans < dp[i]) {
					last = i;
					ans = dp[i];
				}
			}
		}
	}

	vector<int> v;
	for (j=last;j>0;j=p[j])
		v.push_back(j);
	reverse(v.begin(), v.end());

	cout << ans << endl;
	for (int &x : v)
		cout << a[x] << ' ';


	return 0;
}
