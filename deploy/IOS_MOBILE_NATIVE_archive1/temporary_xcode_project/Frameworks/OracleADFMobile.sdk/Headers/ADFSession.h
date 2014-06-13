//
//  ADFSession.h
//  OracleADFmcContainerLib
//
/*
 Copyright (c) 2011 Oracle.
 All rights reserved. 
 */

#import <Foundation/Foundation.h>
#import "ADFUser.h"
#import "ADFFeatures.h"
#import "ADFLogLevel.h"

@class oraADFLogger;
/************************************************************************
 * Protocol: ADFSession
 *
 * Purpose: This protocol provides a definition of the ADFSession object
 *    that is provided to the ADFNativeFeatureView when it is initialized. 
 *
 * Authors: Created:, 16 May 2011 (Created)
 ************************************************************************/
@protocol ADFSession <NSObject>
/***************************************************************************************
 * Message: user:
 *
 * Purpose: This is the user object for this session.  It allows access to information
 *   such as username and provides mechanisms to bind the users session to URL for 
 *   SSO behavior.
 *
 * Authors: Created: 18 May, 2011 (Created)
 ***************************************************************************************/
@property (readonly)id<ADFUser> user;
/***************************************************************************************
 * Message: features:
 *
 * Purpose: This is the features object for this session.  It allows access to services
 *    that manipulate the Navigation Bar and navigate to other features
 *
 * Authors: Created: 18 May, 2011 (Created)
 ***************************************************************************************/
@property (readonly)id<ADFFeatures> features;
/***************************************************************************************
 * Message: getPreferences:
 *
 * Purpose: This message lets you get the preferences for this session.
 *
 * Authors: Created: 18 May, 2011 (Created)
 ***************************************************************************************/
- (NSArray*) getPreferences;
/***************************************************************************************/

@end
