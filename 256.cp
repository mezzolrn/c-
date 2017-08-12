#include <iostream>
using namespace std;


int main() {
	int t;
	cin >> t;
	
	for(int i = 0; i < t; i++){
		int a;
		cin >> a;
		if(a==1){
			cin >> a;
			cout << 1 << endl;
		}
		
		else{
			int max = 2;
			int tmpa;
			cin >> tmpa;
			int tmpb;
			cin >> tmpb;
			
			int tmpsub,tmpmax;
			tmpsub = tmpb - tmpa;
			tmpmax = 2;
			int tmpc;
			for(int j = 2; j < a; j++){
				
				cin >> tmpc;
				if(tmpc - tmpb == tmpsub){
					tmpmax++;
				}else{
					tmpsub = tmpc - tmpb;
					if(tmpmax > max){
						max = tmpmax;
					}
					tmpmax = 2;
				}
				tmpb = tmpc;
			}
			if(tmpmax > max){
				max = tmpmax;
			}
			cout << max << endl;
		}
	}
	
	return 0;
}
