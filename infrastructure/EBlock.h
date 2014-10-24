#pragma once

#include <iostream>
#include "EObject.h"

using std::cout;
using std::endl;

//#define E_NOTIFICATION_DEBUG

#if defined(E_NOTIFICATION_DEBUG) && (defined(_DEBUG) || defined(DEBUG))
#define PRINT_FUNCTION do { std::cout << __FUNCTION__ << std::endl; } while (0);
#else
#define PRINT_FUNCTION
#endif

#define E_NOTIFICATION_CENTER

#ifdef E_NOTIFICATION_CENTER
#define E_NOTIFICATION_CENTER_ENABLED 1
#else
#define E_NOTIFICATION_CENTER_ENABLED 0
#endif

typedef void (*EBlockFunctionTypeNoParams)(void);

class EBlock : public EObject
{
public:
	EBlock();
    EBlock(EBlockFunctionTypeNoParams functionNoParams);
    
	virtual ~EBlock();

    EBlockFunctionTypeNoParams getFunctionNoParams();
    virtual void execute();
    
private:
    EBlockFunctionTypeNoParams _functionNoParams;
};

