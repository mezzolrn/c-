#include <iostream>
#include <sstream>
using namespace std;

struct app{
    int val;
    int par;
};


int kill(app apps[], int len, int inta){
    int m;
    for(m = 0; m < len; m++){
        if(apps[m].val == inta) {
            apps[m].val = -1;
        } else if(apps[m].par == inta) {
            kill(apps, len, apps[m].val);
        }
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        
        int b;
        cin >> b;
        
        app apps[b];
        int len = 0;
        
        apps[0].val = 0;
        apps[0].par = 0;
        len++;
        
        for(int j = 0; j < b; j++){
            string a;
            cin >> a;
            if(a[0] == 'F'){
                
                int inta,intb;
                cin >> inta >> intb;
                
                apps[len].val = intb;
                apps[len].par = inta;
                len++;
                
            
            }else if(a[0] == 'Q'){
                int inta;
                cin >> inta;
                
                int m;
                for(m = 0; m < len; m++){
                    if(apps[m].val == inta) break;
                }
                if(m < len) cout << "Yes" << endl;
                else cout << "No" << endl;
                
                
            }else if(a[0] == 'K'){
                
                int inta;
                cin >> inta;

                kill(apps, len, inta);
                
                int m;
                for(m = 0; m < len; m++){
                    if(apps[m].val == -1){
                        len--;
                        
                        apps[m].val = apps[len].val;
                        apps[m].par = apps[len].par;
                        m--;
                    }
                }
                cout << len << endl;
            }
        }
    }
    
    return 0;
}
