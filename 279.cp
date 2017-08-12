#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    int tim;
    cin >> tim;
    for(int p = 0; p < tim; p++){
        int n;
        cin >> n;
        
        int abcd[4];
        for(int i = 0 ; i < 4; i++){
            abcd[i] = 0;
        }
        
        
        for(int i = 0; i < n; i++){
            string l,str;
            cin >> l >> str;
            
            long index = str.find(',');
            string str1 = str.substr(0,index);
            string str2 = str.substr(index + 1);
            
            
            
            if(str2[str2.length()-1] == 'B'){
                int tmp = 0;
                int sq = 1;
                int t;
                for(long j = str2.length()-2; j >=0; j--){
                    stringstream ss;
                    ss << str2[j];
                    ss >> t;
                    tmp = t * sq + tmp;
                    sq = sq * 2;
                }
                stringstream ss;
                ss << tmp;
                ss >> str2;
            }
            else if(str2[0] == '0'){
                int tmp = 0;
                int sq = 1;
                int t;
                
                for(long j = str2.length()-2; j >=0; j--){
                    if(str2[j]>='0'&&str2[j]<='9')
                        t=str2[j]-'0';
                    else
                        t=str2[j]-'A'+10;
                    tmp = t * sq + tmp;
                    sq = sq * 16;
                }
                stringstream ss;
                ss << tmp;
                ss >> str2;
            }
            //mov
            if(l[0] == 'M'){
                //取str2
                int tmp2 = 0;
                if(str2[0] <= '9' && str2[0] >= '0'){
                    stringstream ss;
                    ss << str2;
                    ss >> tmp2;
                }
                else{
                    if(str2[1] == 'X') tmp2 = abcd[str2[0] - 'A'];
                    else if(str2[1] == 'L') tmp2 = abcd[str2[0] - 'A'] % 256;
                    else tmp2 = abcd[str2[0] - 'A'] / 256;
                }
                //赋值str1
                if(str1[1] == 'X') abcd[str1[0] - 'A'] = tmp2;
                else if(str1[1] == 'L') abcd[str1[0] - 'A'] = tmp2 + abcd[str1[0] - 'A'] / 256 * 256;
                else abcd[str1[0] - 'A'] = tmp2 * 256 + abcd[str1[0] - 'A'] % 256;
            }
            
            //add
            if(l[0] == 'A'){
                
                //取str2
                int tmp2 = 0;
                if(str2[0] <= '9' && str2[0] >= '0'){
                    stringstream ss;
                    ss << str2;
                    ss >> tmp2;
                }
                else{
                    if(str2[1] == 'X') tmp2 = abcd[str2[0] - 'A'];
                    else if(str2[1] == 'L') tmp2 = abcd[str2[0] - 'A'] % 256;
                    else tmp2 = abcd[str2[0] - 'A'] / 256;
                }
                
                //赋值str1
                
                if(str1[1] == 'X') abcd[str1[0] - 'A'] += tmp2 ;
                else if(str1[1] == 'L') abcd[str1[0] - 'A'] += tmp2;
                else abcd[str1[0] - 'A'] += tmp2 * 256;
            }
        }
        for(int i = 0; i < 3; i++){
            cout << abcd[i] << ' ';
        }
        cout << abcd[3] << endl;
    }
    return 0;
}

