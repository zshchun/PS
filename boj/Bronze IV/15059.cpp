#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int C, B, P, c, b, p, ans = 0;
	cin >> C >> B >> P >> c >> b >> p;
	ans += max(0, c-C);
	ans += max(0, b-B);
	ans += max(0, p-P);
	cout << ans << endl;
	return 0;
}
