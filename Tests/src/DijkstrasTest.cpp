#include <memory>
#include <vector>

#include "DijkstrasTest.hpp"
#include "Action2D.hpp"
#include "State2D.hpp"

namespace PathPlanningLib
{
    namespace Tests
    {
        void DijkstrasTest::TestDijkstras()
        {
            std::vector<std::shared_ptr<Action2D>> actions{
                std::make_shared<Action2D>(1, 0, 1.0),
                std::make_shared<Action2D>(-1, 0, 1.0),
                std::make_shared<Action2D>(0, 1, 1.0),
                std::make_shared<Action2D>(0, -1, 1.0)
            };            
        }
    }
}

int main(int argc, char *argv[])
{
    PathPlanningLib::Tests::DijkstrasTest::TestDijkstras();

}