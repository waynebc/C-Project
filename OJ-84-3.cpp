/*
USER_ID: test#jianyun
PROBLEM: 84
SUBMISSION_TIME: 2017-03-20 18:19:45
*/
#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int main() {
      
    int N = 0;
    long long a = 0;
    while (cin >> N) {
        map<long long, int> cntmap;
        for (int i = 0; i < N; i++) {
            scanf("%lld", &a);
            cntmap.count(a) ? cntmap[a]++ : cntmap[a] = 1;
            if (cntmap[a] == 3)
                cntmap.erase(a);
        }
        printf("%lld\n", (*cntmap.begin()).first);
    }
    return 0;
}