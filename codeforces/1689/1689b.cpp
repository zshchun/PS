#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
#define MOD 1000000007
ll n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, x, l, r, ans;
	cin >> T;
	while(T--) {
		cin >> n;
		vector<ll> a(n);
		vector<ll> b(n);
		for (i=0;i<n;i++) {
			cin >> a[i];
			b[i] = a[i];
		}
		if (n == 1) {
			cout << "-1\n";
			continue;
		}
		sort(b.begin(), b.end());
		for (i=0;i<n-1;i++) {
			if (a[i] == b[i])
				swap(b[i], b[i+1]);
		}
		if (a[n-1] == b[n-1])
			swap(b[n-1], b[n-2]);
		for (i=0;i<n;i++)
			cout << b[i] << ' ';
		cout << endl;
	}
	return 0;
}
