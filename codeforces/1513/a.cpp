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
		if ((n-1)/2 < k) {
			cout << "-1\n";
			continue;
		}
		x = n-k;
		for (i=1;i<=n-k;i++) {
			cout << i << ' ';
			if (x+i <= n)
				cout << x+i << ' ';
		}
		cout << endl;
	}
	return 0;
}
