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
		string s1, s2, t;
		cin >> s1 >> s2;
		j = s1.size()-1;
		ll p = 0;
		for (i=s2.size()-1;i>=0;i--) {
			while (j >=0 && s1[j] != s2[i]) {
				j--;
				p = i;
			}
			if (j >=0 && s1[j] == s2[i]) {
				ans++;
				j--;
			}
		}
		if (ans == s2.size() && p < 1)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
