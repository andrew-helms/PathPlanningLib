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
            std::vector<std::shared_ptr<const Action2D>> actions{
                std::make_shared<const Action2D>(1, 0, 1.0),
                std::make_shared<const Action2D>(-1, 0, 1.0),
                std::make_shared<const Action2D>(0, 1, 1.0),
                std::make_shared<const Action2D>(0, -1, 1.0)
            };
            
            Implementations::Dijkstras<State2D, Action2D> planner(actions);
        }
    }
}

int main(int argc, char *argv[])
{
    PathPlanningLib::Tests::DijkstrasTest::TestDijkstras();

}