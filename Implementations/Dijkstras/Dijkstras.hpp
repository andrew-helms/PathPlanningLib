#pragma once

#include <memory>
#include <queue>

#include "../../PathPlanningLib/PathPlanner.hpp"
#include "../../PathPlanningLib/Node.hpp"

template <class S, class A> class Dijkstras : public PathPlanner<S, A>
{
public:
    Dijkstras(std::vector<std::shared_ptr<const A>> actions) : PathPlanner(actions)
    {

    }

    override bool PlanPath(std::shared_ptr<const S> start, std::shared_ptr<const S> goal);
    
private:
    std::priority_queue<Node<S, A>> m_NodeQueue;
};