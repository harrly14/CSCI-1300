#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include <vector>
class Event{
    public:
        int _event_num;
        int _path_type;
        std::vector<int> _impacting_familiars;
        int _sardines_change_no_familiar, _sardines_change_w_familiar;
        std::string _title;
        std::string _description;
        std::string _impacted_description;


        Event();
        Event(int num, int path, std::vector<int> important_familiars, int sardines_change, std::string title, std::string desc, std::string imp_desc, int fam_sardines_change);
        bool isValidEvent(int current_path, int familiar_num) const;
        int applyEvent(int sardines, int familiar_num);
        void displayEvent();
};
#endif