class Solution {
    public int[] rearrangeArray(int[] nums) {
        Map<Integer,Integer> mp = new HashMap<>();
        Set<Integer> st = new TreeSet<>(); 
        int n = nums.length;

        int[] ans = new int[n];

        for(int i = 0; i < n; i++) {
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
            st.add(nums[i]);
        }

        int idx = 0;

        while(idx<n){
            for (int x : st) {
                if(mp.get(x) == 0){
                    continue;
                }else{
                    ans[idx++] = x;
                    mp.put(x,mp.get(x)-1);
                }
            }
        }

        

        return ans;

    }
}