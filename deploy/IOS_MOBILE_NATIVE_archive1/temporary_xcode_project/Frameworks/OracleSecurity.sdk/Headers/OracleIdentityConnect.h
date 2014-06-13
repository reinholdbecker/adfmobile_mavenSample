//
//  OracleSecurity.h
//  OracleSecurityLib
//
/*
 Copyright (c) 2011 Oracle.
 All rights reserved. 
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "OracleUserObject.h"
#import "OracleIdentityLogSink.h"

/************************************************************************
 * Protocol: OracleSecurityProvider
 *
 * Purpose: This protocol defines the interaction between a user of this API
 *   and the OracleSecurityProvider object.  There may be many different
 *   implementations under the covers but they will all provide this
 *   interface.
 *
 * 22 April 2011 (Created)
 ************************************************************************/
@protocol OracleIdentityConnect <NSObject>
// Logs into the Oracle Security Provider and returns a UserObject
- (id<OracleUserObject>) loginWithUser:(NSString*)user password:(NSString*)password;
// Connects a URL with a specific User Object
- (void) associateUser:(id<OracleUserObject>)user withUrl:(NSString*)siteURL;
// Disconnects all connections from a specific User Object
- (void) logoutWithUser:(id<OracleUserObject>)user;
// Used to set the lgging sink to be used by this object when
// making log enries.  
- (void) setLogSink:(id<OracleIdentityLogSink>) loggingSink;
@end
