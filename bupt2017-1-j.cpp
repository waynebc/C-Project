/*
USER_ID: test#jianyun
PROBLEM: 1465
SUBMISSION_TIME: 2017-04-03 20:26:05
*/
#include<iostream>
#include<cstdio>
#include<map>
#include<list>
using namespace std;
 
typedef short int VTYPE;
 
//求某一点index为起点的所有最短路径平方和
long long dijkstra(int index, VTYPE** graph, int n) {
    map<VTYPE, list<int> > lenmap;  //以index为起点的 shortestLen-dsts map
    long long sum = 0;  //结果平方和

    for (int i = 0; i < n; i++) {
        if (i == index)continue;
        int len = graph[index][i];
        lenmap[len].push_back(i);
    }
 
	/*
	 * dijkstra算法，依次找到最短距离及相应顶点--newLen,newVert; 
	 * 并以此顶点为中转更新其他顶点距离lenmap[newLen+1].push_back;
	 */
    for (int i = 1; i < n; i++) {
        map<VTYPE, list<int> >::iterator imap = lenmap.begin();
        if (imap == lenmap.end()) {
            break;
        }

        int newVert = (imap->second).front();
        VTYPE newLen = (imap->first);
 
        imap++;

		//重要减枝操作1,最大距离的点，直接全部加入
        if (imap == lenmap.end()) {
            sum += ((long long)newLen)*newLen*((lenmap.begin()->second).size());
            break;
        }
 
        while (imap != lenmap.end()) {

			//重要减枝操作2,len==(newLen+1),无需更新
            if (imap->first == (newLen + 1)) {
                imap++; continue;
            }

            list<int>::iterator ilist = (imap->second).begin();
            while (ilist != (imap->second).end()) {
				//以newVert为中转更新index到*list的距离
                if (graph[newVert][*ilist]==1) {
                    lenmap[newLen+1].push_back(*ilist);
                    (imap->second).erase(ilist++);
                }
                else {
                    ilist++;
                }
            }
            if ((imap->second).empty()) {
                lenmap.erase(imap++);
            }
            else {
                imap++;
            }
        }
        sum += newLen*newLen;

		//删除已经找到的最短距离顶点。
        imap = lenmap.begin();
        (imap->second).pop_front();
        if ((imap->second).empty()) {
            lenmap.erase(imap);
        }
    }
    return sum;
}
 
 
int main() {
 
    int n;
    scanf("%d", &n);
    VTYPE ** graph = new VTYPE *[n];  //有向图距离数组
    for (int i = 0; i < n; i++) {
        graph[i] = new VTYPE[n];
    }

	//根据输入初始化graph
    char * graChar = new char[n + 1];
    for (int i = 0; i < n; i++) {
        scanf("%s", graChar);
        for (int j = 0; j < n; j++) {
            char c = graChar[j] - '0';
            if (c || i == j) {
                graph[i][j] = c;
            }
            else {
                graph[i][j] = n;
            }
        }
    }

	//求最短距离平方和
    long long sum = 0;
    for (int i = 0; i < n; i++) {

		//重要
        sum += dijkstra(i, graph, n);
    }
    printf("%lld", sum);
    return 0;
}
