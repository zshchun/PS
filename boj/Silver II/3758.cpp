#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int,int,int,int> tup;
#define endl "\n"
#define INF 123456789
int a[101][101];
int c[101];
int o[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, n, k, t, m, i, x, y, z;
	cin >> T;
	while (T--) {
		cin >> n >> k >> t >> m;
		memset(a, 0, sizeof(a));
		memset(c, 0, sizeof(c));
		vector<tup> b;
		for (i=0;i<m;i++) {
			cin >> x >> y >> z;
			if (a[x][y] < z)
				a[x][y] = z;
			o[x] = i + 1;
			c[x]++;
		}

		for (i=1;i<=n;i++) {
			b.push_back(tup(i, accumulate(&a[i][1], &a[i][101], 0), o[i], c[i]));
		}

		sort(b.begin(), b.end(), [](tup lhs, tup rhs) {
			int score1 = get<1>(lhs); int time1 = get<2>(lhs); int count1 = get<3>(lhs);
			int score2 = get<1>(rhs); int time2 = get<2>(rhs); int count2 = get<3>(rhs);
			if (score1 == score2 && count1 == count2)
				return time1 < time2;
			else if (score1 == score2)
				return count1 < count2;
			else
				return score1 > score2;
		});

		for (i=0;i<n;i++) {
			if (get<0>(b[i]) == t) {
				cout << i + 1 << endl;
				break;
			}
		}
	}
	return 0;
}

