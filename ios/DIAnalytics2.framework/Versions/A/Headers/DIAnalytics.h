//
//  DIAnalytics.h
//  DIAnalytics2_Example
//
//  Created by Simon Richard Giroux on 2021-06-19.
//  Copyright © 2021 Simon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UserNotifications/UserNotifications.h>

@class DIContact;
@class PushReceptionPushModel;

NS_ASSUME_NONNULL_BEGIN

typedef void (^block_success)(id _Nullable object);

@interface DIAnalytics : NSObject

@property (nonatomic, strong) DIContact *contact;
@property (nonatomic, strong) PushReceptionPushModel *pushReceptionsData;

@property (nonatomic, strong) id application;
@property (nonatomic, strong) NSString *applicationId;

@property (nonatomic, strong) NSString *baseUrl;
@property (nonatomic, strong) NSString *apiUrl;

@property (NS_NONATOMIC_IOSONLY, nullable, weak) id <UNUserNotificationCenterDelegate> userNotificationCenterDelegate;

+ (DIAnalytics*)shared;

- (NSString*)libraryVersion;
- (NSString*)getBaseUrl;
- (void)enableLogs;
- (void)startWithApplication:(id)application applicationId:(NSString*)applicationId;
- (void)addPushId:(NSString*)pushId;
- (void)registerForRemoteNotification;
- (void)updateContact:(DIContact*)contactData;
- (void)reset;
- (void)updateContactSync;
- (void)getGuid:(block_success)success;
- (void)didReceiveRemoteNotification:(NSDictionary*)userInfo;
- (void)didReceiveRegistrationToken:(NSString*)fcmToken;

@end

NS_ASSUME_NONNULL_END
