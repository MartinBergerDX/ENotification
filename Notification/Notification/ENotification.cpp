#include "ENotification.h"


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
}

void ENotification::initialize(string &notificationName, void *sender, map<string, void *> *userInfo)
{
	_notificationName = notificationName;
	_sender = sender;
	_userInfo = userInfo;
}