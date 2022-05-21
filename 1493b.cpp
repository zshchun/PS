#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int rev[101];
int H, M;
bool isvalid(int h, int m) {
	int rm = rev[h];
	int rh = rev[m];
	if (rh != -1 && rh < H && rm != -1 && rm < M)
		return true;
	else
		return false;

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t, i, j, k, v, h, m, r;
	cin>>t;
	for (i=1;i<100;i++) {
		k = i;
		r = 0;
		for (j=0;j<2;j++) {
			v = k % 10;
			if (v==3||v==4||v==6||v==7||v==9) {
				r = -1;
				break;
			}
			if (v == 2)
				r = r*10 + 5;
			else if (v == 5)
				r = r*10 + 2;
			else
				r = r*10 + v;
			k /= 10;
		}
		rev[i] = r;
	}
	while(t--) {
		cin>>H>>M;
		cin>>h;
		cin.ignore(1, ':');
		cin>>m;
		while(!isvalid(h, m)) {
			++m;
			if (m >= M) {
				m = 0;
				++h;
				if (h >= H) {
					h = 0;
				}
			}
		}
		cout << setfill('0') <<setw(2)<< h <<":"<<setfill('0') <<setw(2)<<m<<"\n";
	}
	return 0;
}
