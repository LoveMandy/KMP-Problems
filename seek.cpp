#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> function(string s) {
		int k = -1, j = 0, len = s.length();
		vector<int> next(len + 1, -1);
		while (j < s.length()) {
			while (k != -1 && s[k] != s[j]) k = next[k];
			k++;
			j++;
			next[j] = k;
		}
		vector<int> result;
		while (len > 0) {
			result.push_back(len);
			len = next[len];
		}
		return result;
	}
};

int main() {
	Solution* s = new Solution();
	string str;
	while (cin >> str) {
		vector<int> result = s->function(str);
		for (int j = result.size() - 1; j >= 0; j--) {
			cout << result[j] << ' ';
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
