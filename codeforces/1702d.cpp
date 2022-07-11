#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
#define MOD 1000000007
ll n, m;

ll a[26];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, z, l, r, ans;
	cin >> T;
	while(T--) {
		string s;
		cin >> s;
		cin >> n;
		memset(a, 0, sizeof(a));
		ll sm = 0;
		for (i=0;i<s.size();i++) {
			z = s[i]-'a';
			a[z]++;
			sm += z+1;
		}
		for (i=25;sm>n && i>=0;i--) {
			z = i+1;
			if (sm - a[i]*z < n) {
				k = (sm - n) / z;
				sm -= k * z;
				a[i] -= k;
				break;
			} else {
				sm -= a[i]*z;
				a[i] = 0;
			}
		}
		if (sm > n) {
			l = 0;
			for (i=25;i>=0;i--) {
				z = i+1;
				if (a[i] && sm - z <= n) {
					l = i+1;
				}
			}
			if (l > 0) {
				sm -= l;
				a[l-1]--;
			}
		}
		for (i=0;i<s.size();i++) {
			z = s[i]-'a';
			if (a[z] > 0) {
				cout << s[i];
				a[z]--;
			}
		}
		cout << endl;
	}
	return 0;
}
