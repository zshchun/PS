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
	int a, b;
	cin >> a >> b;
	while (1) {
		b += a;
		if (b >= 5) {
			cout << "yt\n";
			break;
		}
		a += b;
		if (a >= 5) {
			cout << "yj\n";
			break;
		}
	}
	return 0;
}
