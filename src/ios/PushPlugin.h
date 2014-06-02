/*
 * JBoss, Home of Professional Open Source.
 * Copyright Red Hat, Inc., and individual contributors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#import <Foundation/Foundation.h>
#import <Cordova/CDV.h>
#import <Cordova/CDVPlugin.h>

@interface PushPlugin : CDVPlugin {
    NSDictionary *notificationMessage;
    BOOL isInline;
}

@property(nonatomic, copy) NSString *callbackId;

@property(nonatomic, strong) NSDictionary *notificationMessage;
@property BOOL isInline;

@property(nonatomic, copy) void (^completionHandler)(UIBackgroundFetchResult);

- (void)register:(CDVInvokedUrlCommand *)command;

- (void)didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;

- (void)didFailToRegisterForRemoteNotificationsWithError:(NSError *)error;

- (void)setNotificationMessage:(NSDictionary *)notification;

- (void)notificationReceived;

- (void)setContentAvailable:(CDVInvokedUrlCommand *)command;

- (void)backgroundFetch:(void (^)(UIBackgroundFetchResult))handler userInfo:(NSDictionary *)userInfo;
@end
