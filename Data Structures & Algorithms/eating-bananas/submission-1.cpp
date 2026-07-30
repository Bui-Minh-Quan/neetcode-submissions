class Solution {
public:
    bool is_possible(const int& speed, const int& h, const vector<int>& piles) {
        int time = 0;
        for (const auto& pile:piles) {
            time += (pile + speed - 1) / speed;
            if (time > h)
                return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int min_speed = 1;
        int max_speed = *max_element(piles.begin(), piles.end());
        int ans = max_speed;
        while (min_speed <= max_speed) {
            int mid = (min_speed + max_speed) / 2;

            if (!is_possible(mid, h, piles)) { // Too slow
                min_speed = mid + 1;
            } else  {// fast enough, possibly slower
                ans = mid;
                max_speed = mid - 1;
            }
        }



        return ans;   
    }
};
