#pragma once
#ifndef INC_11_NETWORK_H
#define INC_11_NETWORK_H
#include "profile.h"

struct Post{
    string username;
    string message;
};


class Network {
private:
    static const int MAX_USERS = 20;
    int numUsers;
    Profile profiles[MAX_USERS];
    bool following[MAX_USERS][MAX_USERS];
    int findID (string usrn);

    //extras
    static const int MAX_POSTS = 100;
    int numPosts;
    Post posts[MAX_POSTS];
public:
    Network();
    bool addUser(string usrn, string dspn);
    bool follow(string usrn1, string usrn2);
    void printDot();

    //extras
    bool writePost(string usrn, string msg);
    bool printTimeline(string usrn);
};



#endif //INC_11_NETWORK_H
