#pragma once

#include <memory>

namespace PathPlanningLib
{
    template <class V, class E> class Connection
    {
    public:
        Connection(const std::shared_ptr<const V>& vertex, const std::shared_ptr<const E>& edge) : m_VertexTo(vertex), m_Edge(edge)
        {
        }
        
        double GetCost() const
        {
            return m_Edge->GetCost() * m_VertexTo->GetCostMultiplier();
        }

        std::shared_ptr<const V> GetVertex() const
        {
            return m_VertexTo;
        }

        std::shared_ptr<const E> GetEdge() const
        {
            return m_Edge;
        }

    private:
        std::shared_ptr<const V> m_VertexTo;
        std::shared_ptr<const E> m_Edge;
    };    
}