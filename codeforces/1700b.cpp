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
		cin >> n;
		string s;
		vector<ll> a(n+1);
		cin >> s;
		x = s[0] - '0';
		ll y;
		if (x >= 8)
			y = 1;
		else
			y = x + 2;
		ll carry = 0;
		for (i=n-1;i>=0;i--) {
			x = y - carry - (s[i]-'0');
			if (x < 0) {
				carry = 1;
				x += 10;
			} else carry = 0;
			a[i] = x;
		}
//		a[0] = 1-carry;
//		for (i=0;a[i] == 0 && i<n;i++) { ; }
		for (i=0;i<n;i++) {
			cout << a[i];
		}
		cout << endl;
	}
	return 0;
}
