class Solution {
public:
    string interpret(string command) {
        int n=command.size();
        string a="";
        for(int i=0;i<n;i++){
           if(command[i]=='G'){
            a+='G';
           }
           else if(command[i]=='(' && command[i+1]==')'){
            a+='o';
            i++;
           }
           else{
            a+='a';
            a+='l';      
            i+=3;   
           }
        }
        return a;
    }
};