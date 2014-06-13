//
//  ContainerUtilities.h
//  OracleADFmcContainerLib
//
/*
 Copyright (c) 2011 Oracle.
 All rights reserved. 
 */

#import <Foundation/Foundation.h>
/************************************************************************
 * Key Defines:
 *
 * The keys used to store the feature metadata in the dictionaries
 * returned by [AdfmfContainerUtilities getFeatures] and  
 * [AdfmfContainerUtilities getApplicationInformation]
 ************************************************************************/
#define AdfmfContainerUtilities_FEATURE_ID_KEY @"id"
#define AdfmfContainerUtilities_FEATURE_NAME_KEY @"name"
#define AdfmfContainerUtilities_FEATURE_IMAGE_KEY @"image"
#define AdfmfContainerUtilities_FEATURE_ICON_KEY @"icon"

#define AdfmfContainerUtilities_APPLICATION_ID_KEY @"id"
#define AdfmfContainerUtilities_APPLICATION_NAME_KEY @"name"
#define AdfmfContainerUtilities_APPLICATION_VENDOR_KEY @"vendor"
#define AdfmfContainerUtilities_APPLICATION_VERSION_KEY @"version"

/************************************************************************
 * Class: ContainerUtilities
 *
 * Purpose: This class is provided as the official API for use by 
 *    Objective-C developers for manipulating the Container.
 *
 * Created: 2 November, 2011
 ************************************************************************/
@interface AdfmfContainerUtilities : NSObject 
{
}
/***************************************************************************
 * This method requests that the container check for new configuration 
 * from the server.  If we are not using configuration service then this
 * function does nothing.  If we are using configuration service and the
 * check finds that there is new configuration content this call will 
 * notify the user and then shutdown the app.
 ***************************************************************************/
+ (void) checkForNewConfiguration;

/***************************************************************************
 * This method requests that the container display the feature identified by the 
 * featureId.  The display of the feature may not occur if the feature does not
 * exist or there is some authentication/authorization issues around the display
 * of the feature.
 ***************************************************************************/
+ (void) gotoFeature:(NSString*)featureId;

/***************************************************************************
 * Resets the feature state and then shows the feature
 ***************************************************************************/
+ (void) resetFeature:(NSString*)featureId;

/***************************************************************************
 * This method requests that the container display the springboard feature.
 * The display of the springboard may not occur if there is no springboard 
 * defined or there is some authentication/authorization issues around the display
 * of the springboard.
 ***************************************************************************/
+ (void) gotoSpringboard;

/***************************************************************************
 * This method requests that the container display the default feature.
 * The default feature is the same feature that was displayed at the start
 * of the application.  The display of this feature may not occur if there  
 * are some authentication/authorization issues.
 ***************************************************************************/
+ (void) gotoDefaultFeature;

/***************************************************************************
 * This method requests that the container hide the navigation bar. This is
 * the same as the user tapping the hide/show navigation bar icon when the 
 * navigation bar is shown. 
 ***************************************************************************/
+ (void) hideNavigationBar;

/***************************************************************************
 * This method requests that the container show the navigation bar.  This is
 * the same as the user tapping the hide/show navigation bar icon when the 
 * navigation bar is hidden. 
 ***************************************************************************/
+ (void) showNavigationBar;

/****************************************************************************
 This method returns the root directory of the Application Bundle
 ***************************************************************************/
+ (NSString *) getApplicationBundleRoot;

/****************************************************************************
 This method returns the Application Bundle Root directory
 ***************************************************************************/
+ (NSString *) getDocumentRoot;

/****************************************************************************
 This method returns the path to the cache directory
 ***************************************************************************/
+ (NSString *) getCacheRoot;

/****************************************************************************
 This method returns the path to the default location to store temporary files 
 ***************************************************************************/
+ (NSString *) getTempRoot;

/***************************************************************************************
 * Method: getFeatures
 *
 * Purpose: This method returns an array of dictionary objects containing the metadata 
 *    related to the description of features required to create a custom springboard.  
 *    This metadata includes the feature id, feature name, the icon path and the image
 *    path for the feature.
 ***************************************************************************************/
