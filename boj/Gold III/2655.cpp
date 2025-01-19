#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int dp[101];
int p[101];
int cnt[101];
int mx, last;
class Brick {
public:
	int width;
	int height;
	int weight;
	int index;
};

void track(vector<Brick> &b, int x) {
	if (x) {
		track(b, p[x]);
		cout << b[x].index << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i, j, x, y, w;
	cin >> n;
	vector<Brick> b(n+1);
	for (i=1;i<=n;i++) {
		cin >> b[i].width >> b[i].height >> b[i].weight;
		b[i].index = i;
	}
	sort(b.begin()+1, b.end(), [&](Brick &lhs, Brick &rhs) {
		return lhs.weight < rhs.weight;
	});
	for (i=1;i<=n;i++) {
		for (j=0;j<i;j++) {
			if (b[i].width > b[j].width && dp[j] + b[i].height > dp[i]) {
				dp[i] = dp[j] + b[i].height;
				p[i] = j;
				cnt[i] = cnt[j] + 1;
			}
		}
		if (dp[i] > mx) {
			mx = dp[i];
			last = i;
		}
	}
	cout << cnt[last] << endl;
	track(b, last);
//	cout << ans.size() << endl;
//	for (ll &x : ans) {
//		cout << x << endl;
//	}
	return 0;
}
