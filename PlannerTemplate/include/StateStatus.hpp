#pragma once

namespace PathPlanningLib
{
    namespace PlannerTemplate
    {
        enum StateStatus
        {
            Unexplored = 0,
            Exploring = 1,
            Solved = 2,
        };
    }
}