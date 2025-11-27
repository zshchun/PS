#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	double prev = -100;
	double temp;
	while (cin >> temp) {
		if (temp == 999) break;
		if (prev >= -10)
			cout << fixed << setprecision(2) << temp - prev << endl;
		prev = temp;
	}
	return 0;
}
