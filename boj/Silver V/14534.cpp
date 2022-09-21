#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, N;
	cin >> N;
	string s;

	for (i=1;i<=N;i++) {
		cout << "Case # " << i << ":" << endl;
		cin >> s;
		vector<ll> v;
		for (j=0;j<(ll)s.size();j++) {
			v.push_back(j);
		}
		do {
			for (j=0;j<(ll)s.size();j++)
				cout << s[v[j]];
			cout << endl;
		} while(next_permutation(v.begin(), v.end()));
	}
	return 0;
}
