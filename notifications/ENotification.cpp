#include "notifications/ENotification.h"


ENotification::ENotification()
{
    string empty;
	initialize(empty, NULL, NULL);
}

ENotification::ENotification(string &notificationName, void *sender, map<string, void *> *userInfo)
{
	initialize(notificationName, sender, userInfo);
}

ENotification::~ENotification()
{
    _sender = 0; // class is not owner of this object
    if (_userInfo) { delete _userInfo; _userInfo = 0; }
}

void ENotification::initialize(string &notificationName, void *sender, map<string, void *> *userInfo)
{
	_notificationName = notificationName;
	_sender = sender;
	_userInfo = userInfo;
}