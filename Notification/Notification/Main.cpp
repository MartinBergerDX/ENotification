#include <iostream>
#include "ENotificationCenter.h"

#include "EBlock.h"
#include "ENotificationCenter.h"
#include "ENotificationResponder.h"

using namespace std;

void foo(void)
{
	cout << __FUNCTION__ << endl;
}

void f1()
{
    EBlock *block = new EBlock(foo);
    string notificationName("not1");

    ENotification notification(notificationName);

    ENotificationResponder responder;
    responder.registerForNotification(notification, block);

    responder.receiveNotification(notification);
}

void f2()
{
    EBlock *block = new EBlock(foo);
    string notificationName("not1");

    ENotification notification(notificationName);

    ENotificationResponder responder;
    //responder.registerForNotification(notification, block);

    //responder.receiveNotification(notification);

    ENotificationCenter center;

    center.addNotificationResponder(&responder, block, notificationName);

    center.postNotification(notification);
}

int main2(void)
{
    f2();

	int a = 0;
	cin >> a;
	return 0;
}