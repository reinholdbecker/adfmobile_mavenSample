//
//  ADFFeatureLifecycleListener.h
//  OracleADFmcContainerLib
//
/*
 Copyright (c) 2011 Oracle.
 All rights reserved. 
 */

#import <Foundation/Foundation.h>
#import "ADFFeature.h"

/************************************************************************
 * Protocol: ADFFeatureLifecycleListener
 *
 * Purpose: This protocol provides a definition of the object that can 
 *    listen for lifecycle events provided by the Feature.
 *
 * Created:, 29 Sept 2011 (Created)
 ************************************************************************/
@protocol ADFFeatureLifecycleListener <NSObject>
/************************************************************************
 * Protocol: featureActivated
 *
 * Purpose: Called whenever a feature is activated.  This is passed the 
 *    feature that has been activated.
 *
 * Created:, 29 Sept 2011 (Created)
 ************************************************************************/
-(void) featureActivated:(id<ADFFeature>)activatedFeature;
/************************************************************************
 * Protocol: featureDeactivated
 *
 * Purpose: Called whenever a feature is deactivated.  This is passed the 
 *    feature that has been deactivated.
 *
 * Created:, 29 Sept 2011 (Created)
 ************************************************************************/
-(void) featureDeactivated:(id<ADFFeature>)activatedFeature;
@end
