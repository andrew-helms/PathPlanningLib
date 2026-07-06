#pragma once

#include <algorithm>
#include <memory>
#include <numeric>
#include <vector>

#include "Connection.hpp"
#include "PathPlanner.hpp"

namespace PathPlanningLib
{
    template <class V, class E> class PathPlanner;

    template <class V, class E> class Node
    {
    public:
        Node(const std::shared_ptr<const V>& vertex, const PathPlanner<V, E>* planner): m_Vertex(vertex), m_Cost(0), m_Parent(nullptr), m_Planner(planner) { }

        Node(const std::shared_ptr<const V>& vertex, Node<V, E> &parent, const std::shared_ptr<const E>& edge, const PathPlanner<V, E>* planner) : m_Vertex(vertex), m_Planner(planner)
        {
            m_Parent = std::make_shared<Connection<V, E>>(parent.GetVertex(), edge);
            m_Cost = m_Planner->CalculateCost(parent, vertex, edge);
        }

        ~Node()
        {

        }

        double GetCost() const
        {
            return m_Cost;
        }

        std::shared_ptr<const V> GetVertex() const
        {
            return m_Vertex;
        }

        std::vector<std::shared_ptr<Connection<const V, const E>>> GetConnections() const
        {
            std::vector<std::shared_ptr<Connection<const V, const E>>> connections;

            std::vector<std::pair<std::shared_ptr<const E>, std::shared_ptr<const V>>> edges = m_Vertex->GetEdges();

            connections.reserve(edges.size());

            std::for_each(edges.begin(), edges.end(), [&connections](std::pair<std::shared_ptr<const E>, std::shared_ptr<const V>> edge) mutable
            {
                connections.push_back(std::make_shared<Connection<const V, const E>>
                (
                    edge.second,
                    edge.first
                ));
            });

            return connections;
        }

        std::shared_ptr<Connection<V, E>> GetParent() const
        {
            return m_Parent;
        }

        void UpdateParent(Node<V, E> &parent, const std::shared_ptr<const E>& edge)
        {
            double newCost = m_Planner->CalculateCost(parent, m_Vertex, edge);

            if (newCost < m_Cost)
            {
                m_Parent = std::make_shared<Connection<V, E>>(parent.GetVertex(), edge);
                m_Cost = newCost;
            }
        }

        bool operator<(const Node<V, E>& rhs) const
        {
            return GetCost() < rhs.GetCost();
        }

        bool operator>(const Node<V, E>& rhs) const
        {
            return GetCost() > rhs.GetCost();
        }

    private:
        std::shared_ptr<const V> m_Vertex;
        std::shared_ptr<Connection<V, E>> m_Parent;
        const PathPlanner<V, E>* m_Planner;
        double m_Cost;
    };
}