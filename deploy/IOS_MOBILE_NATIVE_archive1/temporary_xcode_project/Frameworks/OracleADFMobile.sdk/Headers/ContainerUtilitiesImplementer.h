//
//  ContainerUtilitiesImplementer.h
//  OracleADFmcContainerLib
//
//  Created by Eric Jumper on 11/2/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#define ContainerUtilities_featureId @"featureId"
#define ContainerUtilities_parameters @"params"
#define ContainerUtilities_method @"method"
#define ContainerUtilities_classname @"classname"

@protocol ContainerUtilitiesImplementer <NSObject>
// This method requests that the container display the feature identified by the 
// featureId.  The display of the feature may not occur if the feature does not
// exist or there is some authentication/authorization issues around the display
// of the feature.
- (void) gotoFeature:(NSString*)featureId;

// This method requests that the container reset the state of a feature and then
// reload and display the UI for the feature.
- (void) resetFeature:(NSString*)featureId;

// This method requests that the container display the springboard feature.
// The display of the springboard may not occur if there is no springboard 
// defined or there is some authentication/authorization issues around the display
// of the springboard.
- (void) gotoSpringboard;

// This method requests that the container display the default feature.
// The default feature is the same feature that was displayed at the start
// of the application.  The display of this feature may not occur if there  
// are some authentication/authorization issues.
- (void) gotoDefaultFeature;

// This method requests that the container hide the navigation bar. This is
// the same as the user tapping the hide/show navigation bar icon when the 
// navigation bar is shown. 
- (void) hideNavigationBar;

// This method requests that the container show the navigation bar.  This is
// the same as the user tapping the hide/show navigation bar icon when the 
// navigation bar is hidden. 
- (void) showNavigationBar;

// These functions are used to call methods on objects in the three layers
// of the Native Framework.

// invokeJavaMethod expects a dictionary containing a classname, method and paramters
// object.  The parameters object should be an NSArray containing [featureId,parameter0,paramter1,...].
// The featureId will be used to determine the ADF Channel that will be used to invoke
// the the Java Method.  The rest of the parameters will be used as the parameter to the 
// method.
- (NSObject*) invokeJavaMethod:(NSDictionary*)definition;

// invokeJavaMethod expects a dictionary containing a method and paramters 
// object (no classname).  The parameters object should be an NSArray containing 
// [featureId,parameter0,paramter1,...].  The featureId will be used to determine 
// the Feauture WebView that will be used to invoke the the JavaScript Method.
// The rest of the parameters will be used as the parameter to the method.
- (NSObject*) invokeContainerJavaScriptFunction:(NSDictionary*)definition;

// invokeContainerMethod expects a dictionary containing a classname, method and paramters
// object.  The parameters object should be an NSArray containing [featureId,parameter0,paramter1,...].
// The featureId will be used to determine the ADF Channel that will be used to invoke
// the the Objective-C Method.  The rest of the parameters will be used as the parameter to the 
// method.
- (NSObject*) invokeContainerMethod:(NSDictionary*)definition;

@end
