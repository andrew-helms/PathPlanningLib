#include "Dijkstras.hpp"

namespace PathPlanningLib{
    template <class V, class E> class AStar : public Dijkstras<V, E>
    {
    public:
        AStar() : Dijkstras<V, E>()
        {
            
        }
        
        bool PlanPath(std::vector<std::shared_ptr<Connection<V, E>>> *path, std::shared_ptr<const V> start, std::shared_ptr<const V> goal) override
        {
            m_Goal = goal;

            return Dijkstras<V, E>::PlanPath(path, start, goal);
        }

        float CalculateCost(Node<V, E>& parent, const std::shared_ptr<const V>& vertex, const std::shared_ptr<const E>& edge) const override
        {
            return parent.GetCost() + parent.GetVertex()->GetCostMultiplier() * edge->GetCost() + vertex->CalculateHeuristic(*m_Goal);
        }

    private:
        std::shared_ptr<const V> m_Goal;
    };
    
}