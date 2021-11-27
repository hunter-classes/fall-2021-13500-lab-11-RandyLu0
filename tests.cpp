#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "network.h"
#include "profile.h"

using std::to_string;

Profile p1 = Profile();
Profile p2("user","display");
Network nw;

TEST_CASE("task A"){
    CHECK(p1.getUsername() == "");
    p1.setDisplayName("hacker");
    CHECK(p2.getUsername() == "user");
    CHECK(p1.getFullName() == "hacker (@)");
    CHECK(p2.getFullName() == "display (@user)");
}

TEST_CASE("task B"){
    CHECK(nw.addUser("mario","mario"));
    CHECK(!nw.addUser("mario","mario"));
    CHECK(!nw.addUser("",""));
    CHECK(!nw.addUser("@@@","*-*-"));
    CHECK(nw.addUser("luigi","mario"));
    for(int i = 0; i < 18; i++)
        nw.addUser(to_string(i),"apple");
    CHECK(!nw.addUser("wario","wario"));
}

TEST_CASE("task C"){
    CHECK(nw.follow("mario","luigi"));
    CHECK(nw.follow("mario","mario"));
    CHECK(!nw.follow("mario","mario"));
    CHECK(!nw.follow("mario",""));
    CHECK(!nw.follow("","mario"));
}