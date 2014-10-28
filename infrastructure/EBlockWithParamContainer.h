//
//  EBlockWithParamContainer.h
//  Game
//
//  Created by HackPro on 10/24/14.
//
//

// class becomes owner of _userInfo, meaning this class must delete it

#ifndef __Game__EBlockWithParamContainer__
#define __Game__EBlockWithParamContainer__

#include <list>
#include <vector>

#include "infrastructure/EBlock.h"

typedef std::list<float> EBlockTypeList;
typedef std::vector<float> EBlockTypeVector;

typedef void (*EBlockFunctionTypeParamEObjectParamList)(void*, EBlockTypeList *userInfo);
typedef void (*EBlockFunctionTypeParamEObjectParamVector)(void*, EBlockTypeVector *userInfo);

class EBlockWithParamContainer : public EBlock
{
public:
    //EBlockWithParamContainer(EBlockFunctionTypeParamEObjectParamList function, EObject* object, EBlockTypeList *userInfo = 0);
    //EBlockWithParamContainer(EBlockFunctionTypeParamEObjectParamVector function, EObject* object, EBlockTypeVector *userInfo = 0);
    
    EBlockWithParamContainer(EBlockFunctionTypeParamEObjectParamList function, void* object, EBlockTypeList *userInfo = 0);
    EBlockWithParamContainer(EBlockFunctionTypeParamEObjectParamVector function, void* object, EBlockTypeVector *userInfo = 0);
    
    virtual ~EBlockWithParamContainer();
    
    virtual void execute();
    
private:
    EBlockWithParamContainer();
    
    void* _object; // class is not owner of this object, meaning it must not delete it
    
    EBlockFunctionTypeParamEObjectParamList _functionParamEObjectParamList;
    EBlockFunctionTypeParamEObjectParamVector _functionParamEObjectParamVector;
    
    EBlockTypeList *_userInfoList;
    EBlockTypeVector *_userInfoVector;
};

#endif /* defined(__Game__EBlockWithParamContainer__) */
