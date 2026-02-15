class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        string c = "";

        while(i >= 0 || j >= 0 || carry){

            if(i >= 0 && j >= 0){

                if(a[i]=='1' && b[j]=='1' && carry){        // 111
                    c += '1';
                    carry = 1;
                }
                else if(a[i]=='1' && b[j]=='1' && !carry){  // 110
                    c += '0';
                    carry = 1;
                }
                else if(a[i]=='1' && b[j]=='0' && carry){   // 101
                    c += '0';
                    carry = 1;
                }
                else if(a[i]=='1' && b[j]=='0' && !carry){  // 100
                    c += '1';
                    carry = 0;
                }
                else if(a[i]=='0' && b[j]=='1' && carry){   // 011
                    c += '0';
                    carry = 1;
                }
                else if(a[i]=='0' && b[j]=='1' && !carry){  // 010
                    c += '1';
                    carry = 0;
                }
                else if(a[i]=='0' && b[j]=='0' && carry){   // 001
                    c += '1';
                    carry = 0;
                }
                else{                                       // 000
                    c += '0';
                    carry = 0;
                }

                i--;
                j--;
            }

            else if(i >= 0 && j < 0){

                if(carry && a[i]=='1'){
                    c += '0';
                    carry = 1;
                }
                else if(a[i]=='0' && carry){
                    c += '1';
                    carry = 0;
                }
                else{
                    c += a[i];
                }
                i--;
            }

            else if(i<0 && j>=0){ // j >= 0
             
                if(carry && b[j]=='1'){
                    c += '0';
                    carry = 1;
                }
                else if(b[j]=='0' && carry){
                    c += '1';
                    carry = 0;
                }
                else{
                    c += b[j];
                }
                j--;
            }
            else if(carry){
                c+='1';
                carry =0;
            }
        }

        reverse(c.begin(), c.end());
        return c;
    }
};
