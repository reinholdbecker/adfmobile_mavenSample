//
//  AuthenticationContext.h
//  OracleSecurityLib
//
//  Created by Tadashi Enomori on 12/8/11.
//  Copyright 2011 Oracle. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Foundation/Foundation.h>
#import "OracleAuthenticationDefinition.h"
#import "ADFFeature.h"
#import "OMMobileSecurityService.h"

@interface ADFAuthenticationContext : NSObject <OMMobileServiceDelegate>
{
}

typedef enum {
	REMOVE_CREDENTIAL           = 0, // Remove credenatial from shared credential store
	ADD_CREDENTIAL,                  // Add credential to shared credential store
}SharedCredentialCommand;

typedef enum {
    HTTP_SUCCESS                = 200,
    HTTP_MOVED_TEMP             = 302
}HTTPResponseCode;

typedef enum {
    HTTP_DEFAULT_PORT           = 80,
    HTTPS_DEFAULT_PORT          = 443
}DefaultHTTPPortNumber;

@property (nonatomic, assign)       BOOL isOnline;
@property (nonatomic, readwrite)    NSInteger retries;
@property (nonatomic, retain)       id authProvider;
@property (nonatomic, retain)       NSString* loginFeatureId;
@property (nonatomic, retain)       id listener;
@property (nonatomic, retain)       id<OracleAuthenticationDefinition> connDef;
@property (nonatomic, retain)       NSString* credentialStoreKey;
@property (nonatomic, retain)       NSString* loginURL;
@property (nonatomic, retain)       NSString* logoutURL;
@property (nonatomic, readwrite)    NSInteger maximumFailureAttempts;
@property (nonatomic, retain)       id<ADFFeature> featureBeingLoggingIn;
@property (nonatomic, retain)       NSString* featureActivationId;
@property (nonatomic, retain)       id currentAuthenticationProvider;
@property (nonatomic, retain)       NSString* currentUsername;
@property (nonatomic, retain)       NSString* currentTenantId;
@property (nonatomic, readwrite)    BOOL resuming;
@property (nonatomic, retain)       NSString* _mode;
@property (nonatomic, retain)       NSString* currentTenantHeaderName;
@property (nonatomic, retain)       NSString* loggedInUsername;

- (BOOL)          isAuthenticated;
- (BOOL)          isAuthenticatedWithId:(NSString*) featureId;
- (BOOL)          isMultiTenantAware;
- (void)          incrementRetryCount;
- (void)          loginWithUsername:(NSString*) username andPassword:(NSString*) password andTenantId:(NSString*) tenantId;
- (void)          logout;
- (void)          shutdownWithArgsWrapper:(NSString*) message;
- (void)          manageLoginCredentialsToSharedCredentialStorage:(SharedCredentialCommand) command authContext:(ADFAuthenticationContext*) authContext key:(NSString*) key;
- (NSString*)     getCompositeCredentialKey;

+ (ADFAuthenticationContext*) getActiveContext;
+ (BOOL)          isApplicationLoginPrompt;
+ (BOOL)          getUserObjects:(id<OracleAuthenticationDefinition>) connectionDef                  
                          andKey:(NSString*)key 
                     andUserName:(NSString*)userNameIn 
                 andUserPassword:(NSString*)userPasswordIn 
             andTenantHeaderName:(NSString*)tenantHeaderName
                     andTenantId:(NSString*)tenantIdIn;
+ (BOOL)          applicationLoginUserName:(NSString*)un andPassword:(NSString*) pw andTenantId:(NSString*) tenentId;
+ (NSString*)     getPostBody:(NSString*)userName 
                andFilterMask:(NSString*)filterMask 
                andRoleFilter:(NSString*)rolesFilterString 
           andPrivilegeFilter:(NSString*)privilegesFilterString;
+ (NSDictionary*) applicationUserRolesAndPrivileges;
+ (NSString*)     getObjectListString:(NSString*) response andNodeName:(NSString*)nodeName;
+ (NSString*)     getRootUsername:(NSString*) userName 
                    andTenantName:(NSString*) tenantName;
+ (void)          validateAuthRequest:(NSString*) userName 
                      andUserPassword:(NSString*) userPassword 
       andCompositeCredentialStoreKey:(NSString*) compositeCredentialStoreKey 
                           andConnDef:(id<OracleAuthenticationDefinition>) connDef; 
@end