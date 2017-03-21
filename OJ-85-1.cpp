/*
USER_ID: test#jianyun
PROBLEM: 85
SUBMISSION_TIME: 2017-03-21 15:14:33
*/

/*
85. Three Points On A Line

Given points on a 2D plane, judge whether there're three points that locate on the same line.

*/
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
 
struct Point {
    float x;
    float y;
};
 
int main() {
 
    int T, N;
    bool res = false;
    Point pts[100];
    scanf("%d", &T);
    for (int m = 0; m < T; m++) {
                res=false;
        scanf("%d", &N);
        for (int n = 0; n < N; n++) {
            scanf("%f", &pts[n].x);
            scanf("%f", &pts[n].y);
        }
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                for (int z = j + 1; z < N; z++) {
                    float y1 = pts[z].y - pts[i].y;
                    float y2 = pts[j].y - pts[i].y;
                    float x1 = pts[z].x - pts[i].x;
                    float x2 = pts[j].x - pts[i].x;
                    if (abs(y1*x2 - y2*x1) <= 0.000001) {
                        res = true;
                        break;
                    }
                }
                if (res)break;
            }
            if (res)break;
        }
        if (res)
            printf("Yes\n");
        else
            printf("No\n");
    }
 
    return 0;
}