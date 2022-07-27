#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll t, i, j, k, v, n, d, l, c;
	cin>>t;
	dp[0] = 1;
	dp[1] = 1;
	for (i=2;i<=100000;i++) {
		if (dp[i]) continue;
		for (j=i+i;j<=100000;j+=i) {
			dp[j] = 1;
		}
	}
	while(t--) {
		cin>>d;
		for(i=1+d;dp[i];i++) {;}
		for(j=i+d;dp[j];j++) {;}
		v = i * j;
		cout << v << "\n";

	}
	return 0;
}
