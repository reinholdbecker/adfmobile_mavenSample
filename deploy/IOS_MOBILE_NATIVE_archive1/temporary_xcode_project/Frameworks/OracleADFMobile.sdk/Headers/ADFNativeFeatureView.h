//
//  ADFNativeFeatureView.h
//  OracleADFmcContainerLib
//
/*
 Copyright (c) 2011 Oracle.
 All rights reserved. 
 */

#import <Foundation/Foundation.h>
#import "ADFSession.h"

/************************************************************************
 * Protocol: ADFNativeFeatureView
 *
 * Purpose: This protocol should be implemented by the feature views if
 *    they would like a tighter integration with the ADF Mobile Native
 *    framework.  This protocol will allow the Native View to recieve
 *    contextual notifications from the Native Framework.  These include
 *    things like recieving paramters set during activation or 
 *    notifications about prefernce data in the Native Framework. 
 *
 * Authors: Created:, 16 May 2011 (Created)
 ************************************************************************/
@protocol ADFNativeFeatureView <NSObject>
/***************************************************************************************
 * Message: activateFeatureWithParameter:
 *
 * Purpose: This message is sent if the native view is activated and passed a set of
 *   activation paramters.
 *
 * Authors: Created: 16 May, 2011 (Created)
 ***************************************************************************************/
-(void) activateFeatureWithParameter:(NSDictionary*)paramter;
/***************************************************************************************
 * Message: initWithADFSession:
 *
 * Purpose: This initialization message is sent to the object just after the object
 *    has been created.  It provides the ADFSession object that allows the Native view
 *    to interact with the ADF Mobile Native Framework.
 *
 * Authors: Created: 17 May, 2011 (Created)
 ***************************************************************************************/
-(id) initWithADFSession:(id<ADFSession>) session;
@end
