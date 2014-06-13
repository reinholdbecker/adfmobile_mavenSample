//
//  CVMProperties.h
//  OracleCVMLib
//
/*
 Copyright (c) 2011 Oracle.
 All rights reserved. 
 */

#import <Foundation/Foundation.h>
#import "oraADFPropertiesLoader.h"
/***************************************************************************************
 *
 * Class: CVMProperties
 *
 * Purpose: Used to determine the settings found in the cvm.properties file.
 *
 ***************************************************************************************/

// The _Control_Channel_Internal_ ID is used as a FeatureID when the iOS Native Container Code wants to use the public API to send messages to Java using the Control Channel.
// It allows the bypass of the check for the Control Channel that is normally done to prevent third parties from using the Control Channel in normal use.
// The use of _Control_Channel_Internal_ should be limited to ADF Mobile internal code.
#define _Control_Channel_Internal_ @"_adfmf_internal_control_channel_"

@interface CVMProperties : oraADFPropertiesLoader
{
    
}
// Gets the currently loaded and active CVMProperties
+(CVMProperties*) activeConfiguration;
@property(readonly) BOOL isJavaDebugging;
@property(readonly) BOOL isJavaScriptDebugging;
@property(readonly) int debugPort;
@property(readonly) NSArray* arguments;
// Feature debug information
-(NSNumber*) getFeatureJavaScriptDebugPort:(NSString*)featureId;
-(BOOL) isFeatureDebuggingJavaScript:(NSString*)featureId;
@end
