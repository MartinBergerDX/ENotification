#pragma once

// wrapper arpund string representation of notification.
// possibly contains pointer to sender and pointer to user data in form of map.

// class is owner of map, meaning it will delete map's memory on destructor call.
// class is not owner of sender, if any.

#include <iostream>
#include <map>
#include "infrastructure/EObject.h"

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

