#include <memory>
#include <vector>
#include <iostream>

#include "AStarTest.hpp"
#include "Action2D.hpp"
#include "State2D.hpp"

namespace PathPlanningLib
{
    namespace Tests
    {
        void AStarTest::TestAStar()
        {
            std::cout << "AStar Test:" << std::endl;

            State2D::SetObstacles(std::unordered_set<State2D>
            ({
                State2D(1,3),
                State2D(0,3),
                State2D(-1,3)
            }));

            State2D::SetActions(std::vector<std::shared_ptr<Action2D>>
            ({
                std::make_shared<Action2D>(-1, 0, 1.0),
                std::make_shared<Action2D>(1, 0, 1.0),
                std::make_shared<Action2D>(0, 1, 1.0),
                std::make_shared<Action2D>(0, -1, 1.0)
             }));
            
            AStar<State2D, Action2D> planner;
            std::vector<std::shared_ptr<Connection<State2D, Action2D>>> path;

            bool success = planner.PlanPath(
                &path,
                std::make_shared<const State2D>(0, 0),
                std::make_shared<const State2D>(0, 7)
            );

            if (!success)
            {
                std::cout << "No path found" << std::endl;
            }

            for (std::shared_ptr<Connection<State2D, Action2D>> step : path)
            {
                std::shared_ptr<const Action2D> action = step->GetEdge();
                std::shared_ptr<const State2D> state = step->GetVertex();
                std::cout << "State:\t" << state->GetX() << "," << state->GetY() << std::endl;
                std::cout << "Action:\t" << action->GetMoveX() << "," << action->GetMoveY() << std::endl;
            }

            std::cout << std::endl;
        }
    }
}