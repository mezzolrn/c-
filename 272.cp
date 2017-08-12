#include <iostream>
using namespace std;


int main(){
    int n;
    cin >> n;
    
    
    
    for(int m = 0; m < n; m++){
        int e,l;
        cin >> e >> l;
        
        int array[e][e];
        for(int i = 0; i < e; i++){
            for(int j = 0; j < e; j++){
                if(i == j){
                    array[i][j] = 0;
                }
                else array[i][j] = e;
            }
        }
        
        int a,b;
        for(int i = 0; i < l; i++){
            cin >> a >> b;
            array[a-1][b-1] = 1;
            array[b-1][a-1] = 1;
        }
        
        for(int k = 0; k < e; k++){
            for(int i = 0; i < e; i++){
                for(int j = 0; j < e; j++){
                    if(array[i][j] > array[i][k] + array[k][j]){
                        array[i][j] = array[i][k] + array[k][j];
                    };
                }
            }
        }
        
        
        
        int min;
        int tmp = 0;
        for(int j = 0; j < e; j++){
            tmp = tmp + array[0][j];
        }
        min = tmp;
        tmp = 0;
        int knel = 1;
        
        for(int i = 1; i < e; i++){
            for(int j = 0; j < e; j++){
                tmp = tmp + array[i][j];
            }
            
            if ( tmp < min ){
                min = tmp;
                knel = i + 1;
            }
            tmp = 0;
        }
        
        cout << knel << endl;
    }
    return 0;
}
