#ifndef E_NOTIFICATION_CENTER_H_
#define E_NOTIFICATION_CENTER_H_

#include <map>
#include <forward_list>
#include <iostream>

#include "EBlock.h"
#include "ENotification.h"
#include "ENotificationResponder.h"
#include "EObject.h"

using namespace std;

typedef forward_list<ENotificationResponder*> ENotificationCenterTypeListOfResponders;
typedef map<const string, ENotificationCenterTypeListOfResponders*> ENotificationCenterTypeRegisteredResponder;

class ENotificationCenter : public EObject
{
public:
	ENotificationCenter();
	virtual ~ENotificationCenter();

	static ENotificationCenter* defaultCenter();

	void addNotificationResponder(ENotificationResponder* notificationResponder, EBlock *block, string &notificationName);
    void removeNotificationResponder(ENotificationResponder* notificationResponder);
    
    void postNotification(ENotification &notification);
    void postNotificationName(string &notificationName, void *sender);
    void postNotificationName(string &notificationName, void *sender, map<string, void *> *userInfo);

    void cleanNotificationCenter();
    
private:
	static ENotificationCenter *s_notificationCenter;

    ENotificationCenterTypeRegisteredResponder _registeredResponders;
};

#endif // E_NOTIFICATION_CENTER_H_