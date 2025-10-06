#pragma once

#include <vector>
#include <memory>

#include "IAction.hpp"

class IState
{
public:
    IState(){}
    virtual ~IState(){}
    virtual bool IsValid() = 0;

    virtual bool operator==(const IState& other) = 0;
    virtual std::size_t CalculateHash() const = 0;    
};

template<>
struct std::hash<IState>
{
    std::size_t operator()(const IState& state)
    {
        return state.CalculateHash();
    }
};