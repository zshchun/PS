#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int h1, h2, m1, m2, s1, s2, r1 = 0, r2 = 0, s;
	char c;
	cin >> h1 >> c >> m1 >> c >> s1;
	cin >> h2 >> c >> m2 >> c >> s2;
	r1 = s1 + m1 * 60 + h1 * 3600;
	r2 = s2 + m2 * 60 + h2 * 3600;
	if (r2 < r1) r2 += 86400;
	s = r2 - r1;
	cout << setw(2) << setfill('0') << (s / 3600) << ":";
	cout << setw(2) << setfill('0') << (s % 3600 / 60) << ":";
	cout << setw(2) << setfill('0') << (s % 60) << "\n";

	return 0;
}
