//
//  ApplicationSecurityContext.h
//  OracleSecurityLib
//
//  Created by Tadashi Enomori on 12/15/11.
//  Copyright 2011 Oracle. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OMMobileSecurityConfiguration.h"
#import "OMMobileSecurityService.h"
#import "ADFAuthenticationContext.h"

@interface ApplicationSecurityContext : NSObject
{
    
}

+(ApplicationSecurityContext*) getActiveContext;
+(OMMobileSecurityService*) getMobileSecurityService:(int) maxFailuresBeforeCredentialCleared;

+(NSString*) getloggedInUserName;
+(void) setloggedInUserName:(NSString*)un;

+(NSString*) getCurrentFeatureId;
+(void) setCurrentFeatureId:(NSString*)featureId;

+(NSString*) getCurrentCredentialStoreKey;
+(void) setCurrentCredentialStoreKey:(NSString*)key;

//+(OMMobileSecurityService*) getService;

+(NSString*) getDefaultAuthConnectionName;
+(void) setDefaultAuthConnectionName:(NSString*)s;

+(void) pergeRemoteLoginCredentials;
+(void) addRemoteLoginCredentialKey:(NSString*)key;
+(void) removeRemoteLoginCredentialKey:(NSString*) key;

+(id)   getApplicationAuthContext;
+(void) setApplicationAuthContext:(id)authContext;

+(BOOL) getAuthState;
+(void) setAuthState:(BOOL)state;

+ (ADFAuthenticationContext *) getPausedFeatureAuthContext;
+ (void) setPausedFeatureAuthContext:(ADFAuthenticationContext *) pausedAuthContext;

+ (id<OracleAuthenticationDefinition>) getConnDefForCredentialStoreKey:(NSString*) credentialStoreKey;
+ (void) setConnDefForCredentialStoreKey:(NSString*) key andLoginUrl:(id<OracleAuthenticationDefinition>) connDef;

+(NSString*) getApplicationIdentifier;
+(NSString*) obfuscate:(NSString*) str;
+(NSString*) unobfuscate:(NSString*) str;

@end
