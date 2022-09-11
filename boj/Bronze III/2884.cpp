#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int h, m, s;
	cin >> h >> m;
	s = h * 60 + m;
	if (s < 45) {
		s = (h+24) * 60 + m;
	}
	s -= 45;
	cout << (s / 60) << " " << (s % 60) << "\n";
	return 0;
}
