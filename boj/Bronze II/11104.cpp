#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, n;
	string s;
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> s;
		k = 0;
		for (auto it=s.begin();it!=s.end();it++) {
			k <<= 1;
			if (*it == '1') k |= 1;
		}
		cout << k << endl;
	}
	return 0;
}
