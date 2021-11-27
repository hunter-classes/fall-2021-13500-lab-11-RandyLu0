#include "profile.h"
#include "network.h"
#include <iostream>

using std::cout;
using std::to_string;

int main(){

    Profile p1("marco", "Marco");
    cout << p1.getUsername() << "\n"; // marco
    cout << p1.getFullName() << "\n"; // Marco (@marco)

    p1.setDisplayName("Marco Rossi");
    cout << p1.getUsername() << "\n"; // marco
    cout << p1.getFullName() << "\n"; // Marco Rossi (@marco)

    Profile p2("tarma1", "Tarma Roving");
    cout << p2.getUsername() << "\n"; // tarma1
    cout << p2.getFullName() << "\n"; // Tarma Roving (@tarma1)

    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");

    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();

    /*
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    nw.follow("mario", "luigi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");

    // write some posts
    nw.writePost("mario", "It's a-me, Mario!");
    nw.writePost("luigi", "Hey hey!");
    nw.writePost("mario", "Hi Luigi!");
    nw.writePost("yoshi", "Test 1");
    nw.writePost("yoshi", "Test 2");
    nw.writePost("luigi", "I just hope this crazy plan of yours works!");
    nw.writePost("mario", "My crazy plans always work!");
    nw.writePost("yoshi", "Test 3");
    nw.writePost("yoshi", "Test 4");
    nw.writePost("yoshi", "Test 5");

    cout << "\n";
    cout << "======= Mario's timeline =======" << "\n";
    nw.printTimeline("mario");
    cout << "\n";

    cout << "======= Yoshi's timeline =======" << "\n";
    nw.printTimeline("yoshi");
    cout << "\n";
    */

    return 0;
}