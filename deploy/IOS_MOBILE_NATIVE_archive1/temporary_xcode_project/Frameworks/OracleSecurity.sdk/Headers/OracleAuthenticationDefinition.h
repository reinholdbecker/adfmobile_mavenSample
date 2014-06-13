//
//  OracleAuthenticationDefinition.h
//  OracleSecurityLib
//
//  Created by Eric Jumper on 12/14/11.
//  Copyright (c) 2011 Oracle. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol OracleAuthenticationDefinition <NSObject>
@property (nonatomic, retain) NSString* credentialStoreKey;
@property (nonatomic, assign) NSInteger max_retries;
@property (nonatomic, assign) NSInteger maxFailuresBeforeCredentialCleared;
@property (nonatomic, assign) NSInteger idleTimeout;
@property (nonatomic, assign) NSInteger sessionTimeout;
@property (nonatomic, retain) NSString* loginURL;
@property (nonatomic, retain) NSString* logoutURL;
@property (nonatomic, retain) NSMutableArray* cookieNames;
@property (nonatomic, retain) NSString* privilegesFilter;
@property (nonatomic, retain) NSString* rolesFilter;
@property (nonatomic, retain) NSString* accessControl; 
@property (nonatomic, retain) NSString* realm;
@property (nonatomic, assign) BOOL      injectBasicAuthHeader;
@property (nonatomic, assign) BOOL      isMultiTenantAware; 
@property (nonatomic, assign) BOOL      isCookieInjectionRequested;
@property (nonatomic, retain) NSString* multiTenantHeaderName; 
@end
