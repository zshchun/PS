#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int m[21][21][21];
int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20)
		return w(20, 20, 20);
	if (m[a][b][c])
		return m[a][b][c];
	if (a < b && b < c)
	    m[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
	else
	    m[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
	return m[a][b][c];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c;
	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
	}

	return 0;
}
