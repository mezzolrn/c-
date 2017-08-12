#include <iostream>
using namespace std;

struct stu{
    string name;
    string sex;
    string birth;
};

bool findname(string name, stu student[], int n){
    for(int i = 0; i < n; i++){
        if(student[i].name == name)
            return true;
    }
    return 0;
}

string findsex(string sex, stu student[], int &e, int n){
    
    for(int i = e; i < n; i++){
        if(student[i].sex == sex)
        {
            return student[i].name;
            
        }
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++){
        int a;
        cin >> a;
        
        stu student[1000];
        for(int i = 0; i < a; i++){
            cin >> student[i].name >> student[i].sex >> student[i].birth;
        }
        
        int b;
        cin >> b;
        for(int i = 0; i < b; i++){
            string tmp;
            cin >> tmp;
            
            long tre[2];
            int p = 0;
            while(tmp.find(' ')){
                tre[p] = tmp.find(' ');
                p++;
            }
            if(p == 0){
                switch(tmp[0]){
                    case 'N':
                    case 'S':
                    case 'B':break;
                }
            }
            if(p == 1){
                
            }
            if(p == 2){
                
            }
        }
    }
    
    return 0;
}
