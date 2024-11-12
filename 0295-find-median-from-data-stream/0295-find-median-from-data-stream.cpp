class MedianFinder {
public:
    priority_queue<int> lmh;
    priority_queue<int, vector<int>, greater<int>> rmh;
    MedianFinder() {}

    void addNum(int num) {
        // agar left wala khaali ho ya incoming ele chota ho left ke top se
        if (lmh.empty() or num < lmh.top()) {
            lmh.push(num);
        } else {
            rmh.push(num);
        }
        // check if left me 1  kam elements hai toh right se left me push
        if (lmh.size() < rmh.size()) {
            lmh.push(rmh.top());
            rmh.pop();
        } 
        // check if left me 1 se jyada elements jyada hai right se toh left se utha ke right push
        else if (lmh.size() - rmh.size() > 1  ) {
            rmh.push(lmh.top());
            lmh.pop();
        }
    }

    double findMedian() {
        if (lmh.size() == rmh.size()) {
            // even size
            double median = rmh.top() + lmh.top();
            return median / 2.0;
        } else {
            return lmh.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */