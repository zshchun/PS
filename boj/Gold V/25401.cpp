#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
#define endl "\n"
#define INF 123456789
int N, ans = INF;
vector<int> v;
set<pi> st;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, a, b;
	cin >> N;
	v.resize(N);
	for (i=0;i<N;i++)
		cin >> v[i];

	for (i=0;i<N-1;i++) {
		for (j=i+1;j<N;j++) {
			a = (v[j] - v[i]) / (j - i);
			b = v[j] - a * j;
			if (((v[j] - v[i]) % (j - i)) == 0)
				st.insert(pi(a, b));
		}
	}
	for (auto &[a, b]: st) {
		int cnt = 0;
		for (i=0;i<N;i++) {
			if (v[i] != a * i + b)
				cnt++;
		}
		ans = min(ans, cnt);
	}
	cout << ans << endl;

	return 0;
}
