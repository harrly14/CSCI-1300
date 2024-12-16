#include "Event.h"

Event::Event() {
    _event_num = -1;
    _path_type = -1;
    _impacting_familiars = {};
    _title = "";
    _description = "";
}

Event::Event(int num, int path, std::vector<int> important_familiars, int sardines_change, std::string title, std::string desc, std::string imp_desc, int fam_sardines_change) {
    _event_num = num;
    _path_type = path;
    _sardines_change_no_familiar = sardines_change;
    _impacting_familiars = important_familiars;
    _title = title;
    _description = desc;
    _impacted_description = imp_desc;
    _sardines_change_w_familiar = fam_sardines_change;
}

bool Event::isValidEvent(int current_path, int familiar_num) const {
    // Check path type compatibility
    if (_path_type != 0 && _path_type != current_path) {
        return false;
    }

    if (_event_num == 23){  // Cat eating sardines
        return familiar_num == 4;  
    }
    return true;

}

int Event::applyEvent(int sardines, int familiar_num) {
    std::cout << _description << std::endl;

    for (unsigned int i = 0; i < _impacting_familiars.size(); ++i) {
        if (_impacting_familiars[i] == familiar_num) {
            std::cout << _impacted_description << std::endl;
            if (_sardines_change_w_familiar > 0 ) {
                std::cout << "\n+";
            }
        std::cout << _sardines_change_w_familiar << " Sardines." << std::endl;
        return sardines + _sardines_change_w_familiar;
        }
    }
    
    if (_sardines_change_no_familiar > 0 ) {
        std::cout << "\n+";
    }
    std::cout << _sardines_change_no_familiar << " Sardines." << std::endl;
    return sardines + _sardines_change_no_familiar;

}

void Event::displayEvent() {
    std::cout << _event_num << ". " << _title << "\n" << _description << _impacted_description << "\nPath: " << _path_type << "\nFamiliars: ";
    if (_impacting_familiars.size() > 0) {std::cout << _impacting_familiars[0];}
    if (_impacting_familiars.size() > 1) {std::cout << "," << _impacting_familiars[1];}
    std::cout << "\nSardines change (no fam): " << _sardines_change_no_familiar << "\nSardines change (fam): " << _sardines_change_w_familiar << std::endl;
}