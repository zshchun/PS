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
		cin >> n >> m;
		ans = 0;
		string a, b;
		cin >> a >> b;
		if (a.substr(n-m+1) != b.substr(1) || a.find(b[0]) > n-m) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
	}
	return 0;
}
