#pragma once

#include "StateStatus.hpp"

#include <memory>
#include <unordered_map>
#include <vector>

template <class S, class A> class PathPlanner
{
public:
    PathPlanner(std::vector<std::shared_ptr<const A>> actions){};
    virtual ~PathPlanner(){};

    virtual bool PlanPath(std::shared_ptr<const S> start, std::shared_ptr<const A> goal) = 0;

private:
    std::unordered_map<std::shared_ptr<const S>, StateStatus> m_ExploredStates;
    
};