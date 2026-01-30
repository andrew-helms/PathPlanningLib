#include "AStarTest.hpp"
#include "DijkstrasTest.hpp"

int main(int argc, char *argv[])
{
    PathPlanningLib::Tests::AStarTest::TestAStar();
    PathPlanningLib::Tests::DijkstrasTest::TestDijkstras();
}