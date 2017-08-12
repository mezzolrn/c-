#include <iostream>
#include <string>
#include <sstream>
using namespace std;


int main(){
    int n;
    cin >> n;
    
    for(int m = 0; m < n; m++){
        string k;
        cin >> k;
        
        
        long index = 0;
        int i = 0;
        string array[15];
        
        while(k.find(".") != -1){
            index = k.find(".");
            array[i] = k.substr(0,index);
            i++;
            k = k.substr(index+1);
        }
        array[i] = k;
        i++;
        
        if(i != 4) {
            cout << "No" << endl;
            continue;
        }
        
        int intarr[i];
        int j;
        for(j = 0; j < i; j++){
            int p = 0;
            while((array[j].substr(p,1) == "0" ||
                   array[j].substr(p,1) == "1" ||
                   array[j].substr(p,1) == "2" ||
                   array[j].substr(p,1) == "3" ||
                   array[j].substr(p,1) == "4" ||
                   array[j].substr(p,1) == "5" ||
                   array[j].substr(p,1) == "6" ||
                   array[j].substr(p,1) == "7" ||
                   array[j].substr(p,1) == "8" ||
                   array[j].substr(p,1) == "9" ) && p < array[j].length()){
                p++;
            }
            if(p == array[j].length()) {
                stringstream ss;
                ss << array[j];
                ss >> intarr[j];
                
                if(intarr[j] < 0 || intarr[j] > 255) break;
            }
            else break;
            
        }
        
        if(j == i) cout << "Yes" << endl;
        else cout << "No" << endl;
        
    }
    return 0;
    
}
