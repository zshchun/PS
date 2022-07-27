#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
#define MOD 1000000007
ll n, m, ans;
ll a[100001];
ll c[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, z, l, r;
	cin >> T;
	while(T--) {
		cin >> n;
		vector<ll> a(n,-1);
		vector<ll> c(n);
		for (i=0;i<n;i++) {
			cin >> j; j--;
			if (!c[j]) {
				a[j] = i;
				c[j]++;
			} else if ((i-a[j])%2 == 1) {
				a[j] = i;
				c[j]++;
			}
		}
		for (i=0;i<n;i++) {
			cout << c[i] <<' ' ;
		}
		cout << endl;
	}
	return 0;
}
