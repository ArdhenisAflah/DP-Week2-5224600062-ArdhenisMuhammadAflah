
#include <iostream>
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
};
