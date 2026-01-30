#pragma once

#include <memory>
#include <unordered_map>
#include <vector>

#include "StateStatus.hpp"
#include "Connection.hpp"
#include "Node.hpp"

namespace PathPlanningLib
{
    namespace PlannerTemplate
    {
        template <class S, class A> class Node;

        template <class S, class A> class PathPlanner
        {
        public:
            PathPlanner(std::vector<std::shared_ptr<const A>> actions)
            {
                m_Actions = actions;
            }

            virtual ~PathPlanner(){};

            virtual bool PlanPath(std::vector<std::shared_ptr<Connection<S, A>>> *path, std::shared_ptr<const S> start, std::shared_ptr<const S> goal) = 0;

            virtual float CalculateCost(Node<S, A>& parent, const std::shared_ptr<const S>& state, const std::shared_ptr<const A>& action) const = 0;

        protected:
            std::vector<std::shared_ptr<const A>> m_Actions;            
        };
    }
}