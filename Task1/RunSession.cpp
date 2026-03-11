
#include <iostream>
#include "SessionContext.h"
#include <memory>

// forward declaration.
class IInputGenerator;
class IScoringRule;
class IRewardRule;
class ShopSystem;

class RunSession
{
private:
    std::unique_ptr<IInputGenerator> inputGen;
    std::unique_ptr<IScoringRule> scoringRule;
    std::unique_ptr<IRewardRule> rewardRule;
    std::unique_ptr<ShopSystem> shopSystem;

    SessionContext context;

public:
public:
    // Constructor untuk Dependency Injection
    RunSession(std::unique_ptr<IInputGenerator> ig,
               std::unique_ptr<IScoringRule> sr,
               std::unique_ptr<IRewardRule> rr,
               std::unique_ptr<ShopSystem> shop)
        : inputGen(std::move(ig)),
          scoringRule(std::move(sr)),
          rewardRule(std::move(rr)),
          shopSystem(std::move(shop)) {}

    void run(); // Implementasi urutan fase di .cpp
};
