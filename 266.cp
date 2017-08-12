#include <iostream>
using namespace std;

int main(){
    int tim;
    cin >> tim;
    for(int p = 0; p < tim; p++){
        int a,b;
        cin >> a >> b;
        
        int tmp1 = 1;
        int tmp2 = 1;
        if(a > b){
            for(int i = 0; i < a; i++){
                tmp1 = tmp1 * 2;
            }
            for(int i = 0; i < b; i++){
                tmp2 = tmp2 * 2;
            }
        }else if(a < b){
            for(int i = 0; i < b; i++){
                tmp1 = tmp1 * 2;
            }
            for(int i = 0; i < a; i++){
                tmp2 = tmp2 * 2;
            }
        }else{
            for(int i = 0; i < a; i++){
                tmp2 = tmp2 * 2;
            }
            tmp1 = tmp2;
        }
        int fenzi = tmp1 / tmp2 + 1;
        if(fenzi == 2){
            cout << "1/" << tmp1 / 2 << endl;
        }
        else{
            cout << fenzi << "/" << tmp1 << endl;
        }
        
        
        
    }
    return 0;
}

