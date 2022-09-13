#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __uint128_t u128;
typedef pair<ll,ll> pa;
#define endl "\n"
#define MOD 1000000007
#define INF (1LL<<60)
ll n, m, ans;

string al = "0abcdefghijklmnopqrstuvwxyz";

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll TC, i, j, k;
	cin >> TC;
	while(TC--) {
		cin >> n;
		string s;
		cin >> s;
		s += "   ";
		for (i=0;i<n;i++) {
			if (s[i+3] != '0' && s[i+2] == '0') {
				j = stoi(s.substr(i, 2));
				i += 2;
				cout << al[j];
			} else {
				j = stoi(s.substr(i, 1));
				cout << al[j];
			}
		}
		cout << endl;
	}
	return 0;
}
