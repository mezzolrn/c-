#include <iostream>
using namespace std;


int main(){
    int n;
    cin >> n;
    
    for(int m = 0; m < n; m++){
        int time;
        cin >> time;
        
        int matrix[time][time];
        int dp[time][time];
        
        for(int i = 0;i < time;i++){
            int temp;
            cin >> temp;
            for(int j = time - 1;j >= 0;j--){
                matrix[i][j] = temp % 10;
                temp = temp / 10;
            }
        }
        
        int maxVal = 0;
        for(int i = 0; i < time; i++){
            if(matrix[i][0] == 1){
                dp[i][0] = 1;
                maxVal = 1;
            }else dp[i][0] = 0;
        }
        for(int j = 0; j < time; j++){
            if(matrix[0][j] == 1){
                dp[0][j] = 1;
                maxVal = 1;
            }else dp[0][j] = 0;
        }
        for(int i = 1; i < time; i++){
            for(int j = 1; j < time; j++){
                if(matrix[i][j] == 1){
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                    maxVal = max(maxVal, dp[i][j]);
                }else dp[i][j] = 0;
            }
        }
        cout << maxVal << endl;
        
    }
    
    
    
    return 0;
    
}
