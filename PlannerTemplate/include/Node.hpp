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
            Node(const std::shared_ptr<const S>& state) : m_State(state), m_Cost(0), m_Parent(nullptr) { }

            Node(const std::shared_ptr<const S>& state, Node<S, A> &parent, const std::shared_ptr<const A>& action) : m_State(state)
            {
                m_Parent = std::make_shared<Connection<S, A>>(parent.GetState(), action);
                m_Cost = parent.GetCost() + parent.GetState()->GetCostMultiplier() * action->GetCost();
            }

            ~Node()
            {

            }

            double GetCost() const
            {
                return m_Cost;
            }

            std::shared_ptr<const S> GetState() const
            {
                return m_State;
            }

            std::vector<std::shared_ptr<Connection<S, A>>> GetConnections(std::vector<std::shared_ptr<const A>> actions) const
            {
                std::vector<std::shared_ptr<Connection<S, A>>> connections;
                connections.reserve(actions.size());
                
                for (const std::shared_ptr<const A>& action : actions)
                {
                    connections.push_back(std::make_shared<Connection<S, A>>
                    (
                        action->Apply(m_State),
                        action
                    ));
                }

                // std::for_each(actions.begin(), actions.end(), [connections, this](std::shared_ptr<const A> action)
                // {
                //     connections.push_back(std::make_shared<Connection<S, A>>
                //     (
                //         action->Apply(m_State),
                //         action
                //     ));
                // });

                return connections;
            }

            std::shared_ptr<Connection<S, A>> GetParent() const
            {
                return m_Parent;
            }

            void UpdateParent(Node<S, A> &parent, const std::shared_ptr<const A>& action)
            {
                double newCost = parent.GetCost() + parent.GetState()->GetCostMultiplier() * action->GetCost();

                if (newCost < m_Cost)
                {
                    m_Parent = std::make_shared<Connection<S, A>>(parent.GetState(), action);
                    m_Cost = newCost;
                }
            }

            bool operator<(const Node<S,A>& rhs) const
            {
                return GetCost() < rhs.GetCost();
            }

            bool operator>(const Node<S,A>& rhs) const
            {
                return GetCost() > rhs.GetCost();
            }

        private:
            std::shared_ptr<const S> m_State;
            std::shared_ptr<Connection<S, A>> m_Parent;
            double m_Cost;
        };
    }
}