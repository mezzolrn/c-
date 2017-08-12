#include <iostream>
using namespace std;


int main() {
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++){
        
        int n,m,k;
        cin >> n >> m >> k;
        
        int arr[n][n];
        
        for(int j = 0; j < n; j++){
            for(int l = 0; l < n; l++){
                if(j == l){
                    arr[j][l] = 0;
                }
                else arr[j][l] = 999999;
            }
        }
        
        
        for(int j = 0; j < m; j++){
            int a,b,c;
            cin >> a >>b >>c;
            arr[a-1][b-1] = c;
            arr[b-1][a-1] = c;
            
        }
        
        
        
        int goal[2][k];
        
        for(int i = 0; i < k; i++){
            cin >> goal[0][i];
            goal[0][i]--;
            goal[1][i] = 0;
        }
        
        int lastmin = 0;
        int min = 999999;
        int tmp = 0;
        int sum = 0;
        int tmpk = k;
        int col = 0;
        
        while(tmpk > 0){
            for(int p = 0; p < n; p++){
                //找到最小值
                for(int j = 0; j < n; j++){
                    if(arr[col][j] >= lastmin && arr[col][j] < min &&arr[col][j] != 0) {
                        min = arr[col][j];
                        tmp = j;
                    }
                }
                //通过最小值返现新路径
                for(int j = 0; j < n; j++){
                    if(arr[col][j] > arr[col][tmp] + arr[tmp][j]){
                        arr[col][j] = arr[col][tmp] + arr[tmp][j];
                    }
                }
                
                lastmin = min;
                min = 999999;
            }
            
            
            int tmpl = 0;
            for(int l = 0; l < k; l++){
                //col到目标点中最小的
                if(arr[col][goal[0][l]] > 0 && arr[col][goal[0][l]] < min && goal[1][l] == 0){
                    min = arr[col][goal[0][l]];
                    tmp = goal[0][l];
                    tmpl = l;
                }
            }
            sum = sum + min;
            goal[1][tmpl] = 1;
            col = tmp;
            lastmin = 0;
            min = 999999;
            tmpk--;
        }
        
        
        
        cout << sum << endl;
        
    }
    
    return 0;
}
