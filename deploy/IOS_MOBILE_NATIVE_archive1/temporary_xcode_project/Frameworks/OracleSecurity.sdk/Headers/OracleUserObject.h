//
//  UserObject.h
//  OracleSecurityLib
//
/*
 Copyright (c) 2011 Oracle.
 All rights reserved. 
 */

#import <Foundation/Foundation.h>
/************************************************************************
 * Protocol: UserObject
 *
 * Purpose: This protocol represents a User Object that is effectively a
 *   token for an Oracle Security Session.
 *
 * 22 April 2011 (Created)
 ************************************************************************/
@protocol OracleUserObject <NSObject>
// Provides the userid that was used to login.
@property (retain) NSString *userid;
// Determines if a user has a specified Role. Returns YES if it does and NO if it does not. 
-(BOOL) hasRole:(NSString*) roleName;
// Determines if a user has a specified Privilege. Returns YES if it does and NO if it does not. 
-(BOOL) hasPrivilege:(NSString*) privilegeName;
@end
