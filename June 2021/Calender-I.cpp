class MyCalendar
{
    set<pair<int, int>> cal;

public:
    MyCalendar() {}
    bool book(int start, int end)
    {
        auto it = cal.lower_bound({start, end});
        if (it != cal.begin() && prev(it)->second > start)
            return false;
        if (it != cal.end() && end > it->first)
            return false;
        cal.insert({start, end});
        return true;
    }
};