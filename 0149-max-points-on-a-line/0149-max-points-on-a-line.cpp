static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 1;
        for (int i = 0; i < points.size(); ++i) {
            vector<int> p1 = points[i];
            unordered_map<double, int> count;
            int vertical = 0, duplicate = 0, localMax = 1;
            for (int j = i + 1; j < points.size(); ++j) {
                vector<int> p2 = points[j];
                if (p2[0] == p1[0] && p2[1] == p1[1]) {
                    duplicate++;
                } else if (p2[0] == p1[0]) {
                    vertical++;
                } else {
                    double slope = double(p2[1] - p1[1]) / double(p2[0] - p1[0]);
                    count[slope]++;
                    localMax = max(localMax, count[slope] + 1);
                }
            }
            localMax = max(localMax, vertical + 1);
            res = max(res, localMax + duplicate);
        }
        return res;
    }
};