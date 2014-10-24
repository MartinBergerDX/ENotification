#pragma once

#include "EObject.h"

class EComponent : public EObject
{
public:
    EComponent();
    virtual ~EComponent();

    virtual void initialize() = 0;
    virtual void destroy() = 0;
};

