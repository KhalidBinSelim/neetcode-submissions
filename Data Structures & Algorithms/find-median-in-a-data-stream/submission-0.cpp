class MedianFinder {
    vector<int> data;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        data.push_back(num);
    }
    
    double findMedian() {
        sort(data.begin(), data.end());
        int len = data.size();
        if (len & 1) return data[len / 2];
        else return ((data[len / 2] + data[len / 2 - 1]) / 2.0);
    }
};
