#pragma once
#include "IInputGenerator.h"
#include "IChooseHand.h"
#include <memory>

class StandardInputGenerator : public IInputGenerator
{
private:
    std::unique_ptr<IChooseHand> handChooser; // Objek yang menampung tanggung jawab memilih

public:
    // Constructor menerima interface IChooseHand
    StandardInputGenerator(std::unique_ptr<IChooseHand> chooser);
    TurnInput GenerateInput(int round) override;
};