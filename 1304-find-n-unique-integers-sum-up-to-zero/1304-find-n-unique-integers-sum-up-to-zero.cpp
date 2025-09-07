class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>a(n);
        if(n%2){
            a[0]=0;
          for(int i=1;i<n;i++){
             a[i]=i;
             a[i+1]=-(i);
             i++;
           }
        }
        else{
           for(int i=0;i<n;i++){
              a[i]=i+1;
              a[i+1]=-(i+1);
              i++;
           }
        }
        return a;
    }
};