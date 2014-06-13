//
//  ADFUser.h
//  OracleADFmcContainerLib
//
/*
 Copyright (c) 2011 Oracle.
 All rights reserved. 
 */

#import <Foundation/Foundation.h>


/************************************************************************
 * Protocol: ADFUser
 *
 * Purpose: This protocol provides access to user information and provides
 *   services that enable SSO behavior for URLs. 
 *
 * Authors: Created:, 18 May 2011 (Created)
 ************************************************************************/
@protocol ADFUser <NSObject>
/***************************************************************************************
 * Property: getUserId:
 *
 * Purpose: The userid this session is logged in as.
 *
 * Authors: Created: 18 May, 2011 (Created)
 ***************************************************************************************/
-(NSString*) getUserId;
/***************************************************************************************
 * Property: associateUrl:
 *
 * Purpose: This message associates the SSO information with the provided url.  This will
 *   provide access to that URL under the SSO umbrella.
 *
 * Authors: Created: 18 May, 2011 (Created)
 ***************************************************************************************/
-(void) associateUrl:(NSString*)targetUrl;
@end
