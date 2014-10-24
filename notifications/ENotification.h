#pragma once

#include <iostream>
#include <map>
#include "EObject.h"

using std::string;
using std::map;

class ENotification : public EObject
{
public:
	ENotification(string &notificationName, void *sender = NULL, map<string, void *> *userInfo = NULL);
	virtual ~ENotification();

	string _notificationName;

    string name() { return _notificationName; }

private:
	ENotification();
	void initialize(string &notificationName, void *sender = NULL, map<string, void *> *userInfo = NULL);

	void *_sender;
	map<string, void *> *_userInfo;
};

