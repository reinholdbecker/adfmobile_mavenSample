//
//  ADFApplicationLifecycleListener.h
//  OracleADFmcContainerLib
//
/*
 Copyright (c) 2011 Oracle.
 All rights reserved. 
 */

#import <Foundation/Foundation.h>
#import "ADFFeature.h"
typedef enum ADFFeatureActivationResponse
{
	ALLOW_ACTIVATION = 0,
    CANCEL_ACTIVATION,
    PAUSE_ACTIVATION
} ADFFeatureActivationResponse; 

/************************************************************************
 * Protocol: ADFApplicationLifecycleListener
 *
 * Purpose: This protocol provides a definition of the object that can 
 *    listen for lifecycle events provided by the Application.
 *
 * Created:, 30 Sept 2011
 ************************************************************************/
@protocol ADFApplicationLifecycleListener <NSObject>
/************************************************************************
 * Protocol: addedToApplicationListenerList
 *
 * Purpose: Called when the listener has been added to the application
 *    lifecycle listener list
 *
 * Created: 30 Sept 2011
 ************************************************************************/
-(void) addedToApplicationListenerList;
/************************************************************************
 * Protocol: firstActivationOfFeatureWillOccur:
 *
 * Purpose: Called whenever a feature that has not been activated is 
 *    about to be activated.  This gives application listeners a chance
 *    to register a listener with the feature before it is activated.
 *    this function will only be called a maximum of one time for each 
 *    feature.
 *
 * Created: 30 Sept 2011
 ************************************************************************/
-(void) firstActivationOfFeatureWillOccur:(id<ADFFeature>) featureBeingActivated;

/************************************************************************
 * Protocol: willActivateFeature:
 *
 * Purpose: Called whenever a feature is about to be activated.  The
 *    response can indicate that the feature activation should continue,
 *    should be paused or should be canceled all together.  If paused, 
 *    the event activateFeaturePaused:withActivationId: will be called
 *    with an id that will allow the handler that paused the activation
 *    to continue the activation.
 *
 *    The use of this function is targeted at requirements to allow the user
 *    to be prompted for a login.
 *
 * Return: ALLOW_ACTIVATION = 0,
 *         CANCEL_ACTIVATION,
 *         PAUSE_ACTIVATION
 *
 * Created: 3 Oct 2011
 ************************************************************************/
-(ADFFeatureActivationResponse) willActivateFeature:(id<ADFFeature>) featureBeingActivated;

/************************************************************************
 * Protocol: activateFeaturePaused:withActivationId:
 *
 * Purpose: Called whenever a feature activation has been paused.  The
 *    response from willActivateFeature indicated that the feature activation
 *    should be paused - presumabaly to allow a prompt of the user for 
 *    aditional information.
 *
 *    The ADFApplication calls continueFeatureActivation: or 
 *    cancelFeatureActivation: can be used with the value of featureActivationId
 *    to properly manage the continuation or cleanup of the feature activation.
 *
 *    The use of this function is targeted at requirements to allow the user
 *    to be prompted for a login.
 *
 * Created: 3 Oct 2011
 ************************************************************************/
-(void) activateFeaturePaused:(id<ADFFeature>) featureBeingPaused withActivationId:(NSString*)featureActivationId;

/************************************************************************
 * Protocol: start
 *
 * Purpose: Called when the application has started.  This is after the 
 *    application definition files have been loaded and the first 
 *    feature has not yet been activated
 *
 * Created: 3 Oct 2011
 ************************************************************************/
-(void) start;
/************************************************************************
 * Protocol: stop
 *
 * Purpose: Called when the application is about to shutdown.  This call 
 *    should block the thread until shudown activity is completed.
 *
 * Created: 3 Oct 2011
 ************************************************************************/
-(void) stop;
/************************************************************************
 * Protocol: activate
 *
 * Purpose: Called when the application is returning from being in the
 *    background.
 *
 * Created: 3 Oct 2011
 ************************************************************************/
-(void) activate;
/************************************************************************
 * Protocol: deactivate
 *
 * Purpose: Called when the application is bing placed in the background.
 *
 * Created: 3 Oct 2011
 ************************************************************************/
-(void) deactivate;
@end
