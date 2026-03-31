class Solution {
public:
    bool isSame(string &word,string &str2,int i,int m){
        for(int j=0;j<m;j++){
            if(word[i]!=str2[j])return false;
            i++;
        }
        return true;
    }
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int N = n+m-1;
        string word(N,'$');

        vector<bool>canChange(N,false);

        for(int i = 0; i < n; i++){
            if(str1[i] == 'T'){
                for(int j = 0; j < m; j++){
                    if(word[i+j] != '$' && word[i+j] != str2[j])
                        return "";
                    word[i+j] = str2[j];
                }
            }
        }
        for(int i = 0; i < N; i++){
            if(word[i]=='$'){
                word[i]='a';
                canChange[i]=true;
            }
        }


        for(int i=0;i<n;i++){
            if(str1[i]=='F'){
                if(isSame(word,str2,i,m)){
                    bool changed = false;
                    for(int j=i+m-1;j>=i;j--){
                        if(canChange[j]==true){
                            word[j] = 'b';
                            changed = true;
                            break;
                        }
                    }
                    if(!changed)return "";
                }
            }
        }
        return word;
    }
};