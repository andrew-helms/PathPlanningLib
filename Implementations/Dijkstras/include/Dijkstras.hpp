#pragma once

#include <memory>
#include <queue>
#include <chrono>

#include "PathPlanner.hpp"
#include "Node.hpp"
#include "Connection.hpp"
#include "StateStatus.hpp"

namespace PathPlanningLib{
    namespace Implementations{
        template <class S, class A> class Dijkstras : public PathPlanner<S, A>
        {
        public:
            Dijkstras(std::vector<std::shared_ptr<const A>> actions) : PathPlanner(actions)
            {
                
            }

            bool override PlanPath(std::vector<std::shared_ptr<PlannerTemplate::Connection>> *path, std::shared_ptr<const S> start, std::shared_ptr<const S> goal)
            {
                // setup
                std::priority_queue<Node<S, A>> nodeQueue();
                std::unordered_map<const S, PlannerTemplate::StateStatus> exploredStates();

                nodeQueue.push(Node<S, A>(start));

                // loop through discovered nodes
                for (; !nodeQueue.empty(); nodeQueue.pop())
                {
                    Node<S,A> node = nodeQueue.top();

                    std::vector<std::shared_ptr<Connection<S,A>>> connections = node.GetConnections(m_Actions);

                    // loop through connections
                    for (auto connection = connections.begin(); connection != connections.end(); ++connection)
                    {
                        //check if connection has been found before
                        PlannerTemplate::StateStatus status = exploredStates.contains(connection->GetState()->get()) ? [connection->GetState()->get()] : PlannerTemplate::StateStatus.Unexplored;
                    }

                }

                return false;
            }

            // bool override PlanPath(std::vector<std::shared_ptr<PlannerTemplate::Connection>> *path, std::shared_ptr<const S> start, std::shared_ptr<const S> goal, const std::chrono::duration<float>& timeout)
            // {
                    // Call PlanPath with timeout
            // }
            
        private:
        };
    }
}