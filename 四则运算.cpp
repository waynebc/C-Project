#include<iostream>
using namespace std;
double expr(char* s, int& pos); //expr   = term   [+- term]...
double term(char* s, int& pos); //term   = factor [*/ factor]...
double factor(char* s, int& pos); //factor = number | (expr)
double number(char* s, int& pos);
double expr(char* s, int& pos) {
	double v = term(s, pos);
	while (s[pos] == '+' || s[pos] == '-') {
		if (s[pos++] == '+')
			v += term(s, pos);
		else
			v -= term(s, pos);
	}
	return v;
}

double term(char* s, int& pos) {
	double v = factor(s, pos);
	while (s[pos] == '*' || s[pos] == '/') {
		if (s[pos++] == '*')
			v *= factor(s, pos);
		else
			v /= factor(s, pos);
	}
	return v;
}

double factor(char* s, int& pos) {
	if (s[pos] == '(') {
		pos++;
		double v = expr(s, pos);
		pos++;
		return v;
	}
	else {
		return number(s, pos);
	}
}

double number(char* s, int& pos) {
	double n = 0;
	while (s[pos] >= '0' && s[pos] <= '9')
		n = n * 10 + s[pos++] - '0';
	if (s[pos] == '.')
		pos++;
	while (s[pos] >= '0' && s[pos] <= '9') {
		n = n + (s[pos++] - '0')*0.1;
	}
	return n;
}
double calc(char* exp, int length) {
	int pos = 0;
	return expr(exp, pos);
}

int main() {
	//char exp[100] = "10+8*2";
	char exp[100] = "(10.5*((1+4/2)-5+(9+1)))/2.0";
	cout << calc(exp, 100) << endl;
	system("pause");
	return 0;

}