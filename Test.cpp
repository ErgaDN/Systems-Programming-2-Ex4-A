#include "sources/Team.hpp"
#include "doctest.h"

using namespace std;
using namespace ariel;

TEST_CASE("Point class")
{
    Point a(0, 0), b(5.5, 0), c(0, 9), d(5.5, 9);
    CHECK(d.getX() == 5.5);
    CHECK(d.getY() == 9);
    CHECK(a.distance(b) == c.distance(d));
    CHECK(a.distance(c) == b.distance(d));
    CHECK(a.distance(b) < a.distance(c));
}

TEST_CASE("Character class")
{
    Character a(Point(1, 2), 10, "test_1"), b(Point(1, 5), 10, "test_2");
    CHECK(a.distance(b) == 3);
    CHECK_NOTHROW(a.hit(8));
    CHECK(a.getHitPoint() == 2);
    CHECK_THROWS(a.hit(4));
}

TEST_CASE("cowboy team vs ninja team")
{
    Cowboy *dan = new Cowboy("Dan", Point(1, 2));
    Cowboy *ran = new Cowboy("Ran", Point(3, 4));
    Team team_C(dan);
    CHECK_THROWS(team_C.add(dan));
    CHECK_NOTHROW(team_C.add(ran));
    CHECK(ran->getHitPoint() == 110);

    YoungNinja *young = new YoungNinja("Young", Point(6, 5));
    Team team_N(young);
    CHECK(team_N.stillAlive() == true);

    dan->shoot(young);
    CHECK(dan->getHitPoint() == 109);
    CHECK(young->getHitPoint() == 90);

    team_C.attack(&team_N);
    CHECK(team_C.stillAlive() == 2);
    CHECK(team_N.stillAlive() != 1);

    CHECK_NOTHROW(ran->shoot(dan));
    CHECK_THROWS(ran->shoot(ran));
}

TEST_CASE("slash function")
{
    OldNinja *enemy = new OldNinja("Enemy", Point(0, 0));
    TrainedNinja *tNinja = new TrainedNinja("T_Ninja", Point(0.5, 0.5));
    for (int i = 0; i < 3; ++i)
        tNinja->slash(enemy);
    CHECK(enemy->getHitPoint() == 30);
    CHECK_THROWS(tNinja->slash(enemy));
}

TEST_CASE("more then 10 members in team")
{
    Team team(new Cowboy("A", Point(1, 1)));
    team.add(new Cowboy("B", Point(2, 2)));
    team.add(new Cowboy("C", Point(3, 3)));
    team.add(new Cowboy("D", Point(4, 4)));
    team.add(new Cowboy("E", Point(5, 5)));
    team.add(new Cowboy("F", Point(6, 6)));
    team.add(new Cowboy("G", Point(7, 7)));
    team.add(new Cowboy("H", Point(8, 8)));
    team.add(new Cowboy("I", Point(9, 9)));
    CHECK_NOTHROW(team.add(new Cowboy("J", Point(10, 10))));
    CHECK_THROWS(team.add(new Cowboy("K", Point(11, 11))));
}

TEST_CASE("attack the same team twice")
{
    Team team_A(new YoungNinja("A", Point(1, 1)));
    team_A.add(new TrainedNinja("B", Point(2, 2)));

    Team team_B(new OldNinja("C", Point(3,3)));

    CHECK(team_A.stillAlive() == 2);
    CHECK(team_A.stillAlive() == 1);

    team_A.attack(&team_B);
    CHECK_THROWS(team_A.attack(&team_B));
}

TEST_CASE("add a member team after the team was attacked")
{
    Team team_A(new YoungNinja("A", Point(1, 1)));
    Team team_B(new OldNinja("B", Point(2,2)));
    team_A.attack(&team_B);
    CHECK_THROWS(team_B.add(new Cowboy("C", Point(3,3))));
}