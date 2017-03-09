#include<iostream>
#include<list>
using namespace std;

bool testBracket(char* str, int len) {
	list<char> tst;
	for (int i = 0; i < len; i++) {
		if (str[i] == '\0')
			break;
		switch (str[i]) {
		case '(':
			tst.push_back(str[i]); break;
		case '[':
			tst.push_back(str[i]); break;
		case '{':
			tst.push_back(str[i]); break;
		case ')':
			if (tst.back() == '(')
				tst.pop_back();
			break;
		case ']':
			if (tst.back() == '[')
				tst.pop_back();
			break;
		case '}':
			if (tst.back() == '{')
				tst.pop_back();
			break;
		default:break;
		}
	}

	if (tst.size() == 0)return true;
	else return false;

}
/*
int main() {

	char str[100] = "({}([]))";
	cout << testBracket(str, 100) << endl;
	system("pause");
}*/