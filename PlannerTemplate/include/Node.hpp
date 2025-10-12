#pragma once

#include <algorithm>
#include <memory>
#include <numeric>
#include <vector>

#include "Connection.hpp"

namespace PathPlanningLib
{
    namespace PlannerTemplate
    {
        template <class S, class A> class Node
        {
        public:
            Node(std::shared_ptr<const S> state, double cost)
            {
                m_State = state;
                m_Cost = cost;
            }

            ~Node()
            {

            }

            double GetCost()
            {
                return m_Cost;
            }

            std::shared_ptr<const S> GetState()
            {
                return m_State;
            }

            std::vector<std::shared_ptr<Connection<S, A>>> GetConnections(std::vector<std::shared_ptr<const A>> actions)
            {
                std::vector<std::shared_ptr<Connection<S, A>>> connections(actions.size());

                std::for_each(actions.begin(), actions.end(), [](std::shared_ptr<const A> action) connections.push_back(std::make_shared<Connection>(action.Apply(m_State), action)));

                return connections;
            }

            bool operator<(Node<S,A> const& lhs, Node<S,A> const& rhs)
            {
                return lhs.GetCost() < rhs.GetCost();
            }

        private:
            std::shared_ptr<const S> m_State;
            std::vector<std::shared_ptr<Connection<S, A>>> m_Connections;
            std::shared_ptr<Connection> m_Parent;
            double m_Cost;
        };
    }
}