class Solution {
public:
    int maximum69Number (int num) {
        vector<int>a;
        while(num>0){
           a.push_back(num%10);
           num/=10;
        }
        reverse(a.begin(),a.end());
        for(int i=0;i<a.size();i++){
            if(a[i]==9){
                continue;
            }
            else{
                a[i]=9;
                break;
            }
        }
        long long digit = 0;
        for (int digits :a) {
         digit = digit * 10 + digits;
        }
       return digit;
    }
};