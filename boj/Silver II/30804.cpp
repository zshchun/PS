#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int c[10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, i, t = 0, ans = 0;
	queue<int> v;
	cin >> N;
	while (N--) {
		cin >> i;
		v.push(i);
		if (!c[i])
			t++;
		c[i]++;
		while (t > 2 && !v.empty()) {
			int x = v.front();
			v.pop();

			c[x]--;
			if (c[x] == 0)
				t--;
		}
		if (ans < (int)v.size())
			ans = v.size();
	}
	cout << ans << endl;
	return 0;
}
