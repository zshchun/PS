#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __uint128_t u128;
typedef pair<ll,ll> pa;
#define endl "\n"
#define MOD 1000000007
#define INF (1LL<<60)
ll n, m;

int main() {
	ios_base::sync_with_stdio(false);

	cin.tie(0);
	ll T, i, j, alice, bob;
	cin >> T;
	while(T--) {
		string s;
		cin >> s;
		alice = 0;
		for (i=0;i<s.size();i++)
			alice += (s[i]-'a')+1;
		if (s.size() % 2) {
			bob = min(s[0], s[s.size()-1])-'a'+1;
			alice = alice - bob;
		} else
			bob = 0;
		if (alice > bob)
			cout << "Alice " << alice-bob << endl;
		else
			cout << "Bob " << bob-alice << endl;
	}
	return 0;
}
