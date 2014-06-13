//
//  CordovaLibAdaptor.h
//  CordovaLibAdaptor
//
/*
 Copyright (c) 2012 Oracle.
 All rights reserved.
 */

#import <UIKit/UIKit.h>
#import "oraCDVWebViewDelegate.h"
/**
 * This class is intended as the starting point for the API to the Cordova Lib Adaptor.  Do not use
 * any Cordova Lib objects directly in the main ADF Mobile libraries.  Any use of those objects should
 * go through this adaptor and be wrapped by an adaptor object.  This will ensure we know the points of
 * contact between Cordova and ADF Mobile.  It will also facilitate the masking of the use of ARC by 
 * the Cordova Lib until we are ready to migrate to the use of ARC in our libraries.
 **/
@interface CordovaLibAdaptor : NSObject
/** 
 * Creates an un-retained (autoreleased) Cordova UIViewController Adaptor.
 **/
+(UIViewController*) createCordovaUIViewController;
+(UIViewController*) createCordovaUIViewController:(BOOL) hasDeviceAccess andDelegate:(id<oraCDVWebViewDelegate>)delegate;

+(void)              fixupTheGlobalRuntimeWhiteList:(NSArray*)urls;

/** 
 * Given a Cordova created UIViewController this function will return the UIWebView being used as 
 * the Cordova View.  This is needed because there is internal knowledge of how the UIView heirarchy is
 * structured.
 **/
+(UIWebView*) findCordovaUIWebView:(UIViewController*)cordovaViewController;
@end

/**
 * These calls should be removed after the prototype phase
 **/
@interface CordovaLibAdaptor (prototype)
/**
 * Given a Cordova created UIViewController this function will add an additional URL paramter to the
 * existing start page URL that will be used in the initialization of the Cordova Web View.
 **/
+(void) addParameterToUrlUIWebView:(UIViewController*) cordovaViewController withName:(NSString*)parameterName withValue:(NSString*)parameterValue;
@end