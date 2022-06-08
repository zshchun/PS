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
	ll T, i, j, x, v, ans;
	cin >> T;
	while(T--) {
		cin >> n;
		v = n / 3;
		ll v1 = v+1;
		ll v2 = v;
		ll v3 = v-1;
		if (n % 3 == 2) {
			v1++;
			v2++;
		} else if (n % 3 == 1) {
			v1++;
		}
		cout << v2 << " " << v1 << " " << v3 << endl;
	}
	return 0;
}
