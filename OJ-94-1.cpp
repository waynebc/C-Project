
/*
USER_ID: test#jianyun
PROBLEM: 94
SUBMISSION_TIME: 2017-03-21 19:02:21
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include <algorithm>
using namespace std;
 
int main() {
     
    char act[7];
    int query;
 
    int T, M;  //T测试数据的组数，M总共操作的数量
    scanf("%d", &T);
    for (int m = 0; m < T; m++) {
 
        char str[100001];    //str初始串
        int str_len = 0;    //str长度
        scanf("%s", &str);
        str_len = strlen(str);
 
        vector<int> c_pos[26];    //记录str中各个字母的位置信息
        for (int i = 0; i < str_len; i++) {
            c_pos[str[i] - 97].push_back(i);
        }
 
        scanf("%d", &M);
        for (int n = 0; n < M; n++) {
            scanf("%s", &act);
            if (act[0] == 'I') {
                scanf("%s", &str[str_len]);
                c_pos[str[str_len] - 97].push_back(str_len);
                str_len++;
            }
            else {
                scanf("%d", &query);
 
                int pos = str[query] - 97;
                if (c_pos[pos].size() == 1) {
                    printf("-1\n"); continue;
                }
 
                int dist_r = -1, dist_l = -1;
                vector<int>::iterator itr = find(c_pos[pos].begin(), c_pos[pos].end(), query);
                if (itr > c_pos[pos].begin()) {
                    dist_r = *itr - *(itr-1);
                }
                if (itr < c_pos[pos].end() - 1) {
                    dist_l = *(itr + 1) - *itr;
                    if (dist_r<0 || dist_r>dist_l)
                        dist_r = dist_l;
                }          
                printf("%d\n", dist_r); continue;
            }
        }
 
    }
     
    return 0;
}
