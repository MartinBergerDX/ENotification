//
//  EBlockParamEObjectParamList.cpp
//  Game
//
//  Created by HackPro on 10/24/14.
//
//

#include "infrastructure/EBlockParamEObjectParamList.h"

EBlockParamEObjectParamList::EBlockParamEObjectParamList(EBlockFunctionTypeParamEObjectParamList function, EObject* object, std::list<int> *userInfo)
{
    _functionParamEObjectParamList = function;
    _object = object;
    _userInfo = userInfo;
}

EBlockParamEObjectParamList::~EBlockParamEObjectParamList()
{
    _functionParamEObjectParamList = 0;
    if (_object) { delete _object; _object = 0; }
    if (_userInfo) { delete _userInfo; _userInfo = 0; }
}

void EBlockParamEObjectParamList::execute()
{
    if (!_functionParamEObjectParamList) return;
    _functionParamEObjectParamList(_object, _userInfo);
}