class MedianFinder {
public:
    priority_queue<int> pq;
    priority_queue<int,vector<int>,greater<int>> minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        pq.push(num);
        if(!minheap.empty() && pq.top()>minheap.top()){
            minheap.push(pq.top());
            pq.pop();
        }
        if(pq.size()>minheap.size()+1){
            minheap.push(pq.top());
            pq.pop();
        }
        if(minheap.size()>pq.size()+1){
            pq.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        if(pq.size()==minheap.size()){
            return (minheap.top() + pq.top())/2.0;
        }else if(pq.size()>minheap.size()){
            return pq.top();
        }
        else{
            return minheap.top();
        }
    }
};
