//
//  ADFFeatures.h
//  OracleADFmcContainerLib
//
/*
 Copyright (c) 2011 Oracle.
 All rights reserved. 
 */

#import <Foundation/Foundation.h>
#import "ADFFeature.h"
#define ADFFeatures_RESTART_CONTENT_KEY @"ORACLE_NATIVE_FRAMEWORK_RESTART_CONTENT_ON_ACTIVATE"
#define ADFFeatures_RESTART_CONTENT_VALUE @"true"
/************************************************************************
 * Protocol: ADFFeatures
 *
 * Purpose: This protocol provides a definition of the ADFFeatures object
 *    that is provided to the native views through the ADFSession 
 *    object.
 *
 *    This protocol mimics the API provided in the JavaScript PhoneGap
 *    API for Navigating to features and manipulating the Navigation Bar.
 *
 * Authors: Created:, 19 May 2011 (Created)
 ************************************************************************/
@protocol ADFFeatures <NSObject>
/***************************************************************************************
 * Message: hideNavigationBar:
 *
 * Purpose: This message lets you hide the navigation bar in the Native Framework.
 *
 * Authors: Created: 18 May, 2011 (Created)
 ***************************************************************************************/
- (void) hideNavigationBar;
/***************************************************************************************
 * Message: showNavigationBar:
 *
 * Purpose: This message lets you show the navigation bar in the Native Framework.
 *
 * Authors: Created: 18 May, 2011 (Created)
 ***************************************************************************************/
- (void) showNavigationBar;
/***************************************************************************************
 * Message: showFeature:withParameters:
 *
 * Purpose: These messages let you show a specific feature with a set of paramter.  The
 *    paramter must be a JSON-able NSDictionary.
 *
 * Authors: Created: 19 May, 2011 (Created)
 ***************************************************************************************/
- (void) showFeature:(NSString*)featureId withParameters:(NSDictionary*)paramters;
/***************************************************************************************
 * Message: showSpringboard
 *
 * Purpose: These messages let you show the specified Springboard Feature. 
 *
 * Authors: Created: 9 June, 2011 (Created)
 ***************************************************************************************/
- (void) showSpringboard;

/***************************************************************************************
 * Message: getFeature
 *
 * Purpose: This allows you to get the ADFFeature object identified by the featureId. 
 *
 * Created:4 Oct, 2011
 ***************************************************************************************/
- (id<ADFFeature>) getFeature:(NSString*)featureId;

/***************************************************************************************
 * Message: listAvailable:
 *
 * Purpose: This method lists the available features in the current instance of the 
 *    Native Framework.  This is defined by what is in the adf-mobile.xml and how
 *    the constraints evaluated on load.
 *
 * Authors: Created: 19 May, 2011 (Created)
 ***************************************************************************************/
-(NSArray*) listAvailable;
@end
