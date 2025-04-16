#include "leader.h"

using namespace std;

Leader::Leader(string name, string badge, string gym) : Entraineur(name) {
    this->badge = badge;
    this->gym = gym;
}

string Leader::getBadge() const {
    return badge;
}

string Leader::getGym() const {
    return gym;
}
