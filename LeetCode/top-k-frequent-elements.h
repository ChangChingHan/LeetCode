#https://leetcode.com/problems/top-k-frequent-elements/

struct KFrequent
{
    int val;
    int frequent;
    KFrequent(int x):val(x){}
    KFrequent(int x, int y):val(x),frequent(y){}
};
class Solution {
public:
    int find (vector<KFrequent>& v, int val){
        for (int i = 0; i < v.size(); i++) {
            if (v[i].val == val) return i;
        }
        return -1;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //number - frequent
        //map<int,int> frequentNum;
        vector<KFrequent> frequentNum;
        
        for (int i = 0; i < nums.size(); i++) {
            int n = find(frequentNum, nums[i]);
            if (n == -1) {
                frequentNum.push_back(KFrequent(nums[i],1));
            } else {
                frequentNum[n].frequent++;
            }
        }
        
        bool isContinue = true;
        while (isContinue == true) {
            isContinue = false;
            for (int i = 1; i < frequentNum.size(); i++){
                if (frequentNum[i-1].frequent < frequentNum[i].frequent) {
                    swap(frequentNum[i-1],frequentNum[i]);
                    isContinue = true;
                }
            }
        }
        
        vector<int> result;
        for (int i = 0; i < frequentNum.size(); i++) {
            result.push_back(frequentNum[i].val);
            if(i == k-1) break;
        }
        
        return result;
    }
};
