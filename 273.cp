#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;


struct arr{
    string name;
    int length;
    int arra[100];
};




int main(){
    int time;
    cin >> time;
    
    for(int a = 0; a < time; a++){
        int line;
        cin >> line;
        
        arr t[9999];
        int tindex = 0;
        
        long left;
        long right;
        
        int index;
        int tmp;
        
        for(int b = 0; b < line; b++){
            string str;
            cin >> str;
            
            int i = 0;
            
            while((str[i] <= 'z' && str[i] >= 'a') || (str[i] <= 'Z' && str[i] >= 'A')){
                i++;
            }
            
            string s = str.substr(0,i);
            
            if(str[i] == '='){
                
                int j;
                for(j = 0; t[j].name != s && j < tindex;j++){
                }
                if( j == tindex){
                    t[tindex].name = s;
                    t[tindex].length = 0;
                    tindex++;
                }
                else {
                    t[j].length = 0;
                }
                
            }
            
            else if(str[i] == '['){
                left = str.find('[');
                right = str.find(']');
                string sub = str.substr(left + 1, right - left + 1);
                stringstream ss;
                ss << sub;
                ss >> index;
                
                int j;
                for(j = 0; t[j].name != s;j++){
                }
                if(index >= t[j].length){
                    cout << "ERROR" << endl;
                }
                else {
                    cout << t[j].arra[index] << endl;
                }
            }
            
            else if(str[i] == '.' && str[i + 1] == 'a'){
                left = str.find('(');
                right = str.find(')');
                string sub = str.substr(left + 1, right - left + 1);
                stringstream ss;
                ss << sub;
                ss >> tmp;
                
                int j;
                for(j = 0; t[j].name != s;j++){
                }
                t[j].arra[t[j].length] = tmp;
                t[j].length++;
            }
            
            else if(str[i] == '.' && str[i + 1] == 's'){
                int j;
                for(j = 0; t[j].name != s;j++){
                }
                
                for(int i=0;i < t[j].length - 1;i++){
                    for(int k =i+1;k < t[j].length;k++){
                        if(t[j].arra[k] < t[j].arra[i]){
                            int tm = t[j].arra[k];
                            t[j].arra[k] = t[j].arra[i];
                            t[j].arra[i] = tm;
                        }
                    }
                }
                
            }
        }
        
    }
    
    return 0;
    
}
