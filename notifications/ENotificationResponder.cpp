#include "notifications/ENotificationResponder.h"
#include "notifications/ENotificationCenter.h"

using namespace std;

// Lifecycle

ENotificationResponder::ENotificationResponder()
{
    if(!E_NOTIFICATION_CENTER_ENABLED) return;
    initialize();
}

ENotificationResponder::~ENotificationResponder()
{
    if(!E_NOTIFICATION_CENTER_ENABLED) return;
    destroy();
}

void ENotificationResponder::initialize()
{
    PRINT_FUNCTION
    if(!E_NOTIFICATION_CENTER_ENABLED) return;
}

void ENotificationResponder::destroy()
{
    PRINT_FUNCTION
    if(!E_NOTIFICATION_CENTER_ENABLED) return;

#if 0
    // unregister self from all notifications and release blocks
    map<string, EBlock*>::iterator it = _notifications.begin();
    while (it != _notifications.end())
    {
        unregisterForNotificationName((string)it->first);
        it = _notifications.begin();
    }
#endif
    
    // remove this notification responder from notification center
    ENotificationCenter::defaultCenter()->removeNotificationResponder(this);
}


// Registering for notifications


void ENotificationResponder::registerForNotification(const ENotification &notification, EBlock *block)
{
    PRINT_FUNCTION
    if(!E_NOTIFICATION_CENTER_ENABLED) return;
    
    //_notifications.emplace(notification._notificationName, block);
    _notifications.insert(ENotificationResponderMapElement(notification._notificationName, block));
}

void ENotificationResponder::registerForNotificationName(string &notificationName, EBlock *block)
{
    //_notifications.emplace(notificationName, block);
    _notifications.insert(ENotificationResponderMapElement(notificationName, block));
}

void ENotificationResponder::unregisterForNotification(const ENotification &notification)
{
    PRINT_FUNCTION
    if(!E_NOTIFICATION_CENTER_ENABLED) return;
    
    unregisterForNotificationName(notification._notificationName);
}

// removes notification and deletes block associated with this notification responder
void ENotificationResponder::unregisterForNotificationName(const string &notificationName)
{
    PRINT_FUNCTION
    if(!E_NOTIFICATION_CENTER_ENABLED) return;

    map<string, EBlock*>::iterator iterator = _notifications.find(notificationName);
    if (iterator == _notifications.end())
        return;

    EBlock *block = iterator->second;

    _notifications.erase(notificationName);

    delete block;
}


// Receiving notifications


void ENotificationResponder::receiveNotification(ENotification &notification)
{
    PRINT_FUNCTION
    if(!E_NOTIFICATION_CENTER_ENABLED) return;

    map<string, EBlock*>::iterator iterator = _notifications.find(notification.name());
    if (iterator == _notifications.end()) return;
    
    EBlock *block1 = iterator->second;
    //block1->getFunctionNoParams()();
    block1->execute();
}