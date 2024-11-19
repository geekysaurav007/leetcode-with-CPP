class node {
public:
    int start,  end,index;
    node(int s, int e,int i) {
        start = s;
        end = e;
        index=i;
    }
};
class compare {
public:
    bool operator ()(node* a, node* b) { return a->end > b->end; }
};
// TC:-O(nlogn) 
// SC:- O(N)
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        priority_queue<node*, vector<node*>, compare> pq;
        int i = 1;
        for (auto it : pairs) {
            pq.push(new node(it[0], it[1], i++));
        }
        int cb = pq.top()->end;
        int ca = pq.top()->start;
        pq.pop();

        int cnt = 1;
        while (!pq.empty()) {
            node* temp = pq.top();
            pq.pop();
            if (temp->start > cb) {
                cb = temp->end;
                ca = temp->start;
                cnt++;
            }
        }
        return cnt;
    }
};