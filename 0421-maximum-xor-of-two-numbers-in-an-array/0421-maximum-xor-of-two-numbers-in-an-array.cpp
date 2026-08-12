class Solution {
public:
    struct trieNode{
        trieNode* left; //0 
        trieNode* right;  // 1
    };

    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        newNode->left = NULL; //0 
        newNode->right = NULL;
        return newNode;
    }

    void insert(int num,trieNode* root){
        trieNode* pCrawl = root;

        for(int i=31;i>=0;i--){
            int ith_bit = (num>>i)&1;

            if(ith_bit==0){
                if(pCrawl->left == NULL){
                    pCrawl->left = getNode();
                }
                pCrawl = pCrawl->left ;
            }else{
                if(pCrawl->right == NULL){
                    pCrawl->right = getNode();
                }
                pCrawl = pCrawl->right ;
            }
        }
    }

    int findMaxXor(trieNode* root,int num){
        int maxXor = 0;

        trieNode* pCrawl = root;

        for(int i=31;i>=0;i--){
            int ith_bit = (num>>i)&1;

            if(ith_bit == 1){
                if(pCrawl->left != NULL){
                    pCrawl = pCrawl->left;
                    maxXor += pow(2,i);
                }else{
                    pCrawl = pCrawl->right;
                }
            }else{
                if(pCrawl->right != NULL){
                    pCrawl = pCrawl->right;
                    maxXor += pow(2,i);
                }else{
                    pCrawl = pCrawl->left;
                }
            }
        }
        return maxXor;
    }

    
    int findMaximumXOR(vector<int>& nums) {
        trieNode* root = getNode();

        for(int &num: nums){
            insert(num,root);
        }

        int maxResult = 0;

        for(int i=0;i<nums.size();i++){
            maxResult = max(maxResult,findMaxXor(root,nums[i]));
        }

        return maxResult;
    }
};