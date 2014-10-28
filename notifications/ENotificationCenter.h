#ifndef E_NOTIFICATION_CENTER_H_
#define E_NOTIFICATION_CENTER_H_

// class represent a mp of notifications and list of notification responders.
// notification is represented by a string.
// notification responder is represented by his class.

// class is not responsible for state of objects registered as notification responders, meaning it wont manage their memory.

#include <map>
#include <list>
#include <iostream>

#include "infrastructure/EBlock.h"
#include "infrastructure/EObject.h"
#include "notifications/ENotification.h"
#include "notifications/ENotificationResponder.h"

typedef std::list<ENotificationResponder*>                       ENotificationCenterTypeList;
typedef std::map<const string, ENotificationCenterTypeList*>     ENotificationCenterTypeRegisteredResponder;
typedef std::pair<const string, ENotificationCenterTypeList*>    ENotificationCenterMapElement;

class ENotificationCenter : public EObject
{
public:
	ENotificationCenter();
	virtual ~ENotificationCenter();

	static ENotificationCenter* defaultCenter();

	void addNotificationResponder(ENotificationResponder* notificationResponder, EBlock *block, std::string &notificationName);
    void removeNotificationResponder(ENotificationResponder* notificationResponder);
    
    void postNotification(ENotification &notification);
    void postNotificationName(std::string &notificationName, void *sender);
    void postNotificationName(std::string &notificationName, void *sender, std::map<std::string, void *> *userInfo);

    void cleanNotificationCenter();
    
private:
	static ENotificationCenter *s_notificationCenter;

    ENotificationCenterTypeRegisteredResponder _registeredResponders;
};

#endif // E_NOTIFICATION_CENTER_H_