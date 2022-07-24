#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
#define MOD 1000000007
ll n, m, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, z, l, r;
	cin >> T;
	while(T--) {
		cin >> n;
		ans = 0;
		vector<ll> a(101);
		bool dup = false;
		for (i=0;i<n;i++) {
			cin >> z;
			if (a[z]) dup = true;
			a[z]++;
		}
		if (a[0] > 0)
			cout << n-a[0] << endl;
		else if (dup)
			cout << n << endl;
		else
			cout << n+1 << endl;
	}
	return 0;
}
