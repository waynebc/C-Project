#include<iostream>
#include<cstdio>
#include<map>
#include<list>
using namespace std;

int main(){
	int T;  //the number of test cases
	int N;  //the number of waitresses
	int M;  //the number of years

	map<int,list<int> > bmap;  //the map of beautiful value and the list of waitresses has the same value
	int wnum;  //decide the labeled number
	int bvalue;  //beautiful value
	
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		scanf("%d",&M);
		wnum=1;  //编号初始为1
		while(N--){
		    scanf("%d",&bvalue);
		    bmap[bvalue].push_back(wnum++);
		}
		for(int b_dec=0;b_dec<M;b_dec++){
			scanf("%d",&bvalue);

			map<int,list<int> >::iterator bmin_itr=bmap.begin();  //the least beautiful waitresses pair
			
			printf("%d %d\n",(bmin_itr->second).back(),(bmin_itr->first)-b_dec);
			(bmin_itr->second).pop_back();  //remove
			if((bmin_itr->second).empty()){  //remove b-w pair if empty
				bmap.erase(bmin_itr);
			}

		    bmap[bvalue+b_dec].push_back(wnum++);

		}

		bmap.clear();
	}

	return 0;
}
