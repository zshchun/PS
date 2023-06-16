#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
int N;
int a[2001];
int dp[2001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> N;
	for (i=0;i<N;i++)
		cin >> a[i];
	fill(dp, dp+2001, 1);

	for (i=1;i<N;i++) {
		for (j=0;j<i;j++) {
			if (a[i] < a[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	cout << N-(*max_element(dp, dp+N)) << endl;;

	return 0;
}
