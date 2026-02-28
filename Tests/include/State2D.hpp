#pragma once

#include <IState.hpp>
#include <IAction.hpp>

#include "Action2D.hpp"

#include <unordered_set>

namespace PathPlanningLib
{
    namespace Tests
    {   //template <class A>
        class State2D : public IState
        {
        public:
            State2D(int x, int y);
            ~State2D();

            bool operator==(const IState& other) const override;
            bool operator!=(const IState& other) const override;
            bool operator==(const State2D& other) const;
            bool operator!=(const State2D& other) const;
            size_t CalculateHash() const override;
            int GetX() const;
            int GetY() const;
            std::vector<std::pair<std::shared_ptr<const IState&>, double>> GetConnections() const override;
            float CalculateHeuristic(const State2D& other) const;

            static void SetObstacles(std::unordered_set<State2D> obstacles);
            static void SetActions(std::unordered_set<Action2D> actions);

        private:
            int m_X;
            int m_Y;
            
            static std::unordered_set<State2D> s_Obstacles;
            static std::unordered_set<Action2D> s_Actions;
        };
    }
}

template<>
struct std::hash<PathPlanningLib::Tests::State2D>
{
    std::size_t operator()(const PathPlanningLib::Tests::State2D& state) const
    {
        return state.CalculateHash();
    }
};