#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int m, h;
	cin >> m >> h;
	if (h % m == 0)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}
