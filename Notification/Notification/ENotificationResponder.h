#ifndef E_NOTIFICATION_RESPONDER_H_
#define E_NOTIFICATION_RESPONDER_H_

#include "EComponent.h"
#include "ENotification.h"
#include "EBlock.h"

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
    void registerForNotificationName(string &notificationName, EBlock *block);

    void unregisterForNotification(const ENotification &notification);
    void unregisterForNotificationName(const string &notificationName);

private:
    map<string, EBlock*> _notifications;
};

#endif