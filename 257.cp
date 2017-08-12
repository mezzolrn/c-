#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;



int arr[101];

int main() {
    int t;
    cin >> t;
	
	stack<int> xx,yy;
    
    for(int i = 0; i < t; i++){
        int m;
        scanf("%d", &m);
		
		arr[0] = 0;
		arr[1] = 0;
		int a,b;
        for(int i = 0; i < m - 1; i++){
            scanf("%d", &a);
			scanf("%d", &b);
            arr[b] = a;
        }
		
		int n;
        scanf("%d", &n);
		
        for(int i = 0; i < n; i++){
			
			while(!xx.empty()){
				xx.pop();
			}
			while(!yy.empty()){
				yy.pop();
			}
			scanf("%d", &a);
			scanf("%d", &b);
			while(a != 0){
				xx.push(a);
				a = arr[a];
			}
			while(b != 0){
				yy.push(b);
				b = arr[b];
			}
			int ans = 0;
			while(!xx.empty() && !yy.empty() && xx.top() == yy.top()){
				ans = xx.top();
				xx.pop();
				yy.pop();
			}
			printf("%d\n",ans);
        }
		
    }
    return 0;
}
