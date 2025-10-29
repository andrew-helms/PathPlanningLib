#include <memory>
#include <vector>
#include <iostream>

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

            State2D::SetObstacles(std::unordered_set<State2D>
                ({
                    State2D(1,3),
                    State2D(0,3),
                    State2D(-1,3)
                }));
            
            Implementations::Dijkstras<State2D, Action2D> planner(actions);
            std::vector<std::shared_ptr<PlannerTemplate::Connection<State2D, Action2D>>> path;

            bool success = planner.PlanPath(
                &path,
                std::make_shared<const State2D>(0, 0),
                std::make_shared<const State2D>(0, 5)
            );

            if (!success)
            {
                std::cout << "No path found" << std::endl;
            }

            for (std::shared_ptr<PlannerTemplate::Connection<State2D, Action2D>> step : path)
            {
                std::shared_ptr<const Action2D> action = step->GetAction();
                std::shared_ptr<const State2D> state = step->GetState();
                std::cout << "State:\t" << state->GetX() << "," << state->GetY() << std::endl;
                std::cout << "Action:\t" << action->GetMoveX() << "," << action->GetMoveY() << std::endl;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    PathPlanningLib::Tests::DijkstrasTest::TestDijkstras();

}