class Solution {
public:
    long func(long num,bool odd){
        long temp = num;
        if(odd){
            temp/=10;
        }

        while(temp){
            num = 1L*num*10 + temp%10;
            temp/=10;
        }
        return num;
    }

    string nearestPalindromic(string s) {
        int l = s.length();

        int mid = l/2;
        int firstHalfLength = (l%2==0)?mid:mid+1;

        long firstHalf = stol(s.substr(0,firstHalfLength));

        vector<long>possibleResults;

        possibleResults.push_back(func(firstHalf,l%2));
        possibleResults.push_back(func(firstHalf+1,l%2));
        possibleResults.push_back(func(firstHalf-1,l%2));
        possibleResults.push_back((long)pow(10,l-1)-1);
        possibleResults.push_back((long)pow(10,l)+1);

        long diff = LONG_MAX;

        long result = -1;
        long original = stol(s);

        for(long num:possibleResults){
            if(num==original)continue;
            if(abs(num-original)<diff){
                diff = abs(num-original);
                result = num;
            }
            if(abs(num-original)==diff){
                result = min(num,result);
            }
        }

        return to_string(result);
    }
};