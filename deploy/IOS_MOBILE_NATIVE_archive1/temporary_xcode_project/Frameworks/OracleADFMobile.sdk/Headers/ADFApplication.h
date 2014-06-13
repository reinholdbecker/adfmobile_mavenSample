//
//  ADFApplication.h
//  OracleADFmcContainerLib
//
/*
 Copyright (c) 2011 Oracle.
 All rights reserved. 
 */

#import <Foundation/Foundation.h>
#import "ADFSession.h"
#import "ADFFeatureLifecycleListener.h"
#import "ADFApplicationLifecycleListener.h"
#import "ADFTranslation.h"
#define ADFMF_APPLICATION_KEY_PATH_APP_CONTROLLER_FOLDER @"application.appControllerFolder"
#define ADFMF_APPLICATION_KEY_PATH_APP_CONTROLLER_FOLDER_FULL_PATH @"application.appControllerFolder.fullPath"
#define ADFMF_APPLICATION_KEY_PATH_CONFIG_SERVICE_MANAGED_DIRECTORY_FULL_PATH @"application.configService.managedDir.fullPath"
#define ADFMF_APPLICATION_SPRINGBOARD_FEATURE_ID @"application.springboard.featureid"
#define ADFMF_APPLICATION_SHOW_LOGIN_AT_STARTUP @"show-application-login-at-startup"
@interface ADFApplication : NSObject {
    
}
/************************************************************************
 * Method: nativeFrameworkConfigurationLoadIsComplete
 *
 * Purpose: Allows others to determine if the load of the feature 
 *    definitions are complete.  For example, there may be some time
 *    period in the application startup that requires a login prompt
 *    prior to the load of the features.  There will be different 
 *    login logic implemented while the app is logging in than when the
 *    feature logins are occuring.  This method can be called to determine
 *    when those separate 
 *
 * Created: 4 Oct 2011 
 ************************************************************************/
+ (BOOL) nativeFrameworkConfigurationLoadIsComplete;
/************************************************************************
 * Method: cvmLoadIsComplete
 *
 * Purpose: Allows others to determine if the CVM is loaded
 *
 * Created: 29 Mar 2011 
 ************************************************************************/
+ (BOOL) cvmLoadIsComplete;
/************************************************************************
 * Method: setcvmLoadIsComplete
 *
 * Purpose: Allows others to set the CVM load status flag
 *
 * Created: 29 Mar 2011 
 ************************************************************************/
+ (void) setCvmLoadIsComplete:(BOOL) flag;
/************************************************************************
 * Method: getActiveSession
 *
 * Purpose: Gets the active native application session object.
 *
 * Created: 4 Oct 2011 
 ************************************************************************/
+ (id<ADFSession>) getActiveSession;
/************************************************************************
 * Method: registerListener
 *
 * Purpose: Registers a feature lifecycle listener on the active 
 *    application.
 *
 * Created: 4 Oct 2011 
 ************************************************************************/
+ (void) registerListener:(id<ADFFeatureLifecycleListener>) newListener withFeature:(NSString*) featureId;
/************************************************************************
 * v: unregisterListener
 *
 * Purpose: Unregisters a feature lifecycle listener on the active 
 *    application.
 *
 * Created: 4 Oct 2011 
 ************************************************************************/
+ (void) unregisterListener:(id<ADFFeatureLifecycleListener>) newListener withFeature:(NSString*) featureId;
/************************************************************************
 * Method: getActiveAppliction
 *
 * Purpose: Gets the active application instance.
 *
 * Created: 4 Oct 2011 
 ************************************************************************/
+ (ADFApplication*) getActiveAppliction;
/************************************************************************
 * Method: listenerClass
 *
 * Purpose: The name of the Java class that was configured to handle the lifecycle
 *    events for this feature.
 *
 * Created: 4 Oct 2011 
 ************************************************************************/
