//
//  ViewController.m
//  Notification
//
//  Created by HackPro on 10/24/14.
//  Copyright (c) 2014 HackPro. All rights reserved.
//

#import "ViewController.h"

#include "EBlock.h"
#include "ENotificationCenter.h"
#include "ENotificationResponder.h"

using namespace std;

void foo1(void)
{
	cout << __FUNCTION__ << endl;
}

void foo2(void)
{
	cout << __FUNCTION__ << endl;
}

void f3()
{
    EBlock *block1 = new EBlock(foo1);
    EBlock *block2 = new EBlock(foo2);
    string notificationName1("not1");
    ENotification notification1(notificationName1);
    string notificationName2("not2");
    ENotification notification2(notificationName2);
    ENotificationResponder responderA;
    
    
    ENotificationCenter center;
    
    center.addNotificationResponder(&responderA, block1, notificationName1);
    center.addNotificationResponder(&responderA, block2, notificationName2);
    
    center.postNotification(notification1);
    center.postNotification(notification2);
    center.removeNotificationResponder(&responderA);
    center.postNotification(notification1);
}

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    f3();
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
