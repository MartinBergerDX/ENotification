//
//  EBlockParamEObjectParamList.h
//  Game
//
//  Created by HackPro on 10/24/14.
//
//

// class becomes owner of _object and _userInfo, meaning this class must delete them

#ifndef __Game__EBlockParamEObjectParamList__
#define __Game__EBlockParamEObjectParamList__

#include <list>

#include "infrastructure/EBlock.h"

typedef void (*EBlockFunctionTypeParamEObjectParamList)(EObject*, std::list<int> *userInfo);

class EBlockParamEObjectParamList : public EBlock
{
public:
    EBlockParamEObjectParamList(EBlockFunctionTypeParamEObjectParamList function, EObject* object, std::list<int> *userInfo = 0);
    virtual ~EBlockParamEObjectParamList();
    
    virtual void execute();
    
private:
    EBlockFunctionTypeParamEObjectParamList _functionParamEObjectParamList;
    EObject* _object;
    std::list<int> *_userInfo;
};

#endif /* defined(__Game__EBlockParamEObjectParamList__) */
