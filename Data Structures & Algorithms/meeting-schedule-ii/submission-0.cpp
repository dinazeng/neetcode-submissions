/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        unordered_map <int, int> meetingsAtTime;

        for (Interval i : intervals) {
            int start = i.start;
            int end = i.end;
            for (int m = start; m < end; m++) {
                meetingsAtTime[m]++;
            }
        }

        int rooms = 0;
        for (auto p : meetingsAtTime) {
            rooms = max(rooms, p.second);
        }
        
        return rooms;
    }
};
