#pragma once
#include "IState.hpp"

class IAction
{
public:
    IAction(){}
    virtual ~IAction(){}
    virtual std::shared_ptr<const IState> Apply(std::shared_ptr<const IState> state) = 0;
    double GetCost();

private:
    double m_Cost;
};