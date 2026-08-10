#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
        // Custom comparator comparing squared Euclidean distances
        auto dist = [](const std::vector<int>& p) {
            return p[0] * p[0] + p[1] * p[1];
        };

        // Reorders points such that the top k elements are the smallest k points
        std::nth_element(points.begin(), points.begin() + k - 1, points.end(),
            [&dist](const std::vector<int>& a, const std::vector<int>& b) {
                return dist(a) < dist(b);
            });

        // Return the first k points
        return std::vector<std::vector<int>>(points.begin(), points.begin() + k);
    }
};