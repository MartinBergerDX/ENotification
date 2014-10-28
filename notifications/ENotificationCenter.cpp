#include <cstdio>
#include <cstring>
#include <cassert>
#include "notifications/ENotificationCenter.h"

ENotificationCenter* ENotificationCenter::s_notificationCenter = NULL;

ENotificationCenter* ENotificationCenter::defaultCenter()
{
    if(!E_NOTIFICATION_CENTER_ENABLED) return 0;
    
	if (s_notificationCenter) return s_notificationCenter;
	s_notificationCenter = new ENotificationCenter();
	return s_notificationCenter;
}

ENotificationCenter::ENotificationCenter()
{
}

ENotificationCenter::~ENotificationCenter()
{
    PRINT_FUNCTION
    if(!E_NOTIFICATION_CENTER_ENABLED) return;
    
    // unregister all notificaton responders
    
    ENotificationCenterTypeRegisteredResponder::iterator respondersIterator = _registeredResponders.begin();
    while (respondersIterator != _registeredResponders.end())
    {
        ENotificationCenterTypeList *list = respondersIterator->second;
        while (!list->empty())
        {
            ENotificationResponder *notificationResponder = list->front();
            removeNotificationResponder(notificationResponder);
        }
        
        delete list;
        _registeredResponders.erase(respondersIterator); // invalidates current iterator
        
        respondersIterator = _registeredResponders.begin();
    }
}

void ENotificationCenter::cleanNotificationCenter()
{
    if(!E_NOTIFICATION_CENTER_ENABLED) return;
    
    ENotificationCenterTypeRegisteredResponder::iterator respondersIterator = _registeredResponders.begin();
    while (respondersIterator != _registeredResponders.end())
    {
        ENotificationCenterTypeList *notificationResponderList = respondersIterator->second;
        
        if (notificationResponderList->empty())
        {
            delete notificationResponderList;
            _registeredResponders.erase(respondersIterator);
            respondersIterator = _registeredResponders.begin();
            continue;
        }
        
        respondersIterator++;
    }
}

// if notification responder tries to register for one notification more than once, attempt fails
void ENotificationCenter::addNotificationResponder(ENotificationResponder* notificationResponder, EBlock *block, string &notificationName)
{
    if(!E_NOTIFICATION_CENTER_ENABLED) return;
    
    if (notificationResponder == NULL) return;
    if (block == NULL) return;
    if (notificationName.length() == 0) return;

    // for one notification, only one block
    notificationResponder->registerForNotificationName(notificationName, block);

    // initialize list for this notification if not initialized

    // map<const string, forward_list<ENotificationResponder*>*>
    ENotificationCenterTypeRegisteredResponder::iterator it = _registeredResponders.find(notificationName);
    ENotificationCenterTypeList *list = 0;

    if (_registeredResponders.find(notificationName) == _registeredResponders.end())
    {
        list = new ENotificationCenterTypeList();
        _registeredResponders.insert(ENotificationCenterMapElement(notificationName, list));
    }
    else
    {
        list = it->second;
    }

    // check if notification responder is already registered for this notification

    for (ENotificationCenterTypeList::iterator listIterator = list->begin(); listIterator != list->end(); ++listIterator)
    {
        if (*listIterator == notificationResponder) return;
    }

    // add notification responder to forward list for this notification

    list->push_front(notificationResponder);
}

// removes notification responder from responder list and call unregister for all notifications he is listening to
// will delete forward list if no element remain
void ENotificationCenter::removeNotificationResponder(ENotificationResponder* notificationResponder)
{
    if(!E_NOTIFICATION_CENTER_ENABLED) return;
    
    ENotificationCenterTypeRegisteredResponder::iterator respondersIterator = _registeredResponders.begin();
    
    while (respondersIterator != _registeredResponders.end())
    {
        //cout << "notification: " << respondersIterator->first << endl;
        
        ENotificationCenterTypeList *list = respondersIterator->second;
        
        // find him and find any notifications he is registered for and unregister
        
        ENotificationCenterTypeList::iterator listIterator = list->begin();
        while (listIterator != list->end())
        {
            if (*listIterator == notificationResponder)
            {
                ((ENotificationResponder*)(*listIterator))->unregisterForNotificationName(respondersIterator->first);
                break; // notification responder can be registered only once for given notification
            }
            
            listIterator++;
        }
        
        // remove notification responder from responder list
        
        list = respondersIterator->second;
        list->remove(notificationResponder); // this removes all instances
        
        // if there is no more notification responders for this notification, delete list
        
        /*if (list->empty())
        {
            delete list;
            _registeredResponders.erase(respondersIterator); // invalidates current iterator
            respondersIterator = _registeredResponders.begin();
            continue;
        }*/
        
        respondersIterator++;
    }
}

void ENotificationCenter::postNotification(ENotification &notification)
{
    if(!E_NOTIFICATION_CENTER_ENABLED) return;
    
#ifdef E_NOTIFICATION_DEBUG
    std::cout << "Posting notification: " << notification._notificationName << std::endl;
#endif
    
    assert(notification.name().length() > 0);

    ENotificationCenterTypeRegisteredResponder::iterator it = _registeredResponders.find(notification.name());
    if (it == _registeredResponders.end()) return;

    // broadcast notification to all notification responders

    ENotificationCenterTypeList *list = it->second;
    assert(list != NULL);

    for (auto listIterator = list->begin(); listIterator != list->end(); ++listIterator)
    {
        ((ENotificationResponder*)(*listIterator))->receiveNotification(notification);
    }
}

void ENotificationCenter::postNotificationName(string &notificationName, void *sender)
{
    if(!E_NOTIFICATION_CENTER_ENABLED) return;
    ENotification notification(notificationName);
    postNotification(notification);
}

void ENotificationCenter::postNotificationName(string &notificationName, void *sender, map<string, void *> *userInfo)
{
    if(!E_NOTIFICATION_CENTER_ENABLED) return;
    ENotification notification(notificationName, NULL, userInfo);
    postNotification(notification);
}