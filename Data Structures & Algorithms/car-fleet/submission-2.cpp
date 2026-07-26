class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int, int>> cars;
        cars.reserve(n);

        for (int i = 0; i < n; i++)
            cars.emplace_back(position[i], speed[i]);

        sort(cars.begin(), cars.end(), greater<>());

        int fleets = 0;
        double lastTime = 0;

        for (const auto& [pos, spd] : cars) {
            double time = (double)(target - pos) / spd;

            if (time > lastTime) {
                fleets++;
                lastTime = time;
            }
        }

        return fleets;
    }
};