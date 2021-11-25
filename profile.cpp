#include "profile.h"

Profile::Profile() {
}

Profile::Profile(string usrn, string dspn) {
    username = usrn;
    displayname = dspn;
}

string Profile::getFullName() const {
    return displayname +  " (@" + username + ")";
}

void Profile::setDisplayName(string dspn) {
    displayname = dspn;
}

string Profile::getUsername() const {
    return username;
}

