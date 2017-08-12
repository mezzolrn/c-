#include <iostream>

#include <cstdio>
#include <string.h>
#include <string>
using namespace std;

char abc[100000];
char str[10];
int bb[100000][2];
int cnt[26];
int pre[26];
#define MAX 100003;

int main() {
	int t;
	scanf("%d", &t);
	
	int len;
	int ans;
	
	for(int j = 0; j < 100000; j++){
		bb[j][0]=100003;
		bb[j][1]=100003;
	}
	
	while(t--){
		for(int j = 0; j < 26; j++) {
			cnt[j] = 0;
		}
		
		scanf("%s", abc);
		len = int(strlen(abc));
		int tmpi;
		for(int i = 0; i < len; i++){
			tmpi = abc[i] - 'a';
			cnt[tmpi]++;
			if(cnt[tmpi] > 1){
				bb[i][0] = i - pre[tmpi];
				bb[pre[tmpi]][1] = bb[i][0];
			}
			pre[tmpi] = i;
		}
		
		int n;
		scanf("%d", &n);
		while(n--){
			scanf("%s", str);
			
			
			
			if(str[0] == 'I'){
				
				scanf("%s", str);
				
				tmpi = str[0] - 'a';
				cnt[tmpi]++;
				if(cnt[tmpi] > 1){
					bb[len][0] = len - pre[tmpi];
					bb[pre[tmpi]][1] = bb[len][0];
				}
				pre[tmpi] = len;
				len++;
				
			}else{
				int tmp;
				scanf("%d", &tmp);
				if(bb[tmp][0] < bb[tmp][1]) ans = bb[tmp][0];
				else ans = bb[tmp][1];
				if(ans > 100000){
					printf("-1\n");
				}else{
					printf("%d\n", ans);
				}
				
			}
		}
		
		for(int i = 0; i < len; i++) {
			bb[i][0] = 100003;
			bb[i][1] = 100003;
		}
	
	}
	
	return 0;
}
