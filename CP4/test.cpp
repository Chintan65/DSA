#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumAND(vector<int>& nums, int k, int m) {
        long long ans = 0;
        int n = nums.size();
        for (int i = 30; i >= 0; i--) {
            long long t = ans | (1LL << i);
            vector<long long> c;
            for (int x : nums) {
                long long v = 0;
                bool forced = false;
                for (int j = 30; j >= 0; j--) {
                    long long b = 1LL << j;
                    if (t & b) {
                        v |= b;
                        // If this bit in v is 1 but in x was 0, 
                        // all lower bits in v can be 0 to keep v minimal.
                        if (!(x & b)) forced = true;
                    } else if (!forced && (x & b)) {
                        // If we haven't been "forced" to a larger value yet,
                        // we can carry over bits from x to keep v >= x.
                        v |= b;
                    }
                }
                c.push_back(v - x);
            }
            sort(c.begin(), c.end());
            long long s = 0;
            for (int j = 0; j < m; j++) s += c[j];
            if (s <= (long long)k) ans = t;
        }
        return (int)ans;
    }
};