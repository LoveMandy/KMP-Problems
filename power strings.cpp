#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int function(string& str) {
		int len = str.length();
		vector<int> next(len + 1, -1);
		int k = -1, j = 0;
		while (j < len) {
			while (k != -1 && str[k] != str[j]) k = next[k];
			k++;
			j++;
			next[j] = k;
		}
		return len % (len - next.back()) == 0 ? len / (len - next.back()) : 1;
	}
};


int main() {
	Solution* s = new Solution();
	string str;
	cin >> str;
	while (str != ".") {
		cout << s->function(str) << endl;
		cin >> str;
	}
	return 0;
}