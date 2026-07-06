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
#include "State2D.hpp"

namespace PathPlanningLib{
    template <class V, class E>
    class Dijkstras : public PathPlanner<V, E>
    {
    public:
        Dijkstras() : PathPlanner<V, E>()
        {
            
        }

        virtual bool PlanPath(std::vector<std::shared_ptr<Connection<V, E>>> *path, std::shared_ptr<const V> start, std::shared_ptr<const V> goal) override
        {
            // setup
            std::priority_queue<Node<V, E>, std::vector<Node<V, E>>, std::greater<Node<V, E>>> nodeQueue;
            std::unordered_map<V, StateStatus> exploredVertices;
            std::unordered_map<V, Node<V, E>> nodeMap;

            Node<V, E> startNode(start, this);
            nodeQueue.push(startNode);
            nodeMap.emplace(*start, startNode);

            // loop through discovered nodes    
            for (; !nodeQueue.empty(); nodeQueue.pop())
            {
                Node<V, E> node = nodeQueue.top();

                exploredVertices.emplace(*node.GetVertex(), StateStatus::Solved);

                // Check if goal
                if (*node.GetVertex() == *goal)
                {
                    std::shared_ptr<Connection<V, E>> parent = node.GetParent();

                    while (parent != nullptr)
                    {
                        path->push_back(parent);
                        parent = nodeMap.find(*parent->GetVertex())->second.GetParent();
                    }

                    std::reverse(path->begin(), path->end());

                    return true;
                }

                std::vector<std::shared_ptr<Connection<const V, const E>>> connections = node.GetConnections();

                // loop through connections
                for (std::shared_ptr<Connection<const V, const E>> connection : connections)
                {
                    std::shared_ptr<const V> vertex = connection->GetVertex();

                    //check if connection has been found before
                    if (exploredVertices.count(*vertex) == 0)
                    {
                        Node<V, E> connectedNode(vertex, node, connection->GetEdge(), this);
                        exploredVertices.emplace(*vertex, StateStatus::Exploring);
                        nodeMap.emplace(*vertex, connectedNode);
                        nodeQueue.push(connectedNode);
                    }
                    else if (exploredVertices[*connection->GetVertex()] == StateStatus::Exploring)
                    {
                        nodeMap.find(*vertex)->second.UpdateParent(node, connection->GetEdge());
                    }
                    else
                    {
                    }
                }

            }

            return false;
        }

        virtual float CalculateCost(Node<V, E>& parent, const std::shared_ptr<const V>& vertex, const std::shared_ptr<const E>& edge) const override
        {
            return parent.GetCost() + parent.GetVertex()->GetCostMultiplier() * edge->GetCost();
        }

        // bool override PlanPath(std::vector<std::shared_ptr<PlannerTemplate::Connection>> *path, std::shared_ptr<const S> start, std::shared_ptr<const S> goal, const std::chrono::duration<float>& timeout)
        // {
                // Call PlanPath with timeout
        // }
        
    private:
    };
}