+ (NSArray*) getFeatures;

/***************************************************************************************
 * Method: getApplicationInformation
 *
 * Purpose: This method returns a dictionary containing the metadata related to the 
 *    description of the application required to create a custom springboard. This 
 *    metadata includes the feature id, feature name, the icon path and the image
 *    path for the feature.
 ***************************************************************************************/
+ (NSDictionary*) getApplicationInformation;


// These functions are used to call methods on objects in the three layers
// of the Native Framework.
/***************************************************************************
 * Method: invokeJavaMethodWithId:classname:methodname:args:
 *
 * Purpose: Used to invoke a Java Method from Objective-C.  This takes 
 *    the parameters passed to this method and packages them into an 
 *    NSDictionay of the proper structure and then invokes the method
 *    invokeJavaMethod:(NSDictionary*)definition.
 *
 *    This is a blocking call.  When the return is received from the
 *    Java side it will be returned synchronously.  Because this is a
 *    blocking call it cannot be called on the main thread.  If this call
 *    detects it is being called on the main thread it will raise an
 *    exception.
 * 
 * Paramters: featureId - The featureId you want the Native Framework
 *    to use when it determines the Feature Context for the Java
 *    invocation.
 *
 *    classname - The classname (including the package information) that
 *    you want the infrastructure to create an instance of when calling
 *    the Java method
 *
 *    method - the method name that should be invoked on the instance of
 *    the class specified by the classname.
 *
 *    arguments - an array of arguments to be passed to the method.  They
 *    should be in the order expected by the method.
 ***************************************************************************/
+ (NSObject*) invokeJavaMethodWithId:(NSString*)featureId classname:(NSString*)classname methodname:(NSString*)method args:(NSArray*) arguments;
/***************************************************************************
 * Method: invokeJavaMethod:
 *
 * Purpose: Used to invoke a Java Method from Objective-C.  
 *
 *    This is a blocking call.  When the return is received from the
 *    Java side it will be returned synchronously.  Because this is a
 *    blocking call it cannot be called on the main thread.  If this call
 *    detects it is being called on the main thread it will raise an
 *    exception.
 * 
 * Paramters: definition - This method expects an NSDictionary as a paramter 
 *    and requires it to have the following key values:
 *
 *    featureId - An NSString* - The featureId you want the Native Framework
 *    to use when it determines the Feature Context for the Java
 *    invocation.
 *
 *    classname - An NSString* - The classname (including the package 
 *    information) that you want the infrastructure to create an instance 
 *    of when calling the Java method
 *
 *    method - An NSString* - The method name that should be invoked on the 
 *    instance of the class specified by the classname.
 *
 *    parameters - An NSArray* - an array of arguments to be passed to the 
 *    method.  They should be in the order expected by the method. 
 ***************************************************************************/
+ (NSObject*) invokeJavaMethod:(NSDictionary*)definition;
/***************************************************************************
 * Method: invokeContainerJavaScriptFunctionWithId:methodname:args:
 *
 * Purpose: Used to invoke a JavaScript Method from Objective-C.  This takes 
 *    the parameters passed to this method and packages them into an 
 *    NSDictionay of the proper structure and then invokes the method
 *    invokeContainerJavaScriptFunction:(NSDictionary*)definition.
 *
 *    This is a blocking call.  When the return is received from the
 *    JavaScript side it will be returned synchronously.  Because this is a
 *    blocking call it cannot be called on the main thread.  If this call
 *    detects it is being called on the main thread it will raise an
 *    exception.
 * 
 * Paramters: featureId - The featureId you want the Native Framework
 *    to use when it determines the Feature Context for the JavaScript
 *    invocation.  This determines the UIWebView that the method will 
 *    be called in
 *
 *    method - The method name that should be invoked.
 *
 *    arguments - an array of arguments to be passed to the method.  They
 *    should be in the order expected by the method.
 ***************************************************************************/
