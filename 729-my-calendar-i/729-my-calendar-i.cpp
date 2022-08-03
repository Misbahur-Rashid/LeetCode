

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

class MyCalendar {
public:
    vector<pair<int, int>> bookings;

    bool book(int start, int end) {
    
        for (pair<int, int> p : bookings)
            if (max(p.first, start) < min(end, p.second)) return false;

        bookings.push_back({start, end});
        
        return true;
    }
};