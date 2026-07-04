class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxheap;
        for(auto a:stones){
            maxheap.push(a);
        }
        while(maxheap.size()>1){
            auto x=maxheap.top();
            maxheap.pop();
            auto y=maxheap.top();
            maxheap.pop();
            if(x==y)continue;
            else{
                maxheap.push(x-y);
            }
        }
        if(maxheap.empty())return 0;
        else return maxheap.top();

    }
};
