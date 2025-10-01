#pragma once

#include <memory>

template <class S, class A> class Connection
{
public:
    Connection(std::shared_ptr<const S> state, std::share_ptr<const A> action)
    {
        m_State = state;
        m_Action = action;
    }
    
    double GetCost() 
    {
        return m_Action->GetCost();
    }

    std::shared_ptr<const S> GetState()
    {
        return m_State;
    }

private:
    std::shared_ptr<const S> m_State;
    std::shared_ptr<const A> m_Action;

};