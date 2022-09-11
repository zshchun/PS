#include <bits/stdc++.h>
using namespace std;
int main() {
	char b[101];
	char l[11];
	cin.getline(b, 101);
	int i, len, end;
	len = strlen(b);
	for(i=0;i<len;i+=10) {
		end = i+10 <= len ? 10 : len - i;
		strncpy(l, b+i, end);
		l[end] = '\0';
		cout << l << "\n";
	}

	return 0;
}
