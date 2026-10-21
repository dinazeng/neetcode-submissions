class CountSquares {
public:

    unordered_map<int, unordered_map<int, int>> points;   
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        points[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int counted_squares = 0;
        int x1 = point[0];
        int y1 = point[1];

        for (auto &[y2, count] : points[x1]) {
            int side = y2 - y1;
            if (side == 0) continue;
            
            int x3 = x1 + side, x4 = x1 - side;

            counted_squares += count * points[x3][y1] * points[x3][y2];
            counted_squares += count * points[x4][y1] * points[x4][y2];

        }

        return counted_squares;

    }
};
