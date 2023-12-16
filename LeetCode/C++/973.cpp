class Solution {
public:
    struct Point {
        int x;
        int y;
        double distance;   // 원점과의 유클리드 거리
    };

    struct Compare {
        bool operator()(const Point a, const Point b){
            return a.distance > b.distance;
        }
    };

    double calculateDistance(vector<int> point) {
        return sqrt(pow(point[0], 2) + pow(point[1], 2));
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Point, vector<Point>, Compare> pq;
        int repeat = points.size() - k;
        vector<vector<int>> answer;

        for(vector<int> point : points) {
            int x = point[0];
            int y = point[1];
            double dist = calculateDistance(point);
            pq.push({x, y, dist});
        }
        
        while(pq.size() > repeat) {
            answer.push_back({pq.top().x, pq.top().y});
            pq.pop();
        }

        return answer;
    }
};