#pragma once

#include <algorithm>
#include <memory>
#include <numeric>
#include <vector>

#include "Connection.hpp"

template <class S, class A> class Node
{
public:
    Node()
    {

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

    void PopulateConnections(std::vector<std::shared_ptr<const A>> actions)
    {
        m_Connections.reserve(actions.size());

        std::for_each(actions.begin(), actions.end(), [](std::shared_ptr<const A> action) m_Connections.push_back(std::make_shared<Connection>(action.Apply(m_State), action)));
    }

private:
    std::shared_ptr<const S> m_State;
    std::vector<std::shared_ptr<Connection<S, A>>> m_Connections;
    std::shared_ptr<Connection> m_Parent;
    double m_Cost;
};