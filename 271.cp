#include <iostream>
#include <string>
#include <sstream>
using namespace std;


int main(){
    int n;
    cin >> n;
    
    for(int m = 0; m < n; m++){
        int height,width;
        cin >> height >> width;
        
        char array[height][width];
        
        
        for(int i = 0; i < height; i++){
            string tmp;
            cin >> tmp;
            for(int j = width - 1; j >= 0; j--){
                array[i][j] = tmp[j];
            }
        }
        
        int angle;
        cin >> angle;
        
        if(angle == 90){
            for(int j = 0; j < width; j++){
                string tmp;
                stringstream ss;
                for(int i = height - 1; i >= 0; i--){
                    ss << array[i][j];
                }
                ss >> tmp;
                cout << tmp << endl;
            }
        }
        
        else if(angle == 180){
            for(int i = height - 1; i >= 0; i--){
                string tmp;
                stringstream ss;
                for(int j = width - 1; j >= 0; j--){
                    ss << array[i][j];
                }
                ss >> tmp;
                cout << tmp << endl;
            }
        }
        
        else if(angle == 270){
            for(int j = width - 1; j >= 0; j--){
                string tmp;
                stringstream ss;
                for(int i = 0; i < height; i++){
                    ss << array[i][j];
                }
                ss >> tmp;
                cout << tmp << endl;
            }
        }
        
        else if(angle == 0){
            for(int i = 0; i < height; i++){
                string tmp;
                stringstream ss;
                for(int j = 0; j < width; j++){
                    ss << array[i][j];
                }
                ss >> tmp;
                cout << tmp << endl;
            }
        }
    }
    return 0;
}
