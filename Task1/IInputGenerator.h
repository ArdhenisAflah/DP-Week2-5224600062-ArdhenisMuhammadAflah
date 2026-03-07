#pragma once

#include <iostream>

class IInputGenerator
{
public:
    virtual int Input() = 0;
    virtual ~IInputGenerator() = default;
};