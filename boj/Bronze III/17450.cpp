#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

float s[3], n[3], u[3];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c;
	cin >> s[0] >> s[1];
	cin >> n[0] >> n[1];
	cin >> u[0] >> u[1];
	s[0] *= 10;
	n[0] *= 10;
	u[0] *= 10;
	s[1] *= 10;
	n[1] *= 10;
	u[1] *= 10;
	if (s[0] >= 5000) s[0] -= 500;
	if (n[0] >= 5000) n[0] -= 500;
	if (u[0] >= 5000) u[0] -= 500;
	s[2] = s[1] / s[0];
	n[2] = n[1] / n[0];
	u[2] = u[1] / u[0];
	if (s[2] > n[2] && s[2] > u[2])
		cout << "S\n";
	else if (n[2] > s[2] && n[2] > u[2])
		cout << "N\n";
	else
		cout << "U\n";
	return 0;
}
