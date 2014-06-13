//
//  oraADFSession.h
//  OracleADFmcContainerLib
//
/*
 Copyright (c) 2011 Oracle.
 All rights reserved. 
 */

#import <Foundation/Foundation.h>
#import "oraADFBase.h"
#import "oraADFContainerDelegate.h"
#import "oraADFPlatformDelegate.h"
#import "OracleIdentityConnect.h"
#import "oraADFSettings.h"
#import "ADFSession.h"
#import "ADFFeatures.h"
#import "ADFUser.h"
#import "OracleIdentityLogSink.h"
@class oraADFUser;
@class oraADFDevice;
@class oraADFHardware;
@class OracleAdfmfApplication;
@class OracleSecurityProvider;
@class OracleUserObject;
@class ADFShellDelegator;
/************************************************************************
 * Class: oraADFSession
 *
 * Purpose: This is a class representation of the Oracle ADF Session.
 *   Instances of this object provide access to the User, the Device
 *   and the Hardware instances for this session.
 *
 * Authors: Created:, 11 April 2011 (Created)
 ************************************************************************/
@interface oraADFSession : oraADFBase <ADFSession, OracleIdentityLogSink>
{
    oraADFUser* userInstance;
    oraADFDevice* device;
    oraADFHardware* hardware;
    id<oraADFContainerDelegate> containerDelegate;
    id<oraADFPlatformDelegate> platformDelegate;
    id<OracleIdentityConnect> securityProvider;
    id<oraADFSettings> settings;
    BOOL _languageInfoDumped;
}
// The Determins if this session has a springboard 
@property(readonly) BOOL hasSpringboard;
// The Oracle Settings Object this session will use 
@property(nonatomic,readonly) id<oraADFSettings> settings;
// The Oracle Security Provider this session will use 
@property(nonatomic,readonly) id<OracleUserObject> userObject;
// The Oracle Security Provider this session will use 
@property(nonatomic,readonly) id<OracleIdentityConnect> securityProvider;
// The platform delegate that should be used 
@property(nonatomic,retain) id<oraADFPlatformDelegate> platformDelegate;
// The container delegate that should be used 
@property(nonatomic,retain) id<oraADFContainerDelegate> containerDelegate;
// The user representation for this session
@property(readonly) oraADFUser* internalUser;
// The device representation for this session
@property(nonatomic,readonly) oraADFDevice* device;
// The hardware representation for this session
@property(nonatomic,readonly) oraADFHardware* hardware;
// The container data for this session
@property(nonatomic,readonly) OracleAdfmfApplication* container;
// Notifies the session that the application is ready
- (void) applicationReady;
// Tests the condition - True is fulfilled and fals if not
- (BOOL) testCondtionWithProperty:(NSString*)propertyName withValue:(NSString*)testCondition andOperator:(NSString*)testOperator;
// Get the active session for this app instance
+ (oraADFSession*) getActiveSession;
// Indicates if the configuration completely loaded
- (BOOL) isConfigurationLoadComplete;
+ (BOOL) isConfigurationLoadComplete;
// Gets the shel delegator for this application instance
+(ADFShellDelegator*) getActiveShellDelegator;
// Associates teh cookies for the active session with the web view
-(void) associateSession:(NSString*)newUrl;
// Internationalizes the phrase and returns the new value
// UNIMPLEMENTED - Just returns the passed in resourceKey
- (NSString*) internationalize:(NSString*)resourceKey withContextPrefix:(NSString*) contextPrefix;
- (NSString*) internationalize:(NSString*)resourceKey;
// ADFSession protocol implementation
@property (readonly)id<ADFUser> user;
@property (readonly)id<ADFFeatures> features;
- (NSArray*) getPreferences;
@end
