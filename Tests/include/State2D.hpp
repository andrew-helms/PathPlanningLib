#pragma once

#include <IVertex.hpp>

#include "Action2D.hpp"

#include <unordered_set>

namespace PathPlanningLib
{
    namespace Tests
    {   
        class Action2D;

        class State2D// : public IVertex
        {
        public:
            State2D(int x, int y);
            ~State2D();

            //bool operator==(const IVertex& other) const override;
            //bool operator!=(const IVertex& other) const override;
            bool operator==(const State2D& other) const;
            bool operator!=(const State2D& other) const;
            size_t CalculateHash() const ;
            int GetX() const;
            int GetY() const;
            std::vector<std::pair<std::shared_ptr<const Action2D>, std::shared_ptr<const State2D>>> GetEdges() const;
            float CalculateHeuristic(const State2D& other) const;
            inline double GetCostMultiplier() const { return m_CostMultiplier; }

            static void SetObstacles(std::unordered_set<State2D> obstacles);
            static void SetActions(std::vector<std::shared_ptr<Action2D>> actions);

        private:
            int m_X;
            int m_Y;
            
            static std::unordered_set<State2D> s_Obstacles;
            static std::vector<std::shared_ptr<Action2D>> s_Actions;
            double m_CostMultiplier;
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