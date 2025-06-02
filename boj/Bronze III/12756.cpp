#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int ap1, ap2, hp1, hp2;
	cin >> ap1 >> hp1;
	cin >> ap2 >> hp2;
	while (hp1 > 0 && hp2 > 0) {
		hp1 -= ap2;
		hp2 -= ap1;
	}
	if (hp1 <= 0 && hp2 <= 0)
		cout << "DRAW\n";
	else if (hp1 <= 0)
		cout << "PLAYER B\n";
	else
		cout << "PLAYER A\n";
	return 0;
}
