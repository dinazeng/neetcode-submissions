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

    struct mycomp {
        bool operator() (Interval &one, Interval &two){
            return one.start > two.start;
        }
    };

    bool canAttendMeetings(vector<Interval>& intervals) {
        priority_queue<Interval, vector<Interval>, mycomp> heap;

        for (Interval i : intervals) {
            heap.push(i);
        }

        int end = -1;

        while (!heap.empty()) {
            if (heap.top().start < end) {
                return false;
            }

            end = heap.top().end;
            heap.pop();
        }   

        return true;
    }
};
