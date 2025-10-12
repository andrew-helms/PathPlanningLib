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
        template <class S, class A> class Dijkstras : public PlannerTemplate::PathPlanner
        {
        public:
            Dijkstras(std::vector<std::shared_ptr<const A>> actions) : PlannerTemplate::PathPlanner<S, A>(actions)
            {
                
            }

            bool PlanPath(std::vector<std::shared_ptr<PlannerTemplate::Connection<const S, const A>>> *path, std::shared_ptr<const S> start, std::shared_ptr<const S> goal) override
            {
                // setup
                std::priority_queue<PlannerTemplate::Node<S, A>> nodeQueue;
                std::unordered_map<const S, PlannerTemplate::StateStatus> exploredStates;

                nodeQueue.push(PlannerTemplate::Node<S, A>(start));

                // loop through discovered nodes
                for (; !nodeQueue.empty(); nodeQueue.pop())
                {
                    PlannerTemplate::Node<S,A> node = nodeQueue.top();

                    std::vector<std::shared_ptr<PlannerTemplate::Connection<S,A>>> connections = node.GetConnections(m_Actions);

                    // loop through connections
                    for (auto connection = connections.begin(); connection != connections.end(); ++connection)
                    {
                        //check if connection has been found before
                        //PlannerTemplate::StateStatus status = exploredStates.contains(connection->GetState()->get()) ? [connection->GetState()->get()] : PlannerTemplate::StateStatus.Unexplored;
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