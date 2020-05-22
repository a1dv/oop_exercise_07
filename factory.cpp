#include "factory.h"

std::shared_ptr<figure> factory::fig(std::istream &is) {
    std::string name;
    is >> name;
    if ( name == "pentagon" ) {
        return std::shared_ptr<figure> ( new pentagon(is));
    } else if ( name == "hexagon") {
        return std::shared_ptr<figure> ( new hexagon(is));
    } else if ( name == "octagon") {
        return std::shared_ptr<figure> ( new octagon(is));
    } else {
        throw std::logic_error("There is no such figure\n");
    }
}

std::shared_ptr<figure> factory::fig_from_file(std::ifstream &is) {
    std::string name;
    is >> name;
    if ( name == "pentagon" ) {
        return std::shared_ptr<figure> ( new pentagon(is));
    } else if ( name == "hexagon") {
        return std::shared_ptr<figure> ( new hexagon(is));
    } else if ( name == "octagon") {
        return std::shared_ptr<figure> ( new octagon(is));
    } else {
        throw std::logic_error("There is no such figure\n");
    }
}
