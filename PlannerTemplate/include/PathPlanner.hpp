#pragma once

#include <memory>
#include <unordered_map>
#include <vector>

#include "StateStatus.hpp"
#include "Connection.hpp"

namespace PathPlanningLib
{
    namespace PlannerTemplate
    {
        template <class S, class A> class PathPlanner
        {
        public:
            PathPlanner(std::vector<std::shared_ptr<const A>> actions)
            {
                m_Actions = actions;
                m_ExploredStates();
            }

            virtual ~PathPlanner(){};

            virtual bool PlanPath(std::vector<std::shared_ptr<Connection>> *path, std::shared_ptr<const S> start, std::shared_ptr<const A> goal) = 0;

        protected:
            std::vector<std::shared_ptr<const A>> m_Actions;            
        };
    }
}