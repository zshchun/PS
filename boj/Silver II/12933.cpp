#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int ans;
int hist[6];
char quack[] = "quack";

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k;
	string s;
	cin >> s;
	for (i=0;i<s.size();i++) {
		if (s[i] == 'q') {
			bool end = false;
			int next = 1;
			hist[0] = i;
			for (j=i+1;j<s.size();j++) {
				if (s[j] == quack[next]) {
					hist[next] = j;
					next++;
					if (next > 4) {
						if (!end) ans++;
						end = true;
						next = 0;
						for (k=0;k<5;k++)
							s[hist[k]] = '\0';
					}
				}
			}
		}
	}

	for (char &c : s)
		if (c) ans = 0;

	if (ans)
		cout << ans << endl;
	else
		cout << "-1\n";
	return 0;
}
