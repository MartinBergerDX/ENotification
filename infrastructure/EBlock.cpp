#include "infrastructure/EBlock.h"


EBlock::EBlock()
{
    PRINT_FUNCTION
    _functionNoParams = 0;
}

EBlock::EBlock(EBlockFunctionTypeNoParams functionNoParams)
{
    PRINT_FUNCTION
    _functionNoParams = functionNoParams;
}

EBlock::~EBlock()
{
    PRINT_FUNCTION
}

EBlockFunctionTypeNoParams EBlock::getFunctionNoParams()
{
    PRINT_FUNCTION
    return _functionNoParams;
}

void EBlock::execute()
{
    if (!_functionNoParams) return;
    _functionNoParams();
}