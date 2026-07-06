#pragma once

#include <memory>
#include <unordered_map>
#include <vector>

#include "StateStatus.hpp"
#include "Connection.hpp"
#include "Node.hpp"

namespace PathPlanningLib
{
    template <class V, class E> class Node;

    template <class V, class E> class PathPlanner
    {
    public:
        PathPlanner() {}

        virtual ~PathPlanner(){};

        virtual bool PlanPath(std::vector<std::shared_ptr<Connection<V, E>>> *path, std::shared_ptr<const V> start, std::shared_ptr<const V> goal) = 0;

        virtual float CalculateCost(Node<V, E>& parent, const std::shared_ptr<const V>& vertex, const std::shared_ptr<const E>& edge) const = 0;   
    };
}