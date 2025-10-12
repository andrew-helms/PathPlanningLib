#pragma once

#include <memory>

#include "Node.hpp"

namespace PathPlanningLib
{
    namespace PlannerTemplate
    {
        template <class S, class> class Node;

        template <class S, class A> class Connection
        {
        public:
            Connection(std::shared_ptr<Node<S, A>> node, std::shared_ptr<const A> action)
            {
                m_Node = node;
                m_Action = action;
            }
            
            double GetCost() 
            {
                return m_Action->GetCost() * GetState()->GetCostMultiplier();
            }

            std::shared_ptr<const S> GetState()
            {
                return m_Node->GetState();
            }

        private:
            std::shared_ptr<Node<S, A>> m_Node;
            std::shared_ptr<const A> m_Action;

        };
    }
}