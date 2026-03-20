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
	int a, b, c, d;
	while (cin >> a >> b >> c >> d) {
		if (!a && !b && !c && !d)
			break;
		int cnt = 0;
		int e, f, g, h;
		while (a != b || b != c || c != d || d != a) {
			e = abs(a-b);
			f = abs(b-c);
			g = abs(c-d);
			h = abs(d-a);
			a = e; b = f; c = g; d = h;
			cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}