+ (NSObject*) invokeContainerJavaScriptFunctionWithId:(NSString*)featureId  methodname:(NSString*)method args:(NSArray*) arguments;
/***************************************************************************
 * Method: invokeContainerJavaScriptFunction:
 *
 * Purpose: Used to invoke a Java Method from Objective-C.  
 *
 *    This is a blocking call.  When the return is received from the
 *    JavaScript it will be returned synchronously.  Because this is a
 *    blocking call it cannot be called on the main thread.  If this call
 *    detects it is being called on the main thread it will raise an
 *    exception.
 * 
 * Paramters: definition - This method expects an NSDictionary as a paramter 
 *    and requires it to have the following key values:
 *
 *    featureId - An NSString* - The featureId you want the Native Framework
 *    to use when it determines the Feature Context for the JavaScript
 *    invocation.  This determines which UIWebView will be used to call the
 *    JavaScript method
 *
 *    method - An NSString* - The method name that should be invoked in the 
 *    feature's UIWebView.
 *
 *    parameters - An NSArray* - an array of arguments to be passed to the 
 *    method.  They should be in the order expected by the method. 
 ***************************************************************************/
+ (NSObject*) invokeContainerJavaScriptFunction:(NSDictionary*)definition;
/***************************************************************************
 * Method: invokeContainerMethodWithId:classname:methodname:args:
 *
 * Purpose: Used to invoke a Method on any Objective-C object in the same way
 *    it would be from the Java CVM infrastructure.  This takes 
 *    the parameters passed to this method and packages them into an 
 *    NSDictionay of the proper structure and then invokes the method
 *    invokeContainerMethod:(NSDictionary*)definition.
 *
 *    This is a blocking call.  When the return is received from the
 *    Java side it will be returned synchronously.  Because this is a
 *    blocking call it cannot be called on the main thread.  If this call
 *    detects it is being called on the main thread it will raise an
 *    exception.
 * 
 * Paramters: featureId - The featureId you want the Native Framework
 *    to use when it determines the Feature Context for the Objective-C
 *    invocation.
 *
 *    classname - The classname (can include package information) that
 *    you want the infrastructure to create an instance of when calling
 *    the Objective-C method.  If there is package information then the
 *    package will be stripped off and only the class name will be used.
 *    This is because Objective-C does not support namespacing/packages.
 *
 *    method - the method name that should be invoked on the instance of
 *    the class specified by the classname.
 *
 *    arguments - an array of arguments to be passed to the method.  They
 *    should be in the order expected by the method.  They will be passed
 *    to the method as a single array do to the limitations of reflection
 *    in Oabjective-C.
 ***************************************************************************/
+ (NSObject*) invokeContainerMethodWithId:(NSString*)featureId classname:(NSString*)classname methodname:(NSString*)method args:(NSArray*) arguments;
/***************************************************************************
 * Method: invokeContainerMethod:
 *
 * Purpose: Used to invoke a Method on any Objective-C object in the 
 *    same way it would be from the Java CVM infrastructure.  
 *
 *    This is a blocking call.  When the return is received from the
 *    Java side it will be returned synchronously.  Because this is a
 *    blocking call it cannot be called on the main thread.  If this call
 *    detects it is being called on the main thread it will raise an
 *    exception.
 * 
 * Paramters: definition - This method expects an NSDictionary as a paramter 
 *    and requires it to have the following key values:
 *
 *    featureId - The featureId you want the Native Framework
 *    to use when it determines the Feature Context for the Objective-C
 *    invocation.
 *
 *    classname - The classname (can include package information) that
 *    you want the infrastructure to create an instance of when calling
 *    the Objective-C method.  If there is package information then the
 *    package will be stripped off and only the class name will be used.
 *    This is because Objective-C does not support namespacing/packages.
 *
 *    method - the method name that should be invoked on the instance of
 *    the class specified by the classname.
 *
 *    arguments - an array of arguments to be passed to the method.  They
 *    should be in the order expected by the method.  They will be passed
 *    to the method as a single array do to the limitations of reflection
 *    in Oabjective-C.
 ***************************************************************************/
+ (NSObject*) invokeContainerMethod:(NSDictionary*)definition;

+ (id) rationalizeObject:(id)var;
+ (NSObject*) setApplicationIconBadgeNumber:(NSInteger)badgeNumber;
+ (NSObject*) getApplicationIconBadgeNumber;
@end
