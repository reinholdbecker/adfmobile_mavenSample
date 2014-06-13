//
//  ADFFeature.h
//  OracleADFmcContainerLib
//
/*
 Copyright (c) 2011 Oracle.
 All rights reserved. 
 */
#import <Foundation/Foundation.h>
#import <UIKit/UIWebView.h>
/************************************************************************
 * Method: ADFFeature
 *
 * Purpose: This protocol provides a definition of the ADFFeature object
 *    that is provided through APIs to access a specific features 
 *    information.
 *
 * Created: 29 Sept 2011 (Created)
 ************************************************************************/
@protocol ADFFeature <NSObject>
/************************************************************************
 * Method: listenerClass
 *
 * Purpose: The name of class that was configured to handle the lifecycle
 *    events for this feature.
 *
 * Created: 29 Sept 2011 
 ************************************************************************/
@property (nonatomic, readonly) NSString* listenerClass;

/************************************************************************
 * Method: Id
 *
 * Purpose: The id for this feature.
 *
 * Created: 30 Sept 2011 
 ************************************************************************/
@property (nonatomic, readonly) NSString* id;

/************************************************************************
 * Method: classPaths
 *
 * Purpose: An array of NSString* that lists all the class paths for this
 *    feature.
 *
 * Created: 29 Sept 2011 
 ************************************************************************/
@property (nonatomic, readonly) NSArray* classPaths;

/************************************************************************
 * Method: sessiondata
 *
 * Purpose: An NSMutableDictionary attached to the feature that can be
 *    used to hold various data related to the feature.  Intended
 *    to store infomation about activation, authentication state
 *    and the like.
 *
 * Created: 6 Oct 2011 
 ************************************************************************/
@property (nonatomic, readonly) NSMutableDictionary* sessiondata;

/************************************************************************
 * Method: sessiondata
 *
 * Purpose: An NSMutableDictionary attached to the feature that can be
 *    used to hold various data related to the feature.  Intended
 *    to store infomation about activation, authentication state
 *    and the like.
 *
 * Created: 4 Nov 2011 
 ************************************************************************/
@property (nonatomic, readonly) UIView* featureView;

-(id)           getAuthContext: (id) securityListener;

-(void)         showLoginFeature;

-(NSString *)   getAccessControlConnRefId;

-(BOOL)         isSecureFeature;

-(NSArray *)    getPrivilegeFilterList;

-(void)         cancelActivation:(NSString*) featureActivationId;

-(void)         resumeActivation:(NSString*) featureActivationId;



/************************************************************************
 * Method: isNative
 *
 * Purpose: Indicates if this view is a native view.
 *
 * Created: 11 April 2012
 ************************************************************************/
@property (readonly) BOOL isNative;

@end
