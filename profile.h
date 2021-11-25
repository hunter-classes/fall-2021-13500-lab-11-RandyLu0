#pragma once
#ifndef INC_11_PROFILE_H
#define INC_11_PROFILE_H

#include <string>
using std::string;

class Profile {
private:
    string displayname;
    string username;
public:
    string getUsername() const;
    string getFullName() const;
    void setDisplayName(string dspn);
    Profile(string usrn, string dspn);
    Profile();

};


#endif //INC_11_PROFILE_H
