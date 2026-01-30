#pragma once

#include <memory>

namespace PathPlanningLib
{
    namespace PlannerTemplate
    {
        template <class S, class A> class Connection
        {
        public:
            Connection(const std::shared_ptr<const S>& state, const std::shared_ptr<const A>& action) : m_State(state), m_Action(action)
            {
            }
            
            double GetCost() const
            {
                return m_Action->GetCost() * m_State->GetCostMultiplier();
            }

            std::shared_ptr<const S> GetState() const
            {
                return m_State;
            }

            std::shared_ptr<const A> GetAction() const
            {
                return m_Action;
            }

        private:
            std::shared_ptr<const S> m_State;
            std::shared_ptr<const A> m_Action;
        };
    }
}