#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
#define endl "\n"
#define INF 123456789
ll N, C;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, v;
	cin >> N >> C;
	set<ll> s;
	for (i=0;i<N;i++) {
		cin >> v;
		if (v == 1) {
			cout << C << endl;
			return 0;
		}
		for (j=1;j*v<=C;j++)
			s.insert(j*v);
	}
	cout << s.size() << endl;
	return 0;
}
