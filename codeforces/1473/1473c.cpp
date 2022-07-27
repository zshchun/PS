#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
ll n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, x, ans;
	cin >> T;
	while(T--) {
		cin >> n >> k;
		ans = 0;
		ll inv = n - k+1;
		for (i=1;i<=k-inv;i++)
			cout << i << ' ';
		for (i=k;i>k-inv;i--)
			cout << i << ' ';
		cout << endl;
	}
	return 0;
}
