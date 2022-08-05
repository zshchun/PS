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
	ll T, i, j, sum, maxb, minb, x, v;
	cin >> T;
	while(T--) {
		cin >> n >> x;
		sum = 0;
		maxb = 0;
		for (i=0;i<n;i++) {
			cin >> v;
			sum += v;
			maxb += (v+x-1)/x;
		}
		minb = (sum+x-1) / x;
		cout << minb << " " << maxb << endl;
	}
	return 0;
}
