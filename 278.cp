#include <iostream>
using namespace std;


struct arry{
    int v;
    int d;

};


arry arr[105][105];
int bianli(int i,int j,int n,int m,int d){
    int sub;
    
    for(int k = i - 1; k < i + 2; k++){
        for(int l = j - 1; l < j + 2; l++){
            if(k < 0 || l < 0 || k >= n || l >= m || (i == k && j == l) || arr[k][l].d != -1){
                continue;
            }
            sub = arr[k][l].v - arr[i][j].v;
            sub = sub > 0 ? sub : -sub;
            if(sub <= d){
                arr[k][l].d = arr[i][j].d;
                bianli(k,l,n,m,d);
            }
        }
    }
    return 0;
}




int main(){
    int tim;
    cin >> tim;
    for(int p = 0; p < tim; p++){
        int n,m,d;
        cin >> n >> m >> d;
        
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> arr[i][j].v;
                arr[i][j].d = -1;
                
            }
        }
        
        int tmp = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr[i][j].d == -1){
                    arr[i][j].d = tmp;
                    tmp++;
                    bianli(i,j,n,m,d);
                }
            }
        }
        cout << tmp << endl;
    }
    return 0;
}

