//
//  EBlockWithParamContainer.cpp
//  Game
//
//  Created by HackPro on 10/24/14.
//
//

#include "infrastructure/EBlockWithParamContainer.h"

/*EBlockWithParamContainer::EBlockWithParamContainer(EBlockFunctionTypeParamEObjectParamList function, EObject* object, EBlockTypeList *userInfo)
{
    _functionParamEObjectParamList = function;
    _functionParamEObjectParamVector = NULL;
    _object = object;
    _userInfoList = userInfo;
}

EBlockWithParamContainer::EBlockWithParamContainer(EBlockFunctionTypeParamEObjectParamVector function, EObject* object, EBlockTypeVector *userInfo)
{
    _functionParamEObjectParamList = NULL;
    _functionParamEObjectParamVector = function;
    _object = object;
    _userInfoVector = userInfo;
}*/

EBlockWithParamContainer::EBlockWithParamContainer(EBlockFunctionTypeParamEObjectParamList function, void* object, EBlockTypeList *userInfo)
{
    _functionParamEObjectParamList = function;
    _userInfoList = userInfo;
    
    _functionParamEObjectParamVector = NULL;
    _userInfoVector = NULL;
    
    _object = object;
}

EBlockWithParamContainer::EBlockWithParamContainer(EBlockFunctionTypeParamEObjectParamVector function, void* object, EBlockTypeVector *userInfo)
{
    _functionParamEObjectParamList = NULL;
    _userInfoList = NULL;
    
    _functionParamEObjectParamVector = function;
    _userInfoVector = userInfo;
    
    _object = object;
}

EBlockWithParamContainer::~EBlockWithParamContainer()
{
    _functionParamEObjectParamList = 0;
    _functionParamEObjectParamVector = 0;
    
    if (_userInfoList) { delete _userInfoList; _userInfoList = 0; }
    if (_userInfoVector) { delete _userInfoVector; _userInfoVector = 0; }
    
    _object = 0; // class is not owner of this object, must not delete it
}

void EBlockWithParamContainer::execute()
{
    if (_functionParamEObjectParamList)
    {
        _functionParamEObjectParamList(_object, _userInfoList);
    }
    
    if (_functionParamEObjectParamVector)
    {
        _functionParamEObjectParamVector(_object, _userInfoVector);
    }
}