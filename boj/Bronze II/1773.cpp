#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
#define endl "\n"
#define INF 123456789
ll N, C, ans;
bool s[2000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, v;
	cin >> N >> C;
	for (i=0;i<N;i++) {
		cin >> v;
		if (v == 1) {
			cout << C << endl;
			return 0;
		}
		for (j=v;j<=C;j+=v)
			s[j] = 1;
	}
	for (i=1;i<=C;i++)
		if (s[i]) ans++;
	cout << ans << endl;
	return 0;
}
