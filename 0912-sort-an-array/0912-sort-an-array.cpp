class Solution {
public:
   void mergeSort(vector<int>&nums,int s,int e){
    if(s>=e)return;
     int mid=s+(e-s)/2;

     mergeSort(nums,s,mid);  //left
     mergeSort(nums,mid+1,e);  //right
     merge(nums,s,mid,e);
   }

   void merge(vector<int>&nums,int s,int mid,int e){
            vector<int>temp;
            int l=s;
            int r=mid+1;
            //compare and add element in sorted order of two part to merge it
            while(l<=mid && r<=e){
                if(nums[l]<=nums[r]){
                    temp.push_back(nums[l]);
                    l++;
                }else{
                    temp.push_back(nums[r]);
                    r++;
                }
            }
            // if left side have elements lefts
            while(l<=mid){
                temp.push_back(nums[l]);
                l++;
            }
           // if right side have elements left
            while(r<=e){
                temp.push_back(nums[r]);
                r++;
            }
            // store temp in  nums
            for(int i=s;i<=e;i++){
                nums[i]=temp[i-s];
            }
    }


    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};