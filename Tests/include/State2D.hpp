#pragma once

#include <IState.hpp>
#include <IAction.hpp>

#include <unordered_set>

namespace PathPlanningLib
{
    namespace Tests
    {
        class State2D : public PlannerTemplate::IState
        {
        public:
            State2D(int x, int y);
            ~State2D();

            bool operator==(const PlannerTemplate::IState& other) const override;
            bool operator!=(const PlannerTemplate::IState& other) const override;
            bool operator==(const State2D& other) const;
            bool operator!=(const State2D& other) const;
            size_t CalculateHash() const override;
            int GetX() const;
            int GetY() const;
            bool IsValid() const override;
            static void SetObstacles(std::unordered_set<State2D> obstacles);

        private:
            int m_X;
            int m_Y;
            
            static std::unordered_set<State2D> s_Obstacles;
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