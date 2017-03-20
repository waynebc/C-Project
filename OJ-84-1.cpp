/*
USER_ID: test#jianyun
PROBLEM: 84
SUBMISSION_TIME: 2017-03-20 18:10:13
*/
#include<iostream>
#include<cstdio>
using namespace std;
  
int main() {
  
    int N = 0;
    while (cin>>N) {
        long long a = 0;
        long long one = 0, two = 0, three = 0;
        long long mark1 = 0, mark2 = 0, mark3 = 0;
  
        for (int i = 0; i < N; i++) {
            scanf("%lld",&a);
            mark1 = three & a;
            mark3 = two & a;
            mark2 = one & a;
            three ^= mark3 ^ mark1;
            two ^= mark2 ^ mark3;
            one ^= a ^ mark3;
        }
        printf("%lld\n", one);
    }
    return 0;
}