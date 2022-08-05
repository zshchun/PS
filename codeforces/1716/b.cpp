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
		vector<ll> a(n+1);
		cout << n << endl;
		for (i=1;i<=n;i++) {
			a[i] = i;
			cout << a[i] << " ";
		}
		cout << endl;
		for (j=1;j<n;j++) {
			if (j == 1)
				swap(a[j], a[n]);
			else
				swap(a[j], a[j-1]);
			for (i=1;i<=n;i++)
				cout << a[i] << " ";
			cout << endl;
		}
	}
	return 0;
}
