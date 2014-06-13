//
//  ADFMobileCommand.h
//  OracleADFmcContainerLib
//
/*
 Copyright (c) 2011 Oracle.
 All rights reserved. 
 */

#import <Foundation/Foundation.h>
#import "oraCDVPluginContainerSide.h"
#import "oraADFSession.h"
@class OracleAdfmfFeature;
@class oraADFBase;
/************************************************************************
 * Available Error Codes for ADFMobile
 *
 * Authors: Created:, 27 April 2011 (Created)
 ************************************************************************/
enum ADFMobileError {
	NO_ERROR = 0,
	UNKNOWN_ERROR = 1,
	INVALID_ARGUMENT_ERROR = 2,
	INVALID_FEATURE_NOT_FOUND_ERROR = 3,
	INVALID_ACTIVATION_FUNCTION_ERROR = 4,
	INVALID_FEATURE_HAS_NO_IMAGE_ERROR = 5,
};
typedef NSUInteger ADFMobileError;
/************************************************************************
 * Class: ADFMobileCommand
 *
 * Purpose: This is the base class for all the ADF Mobile PhoneGap 
 *   commands.
 *
 * Authors: Created:, 27 April 2011 (Created)
 ************************************************************************/
@interface ADFMobileCommand : oraCDVPluginContainerSide 
{
}
// Gets the feature id for ADFFeature associated with this command
@property (nonatomic, readonly) NSString* featureId;
// The session object for this command
@property (nonatomic, readonly) oraADFSession* session; 
// The feature associated with this command
@property (nonatomic, readonly) OracleAdfmfFeature* associatedFeature; 
// Sends JavaScript to the attached WebView
- (void) sendJavaScriptToWebView:(NSString*) jsString;
// Sends the JAvaScript to the attached WebView unless the errCode has
// a non-NO_ERROR value...If that is case sends the error to the specifed
// error callback.
- (void) sendJavaScriptToWebView:(NSString*) jsString andCheckErrorCode:(ADFMobileError) errCode withErrorCallback:(NSString*) errCallback;
// Reports the error using the specified callback
- (void) reportErrorInJavaScript:(ADFMobileError)errCode withErrorCallback:(NSString*) errCallback;
// Sets the name of the function to be used for activation callback
- (void) setActivationCallback:(NSString*)callbackFunctionName;
- (void) sendErrorToWebView:(NSException*) error;
@end
