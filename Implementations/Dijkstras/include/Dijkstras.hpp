#pragma once

#include <memory>
#include <queue>
#include <chrono>
#include <algorithm>
#include <iostream>

#include "PathPlanner.hpp"
#include "Node.hpp"
#include "Connection.hpp"
#include "StateStatus.hpp"

namespace PathPlanningLib{
    namespace Implementations{
        template <class S, class A> class Dijkstras : public PlannerTemplate::PathPlanner<S, A>
        {
        public:
            Dijkstras(std::vector<std::shared_ptr<const A>> actions) : PlannerTemplate::PathPlanner<S, A>(actions)
            {
                
            }

            bool PlanPath(std::vector<std::shared_ptr<PlannerTemplate::Connection<S, A>>> *path, std::shared_ptr<const S> start, std::shared_ptr<const S> goal) const override
            {
                // setup
                std::priority_queue<PlannerTemplate::Node<S, A>, std::vector<PlannerTemplate::Node<S, A>>, std::greater<PlannerTemplate::Node<S, A>>> nodeQueue;
                std::unordered_map<S, PlannerTemplate::StateStatus> exploredStates;
                std::unordered_map<S, PlannerTemplate::Node<S, A>> nodeMap;

                PlannerTemplate::Node<S, A> startNode(start);
                nodeQueue.push(startNode);
                nodeMap.emplace(*start, startNode);

                // loop through discovered nodes    
                for (; !nodeQueue.empty(); nodeQueue.pop())
                {
                    PlannerTemplate::Node<S,A> node = nodeQueue.top();

                    exploredStates.emplace(*node.GetState(), PlannerTemplate::StateStatus::Solved);

                    // Check if goal
                    if (*node.GetState() == *goal)
                    {
                        std::shared_ptr<PlannerTemplate::Connection<S, A>> parent = node.GetParent();

                        while (parent != nullptr)
                        {
                            path->push_back(parent);
                            parent = nodeMap.find(*parent->GetState())->second.GetParent();
                        }

                        std::reverse(path->begin(), path->end());

                        return true;
                    }

                    std::vector<std::shared_ptr<PlannerTemplate::Connection<S, A>>> connections = node.GetConnections(this->m_Actions);

                    // loop through connections
                    for (std::shared_ptr<PlannerTemplate::Connection<S, A>> connection : connections)
                    {
                        std::shared_ptr<const S> state = connection->GetState();

                        if (!state->IsValid())
                        {
                            continue;
                        }

                        //check if connection has been found before
                        if (exploredStates.count(*state) == 0)
                        {
                            PlannerTemplate::Node<S, A> connectedNode(state, node, connection->GetAction());
                            exploredStates.emplace(*state, PlannerTemplate::StateStatus::Exploring);
                            nodeMap.emplace(*state, connectedNode);
                            nodeQueue.push(connectedNode);
                        }
                        else if (exploredStates[*connection->GetState()] == PlannerTemplate::StateStatus::Exploring)
                        {
                            nodeMap.find(*state)->second.UpdateParent(node, connection->GetAction());
                        }
                        else
                        {
                        }
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