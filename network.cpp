#include "network.h"
#include <iostream>
using std::cout;

int Network::findID (string usrn){
    for (int i = 0; i < numUsers; ++i)
        if(profiles[i].getUsername() == usrn)
            return i;
    return -1;
}

Network::Network(){
    numUsers = 0;
    //numPosts = 0;
    for (int i = 0; i < MAX_USERS; ++i)
        for (int j = 0; j < MAX_USERS; ++j)
            following[i][j] = false;

}

bool Network::addUser(string usrn, string dspn){
    for (auto c :usrn)
        if(!isalnum(c))
            return false;
    if(usrn.length() and numUsers < MAX_USERS and findID(usrn) == -1){
        profiles[numUsers++] = Profile(usrn,dspn);
        return true;
    }
    return false;
}

bool Network::follow(string usrn1, string usrn2){
    if(findID(usrn1) >= 0 and findID(usrn2) >= 0 and !following[findID(usrn1)][findID(usrn2)]){
        following[findID(usrn1)][findID(usrn2)] = true;
        return true;
    }
    return false;
}

void Network::printDot(){
    cout << "digraph {\n";
    for (int i = 0; i < numUsers; i++)
        cout << "\t\"@" + profiles[i].getUsername() + "\"\n";
    cout << "\n";
    for (int i = 0; i < MAX_USERS; ++i)
        for (int j = 0; j < MAX_USERS; ++j)
            if(following[i][j])
                cout << "\t\"@" + profiles[i].getUsername() + "\" -> \"@" + profiles[j].getUsername() + "\"\n";
    cout << "}\n";
}

/*
bool Network::writePost(string usrn, string msg){
    if(findID(usrn) >= 0  and numPosts < MAX_POSTS){
        Post p;
        p.username = usrn;
        p.message = msg;
        posts[numPosts++] = p;
        return true;
    }
    return false;
}

bool Network::printTimeline(string usrn){
    bool printed = false;
    int p = findID(usrn);
    if(p < 0)
        return printed;
    string name = profiles[p].getFullName() + ": ";
    for (int i = numPosts; i >= 0; i--) {
        if(posts[i].username == usrn){
            printed = true;
            cout << name + posts[i].message + "\n";
        }
        else if(following[p][findID(posts[i].username)]){
            printed = true;
            cout << profiles[findID(posts[i].username)].getFullName() + ": " + posts[i].message + "\n";
        }
    }
    return printed;
}

 */
