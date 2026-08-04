import kotlin.math.max

class Solution {
    fun maxFreqSum(s: String): Int {
        var n = s.length
        val arr = IntArray(26)
        for(x in s){
            arr[x-'a']++;
        }
        var vowel = 0
        var conso = 0
        for(x in s){
            if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u'){
                vowel = max(vowel,arr[x-'a'])
            }else conso = max(conso,arr[x-'a'])
        }
        return vowel+conso
    }
}