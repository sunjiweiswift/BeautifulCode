#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        for (size_t i = 0; i < k; i++) {
            insert_(nums[i]);
        }
        vector<double> result;
        balance_();
        result.push_back(getMid_());
        for (size_t i = k; i < nums.size(); i++) {
            insert_(nums[i]);
            delete_(nums[i - k]);
            result.push_back(getMid_());
        }
        return result;
    }

private:
    double getMid_() {
        if ((smallSize_ + bigSize_) % 2 == 1) {
            return small_.top();
        } else {
            return small_.top() / 2.0 + big_.top() / 2.0;
        }
    }
    void insert_(int num) {
        if (small_.empty() || small_.top() >= num) {
            small_.push(num);
            smallSize_++;
        } else {
            big_.push(num);
            bigSize_++;
        }
        balance_();
    }
    void delete_(int num) {
        record_[num]++;
        if (small_.top() >= num) {
            smallSize_--;
            if (num == small_.top()) {
                deleteSmallTop_();
            }
        } else {
            bigSize_--;
            if (num == big_.top()) {
                deleteBigTop_();
            };
        }
        balance_();
    }
    void balance_() {
        if (smallSize_ > 1 + bigSize_) {
            big_.push(small_.top());
            small_.pop();
            smallSize_--;
            bigSize_++;
            deleteSmallTop_();
        } else if (bigSize_ > smallSize_) {
            small_.push(big_.top());
            big_.pop();
            smallSize_++;
            bigSize_--;
            deleteBigTop_();
        }
    }
    void deleteSmallTop_() {
        while (!small_.empty() && record_[small_.top()] > 0) {
            record_[small_.top()]--;
            small_.pop();
        }
    }
    void deleteBigTop_() {
        while (!big_.empty() && record_[big_.top()] > 0) {
            record_[big_.top()]--;
            big_.pop();
        }
    }

private:
    unordered_map<int, int> record_;
    priority_queue<int> small_;
    priority_queue<int, vector<int>, greater<int>> big_;
    size_t bigSize_ = 0;
    size_t smallSize_ = 0;
};
