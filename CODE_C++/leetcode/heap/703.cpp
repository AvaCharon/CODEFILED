
//堆(小顶堆)自动排序
class KthLargest {
    int K;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        for (int n : nums) {
            pq.push(n);
            if (pq.size() > k) pq.pop();
        }       
        K = k;
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > K) pq.pop();
        return pq.top();
    }
};


//利用multiset自动排序
class KthLargest {
    int K;
    multiset<int> st;//使其可以存储多个一样的数
public:
    KthLargest(int k, vector<int>& nums) {
        for (auto &n : nums) {
            st.insert(n);
            if (st.size() > k) st.erase(st.begin());
        }       
        K = k;

    }
    
    int add(int val) {
        st.insert(val);
        if (st.size() > K) st.erase(st.begin());
        return *st.begin();
    }
};


/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */