#include "Dijkstras.hpp"

namespace PathPlanningLib{
    namespace Implementations{
        template <class S, class A> class AStar : public Dijkstras<S, A>
        {
        public:
            AStar(std::vector<std::shared_ptr<const A>> actions) : Dijkstras<S, A>(actions)
            {
                
            }
            
            bool PlanPath(std::vector<std::shared_ptr<PlannerTemplate::Connection<S, A>>> *path, std::shared_ptr<const S> start, std::shared_ptr<const S> goal) override
            {
                m_Goal = goal;

                return Dijkstras<S, A>::PlanPath(path, start, goal);
            }

            float CalculateCost(PlannerTemplate::Node<S, A>& parent, const std::shared_ptr<const S>& state, const std::shared_ptr<const A>& action) const override
            {
                return parent.GetCost() + parent.GetState()->GetCostMultiplier() * action->GetCost() + state->CalculateHeuristic(*m_Goal);
            }

        private:
            std::shared_ptr<const S> m_Goal;
        };
    }
}