@property (nonatomic, readonly) NSString* listenerClass;
/************************************************************************
 * Method: resumeActivation:
 *
 * Purpose: Called when an activation of a feature should be resumed.
 *    The result will be a restart of the Activation of a feature
 *    that has already been authenticated.  If the activation id
 *    is not found it will be ignored.
 ************************************************************************/
+(void) resumeActivation:(NSString*)featureActivationId;
/************************************************************************
 * Method: cancelActivation:
 *
 * Purpose: Called when an activation of a feature should be cancelled.
 *    This will be used to cleanup activations of features that have
 *    been paused and then fail to authenticate through OIC.  The 
 *    only action this will cause in the iOS Native Framework is to 
 *    remove the data associated with the ActivationId.
 ************************************************************************/
+(void) cancelActivation:(NSString*)featureActivationId;
/************************************************************************
 * Method: showDefaultFeature:
 *
 * Purpose: Called to show the proper feature that was the initial
 *    to be shown at the start of the application. 
 ************************************************************************/
+(void) showDefaultFeature;
/***************************************************************************************
 * Method: getApplicationLifecycleListenerInstance
 *
 * Purpose: Gets the instance that is the lifecycle listener for the provided class.
 *    Will return nil if the class was not configured as an ApplicationLifecycleListener
 *
 * Created: 8 November 2011
 ***************************************************************************************/
+(id<ADFApplicationLifecycleListener>) getApplicationLifecycleListenerInstance:(NSString*)listenerClassName;
/***************************************************************************************
 * Method: showErrorWithName:andMessage:
 *
 * Purpose: Displays the error feature populated with the name and message.
 *
 * Created: 11 November 2011
 ***************************************************************************************/
+ (void) showErrorWithName:(NSString*)name andMessage:(NSString*) message;

/***************************************************************************************
 * Method: getPropertyWithKeyPath:
 *
 * Purpose: Gets a property from the active application identify by the key path 
 *    provided.  Only limited values are available.
 *
 * 9 Jan 2012
 ***************************************************************************************/
+ (NSString*) getPropertyWithKeyPath:(NSString*) propertyKey;

/***************************************************************************************
 * Method: getTranslatedErrorPhrase:
 *
 * Purpose: Gets a translated Error phrase from the strings files.  This is used for
 *    static phrases - those not provided by the framework user.  Any kind of error
 *    being generated in this native code.
 *
 * 2 Feb 2012
 ***************************************************************************************/
+ (NSString*) getTranslatedErrorPhrase:(NSString*)key;
/***************************************************************************************
 * Method: getTranslatedInfoWarningOrUIPhrase:
 *
 * Purpose: Gets a translated Information Warning or UI phrase from the strings files.  
 *    This is used fo static phrases - those not provided by the framework user.  Any 
 *    kind of message (information, warning or UI) being generated in this native code.
 *
 * 2 Feb 2012
 ***************************************************************************************/
+ (NSString*) getTranslatedInfoWarningOrUIPhrase:(NSString*)key;

/***************************************************************************************
 * Method: shutdownApplicationWithMessage:andTitle:
 *
 * Purpose: This call causes an exit of the application after notifying the user 
 *   with the message provided.
 *
 * 23 Mar 2012
 ***************************************************************************************/
+ (void) shutdownApplicationWithMessage:(NSString*) messageForUser andTitle:(NSString*) titleForUser;

/***************************************************************************************
 * Method: recordApplicationStartTime:
 *
 * Purpose: Used to record the application start time.  Will only record the first 
 *    value passed to it.
 *
 * 23 Mar 2012
 ***************************************************************************************/
+(void) recordApplicationStartTime: (double) timeStamp;
/***************************************************************************************
 * Method: getApplicationStartTime:
 *
 * Purpose: Gets the application start time as recorded in main.
 *
 * 23 Mar 2012
 ***************************************************************************************/
+(double) getApplicationStartTime;
/************************************************************************
 * Method: terminate
 *
 * Purpose: Exits the app ensuring all required shutdown steps are 
 *   executed.
 *
 * Created: 13 April 2012
 ************************************************************************/
+ (void) terminate;
@end
