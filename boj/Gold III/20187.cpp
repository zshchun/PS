#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int k;
vector<char> a;
int lr[4] = {1, 0, 3, 2};
int ud[4] = {2, 3, 0, 1};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, h;
	cin >> k;
	a.resize(k*2);
	for (i=0;i<k*2;i++)
		cin >> a[i];;
	cin >> h;

	vector<vector<int>> ans(1, vector<int>(1, h));
	for (auto it=a.rbegin();it != a.rend();it++) {
		char c = *it;
		int h = ans.size();
		int w = ans[0].size();
		vector<vector<int>> rev(h, vector<int>(w));
		if (c == 'L' || c == 'R') {
			for (i=0;i<h;i++)
				for (j=0;j<w;j++)
					rev[i][j] = lr[ans[i][w-j-1]];

			for (i=0;i<h;i++)
				if (c == 'L')
					ans[i].insert(ans[i].end(), rev[i].begin(), rev[i].end());
				else
					ans[i].insert(ans[i].begin(), rev[i].begin(), rev[i].end());
		} else {
			for (i=0;i<h;i++)
				for (j=0;j<w;j++)
					rev[i][j] = ud[ans[h-i-1][j]];
			if (c == 'U')
				ans.insert(ans.end(), rev.begin(), rev.end());
			else
				ans.insert(ans.begin(), rev.begin(), rev.end());
		}
	}
	for (auto &row : ans) {
		for (int &col : row) {
			cout << col << ' ';
		}
		cout << endl;
	}

	return 0;
}
