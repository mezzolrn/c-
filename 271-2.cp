#include <iostream>
#include<cstdio>
using namespace std;


int main(){
    int n;
    cin >> n;
    
    for(int m = 0; m < n; m++){
        int height,width;
        cin >> height >> width;
        
        char array[height][width];
        
        
        for(int i = 0; i < height; i++){
            scanf("%s",array[i]);
        }

        
        int angle;
        cin >> angle;
        
        if(angle == 90){
            for(int j = 0; j < width; j++){
                
                for(int i = height - 1; i >= 0; i--){
                    printf("%c",array[i][j]);
                }
                printf("\n");
            }
        }
        
        else if(angle == 180){
            for(int i = height - 1; i >= 0; i--){
                
                for(int j = width - 1; j >= 0; j--){
                    printf("%c",array[i][j]);
                }
                printf("\n");
            }
        }
        
        else if(angle == 270){
            for(int j = width - 1; j >= 0; j--){
                
                for(int i = 0; i < height; i++){
                    printf("%c",array[i][j]);
                }
                printf("\n");
            }
        }
        
        else if(angle == 0){
            for(int i = 0; i < height; i++){
                
                for(int j = 0; j < width; j++){
                    printf("%c",array[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
