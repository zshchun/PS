#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
bool visited[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, x, y, a, b;
	cin >> x >> y >> a >> b;
	for (i=a;i<=10000;i+=x)
		visited[i] = i;
	for (i=b;i<=10000;i+=y) {
		if (visited[i]) {
			cout << i << endl;
			return 0;
		}
	}
	cout << "-1\n";
	return 0;
}
