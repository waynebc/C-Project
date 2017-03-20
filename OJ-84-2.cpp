/*
USER_ID: test#jianyun
PROBLEM: 84
SUBMISSION_TIME: 2017-03-20 18:57:02
*/
#include<iostream>
#include<cstdio>
using namespace std;
 
int main() {
 
    int N;
    long long a, one, two, three;
    long long mark1, mark2, mark3;
 
    while (cin >> N) {
         
        one = 0;
        two = 0;
        three = 0;
 
        for (int i = 0; i < N; i++) {
            scanf("%lld", &a);
            mark3 = two ^ three;
            mark2 = one ^ two;
            mark1 = ~two;
            three ^= a & mark3;
            two ^= a & mark2;
            one ^= a & mark1;
        }
        printf("%lld\n", one);
    }
    return 0;
}