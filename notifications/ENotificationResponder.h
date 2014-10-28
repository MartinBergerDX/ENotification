#ifndef E_NOTIFICATION_RESPONDER_H_
#define E_NOTIFICATION_RESPONDER_H_

// represents an object which is registered for some notifications.
// every notification is represented by a string associated with a pointer to a block object.
// block object is wrapper around pointer-to-function.
// objects of this class are meant to be used and reused.

// when destructor is called, object of this class first unregister's itself from notification center,
// then resources of this object are released.

#include "infrastructure/EBlock.h"
#include "infrastructure/EComponent.h"
#include "notifications/ENotification.h"

typedef std::pair<string, EBlock*> ENotificationResponderMapElement;

// Observer class

class ENotificationResponder : public EComponent
{
public:
    ENotificationResponder();
    virtual ~ENotificationResponder();

    virtual void initialize();
    virtual void destroy();

    void receiveNotification(ENotification &notification);

    void registerForNotification(const ENotification &notification, EBlock *block);
    void registerForNotificationName(std::string &notificationName, EBlock *block);

    void unregisterForNotification(const ENotification &notification);
    void unregisterForNotificationName(const std::string &notificationName);

private:
    std::map<std::string, EBlock*> _notifications; // owns blocks, meaning this class must delete them
};

#endif