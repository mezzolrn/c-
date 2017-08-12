#include <iostream>
using namespace std;


struct arr{
    int v;
    int flag;
};


int main(){
    int time;
    cin >> time;
    
    for(int a = 0; a < time; a++){
        int n;
        cin >> n;
        
        arr arry[n];
        for(int i = 0; i < n; i++){
            cin >> arry[i].v;
            arry[i].flag = 0;
        }
        
        int t;
        cin >> t;
        
        int tmp[t];
        
        int min;
        int mintmp = -1;
        for(int i = 0; i < t; i++){
            cin >> tmp[i];
            min = 0;
            for(int j = 0; j < n; j++){
                if(arry[j].v >= tmp[i] && arry[j].flag == 0){
                    if(min == 0) {
                        min = arry[j].v;
                        mintmp = j;
                    }
                    else if(arry[j].v < min){
                        min = arry[j].v;
                        mintmp = j;
                    }
                }
            }
            
            tmp[i] = min;
            if(mintmp >= 0) arry[mintmp].flag = 1;
        }
        
        for(int i = 0; i < t-1; i++){
            if(tmp[i] == 0){
                cout << "NULL" << " ";
            }
            else{
                
                cout << tmp[i] << " ";
            }
        }
        if(tmp[t - 1] == 0){
            cout << "NULL" << endl;
        }
        else{
            
            cout << tmp[t-1] << endl;
        }
        
    
    }
    return 0;
    
}
