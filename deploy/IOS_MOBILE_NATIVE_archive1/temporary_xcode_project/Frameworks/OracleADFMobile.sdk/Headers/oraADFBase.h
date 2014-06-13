//
//  oraADFBase.h
//  OracleADFmcContainerLib
//
/*
 Copyright (c) 2011 Oracle.
 All rights reserved. 
 */

#import <Foundation/Foundation.h>
#import "oraADFLogger.h"
#import "oraException.h"
#define ADFMF_FARS_ROOT_DIR @"%@/FARs/%@"
// DOM Information 
#define DOM_ADFMF_NAMESPACE_URI @"http://xmlns.oracle.com/adf/mf"
#define DOM_ADFMC_NAMESPACE_URI @"http://xmlns.oracle.com/adf/mf/config"
#define DOM_ADFMS_NAMESPACE_URI @"http://xmlns.oracle.com/adf/mf/skin"
// user.xml DOM element names
#define DOM_ELEMENT_localUserConfig @"localUserConfig"
#define DOM_ELEMENT_setUserId @"setUserId"
#define DOM_ELEMENT_addUserRole @"addUserRole"
#define DOM_ELEMENT_addUserPrivilege @"addUserPrivilege"
// Define the DOM element names
#define DOM_ELEMENT_APPLICATION @"application"
#define DOM_ELEMENT_SPRINGBOARD_FEATURE_REFERENCE @"springboardFeatureReference"
#define DOM_ELEMENT_springboard @"springboard"
#define DOM_ELEMENT_login @"login"
#define DOM_ELEMENT_error @"error"
#define DOM_ELEMENT_featureId @"featureId"
#define CONTENT_LOCATION_standard_content_far_folderName @"OracleStandardADFmfUiComponents"
#define CONTENT_LOCATION_public_html @"/public_html"
#define CONTENT_LOCATION_lib @"/lib"
#define CONTENT_BUNDLE_ROOT @"<BUNDLE ROOT>"
#define DOM_ELEMENT_navigationBar @"navigationBar"
#define DOM_ATTRIBUTE_showNavigationBar @"showNavigationBar"
#define DOM_ELEMENT_IMPLEMENTATION @"content"
#define DOM_ELEMENT_CONSTRAINTS @"constraints"
#define DOM_ELEMENT_CONSTRAINT @"constraint"
#define DOM_ELEMENT_application_lifecycle_listener @"application-lifecycle-listener"
#define DOM_ELEMENT_application_container_utilities_implementer @"application-container-utilities-implementer"
#define DOM_ELEMENT_application_feature_navigation_bar_title_clipping_length @"application-feature-navigation-bar-title-clipping-length"
#define DOM_ATTRIBUTE_animation @"animation"
#define DOM_ATTRIBUTE_width @"width"

#define DOM_ELEMENT_iphone @"iphone"
#define DOM_ELEMENT_ipad @"ipad"
#define DOM_ELEMENT_objective_c_class_name @"classname"
#define DOM_ELEMENT_FEATURE @"feature"
#define DOM_ELEMENT_FEATURE_REFERENCE @"featureReference"
#define DOM_ELEMENT_SECURITY @"security"
#define DOM_ELEMENT_SECURITY_REQUIRED @"required"
#define DOM_ELEMENT_SECURITY_CACHED @"cached"
#define DOM_ELEMENT_LOCAL_HTML @"localHTML"
#define DOM_ELEMENT_REMOTE_URL_WHITELIST @"remoteURLWhiteList"
#define DOM_ELEMENT_DOMAIN @"domain"
#define DOM_ATTRIBUTE_connection @"connection"
#define DOM_ATTRIBUTE_showNavButtons @"showNavButtons"
#define DOM_ELEMENT_AMX @"amx"
#define DOM_ELEMENT_include @"include"
#define DOM_ELEMENT_FILE @"file"
#define DOM_ELEMENT_REMOTE_URL @"remoteURL"
#define DOM_ELEMENT_NATIVEVIEW @"nativeview"
#define DOM_ELEMENT_NATIVEVIEWPARAMETERS @"nativeviewparameters"
#define DOM_ELEMENT_PARAMETER @"parameter"
#define DOM_ELEMENT_PARAMETER_NAME @"name"
#define DOM_ELEMENT_PARAMETER_VALUE @"value"
#define DOM_ELEMENT_PARAMETER_NAME_CLASS @"class"
#define DOM_ATTRIBUTE_URL @"url"
#define DOM_ATTRIBUTE_BASE_URL @"baseUrl"
#define DOM_ATTRIBUTE_DEVICE_ACCESS @"deviceAccess"
#define DOM_ATTRIBUTE_PROPERTY @"property"
#define DOM_ATTRIBUTE_VALUE @"value"
#define DOM_ATTRIBUTE_ID @"id"
#define DOM_ATTRIBUTE_FEATUREID @"featureId"
#define DOM_ATTRIBUTE_ENABLED @"enabled"
#define DOM_ATTRIBUTE_displayGotoSpringboardControl @"displayGotoSpringboardControl"
#define DOM_ATTRIBUTE_displayHideNavigationBarControl @"displayHideShowNavigationBarControl"
#define DOM_ATTRIBUTE_showSpringboardAtStartup @"showSpringboardAtStartup"
#define DOM_ATTRIBUTE_allowDeviceAccess @"allowDeviceAccess"

#define DOM_ATTRIBUTE_showOnNavigationBar @"showOnNavigationBar"
#define DOM_ATTRIBUTE_showOnSpringboard @"showOnSpringboard"
#define DOM_ATTRIBUTE_loginConnRefId @"loginConnRefId"
#define DOM_ATTRIBUTE_FEATURE_ID @"featureId"
#define DOM_ELEMENT_LOGIN_FEATURE @"login"
#define DOM_ATTRIBUTE_defaultConnRefId @"defaultConnRefId"
#define DOM_ATTRIBUTE_accessControlConnRefId @"accessControlConnRefId"
#define DOM_ELEMENT_USEROBJECT_FILTER @"userObjectFilter"

#define DOM_ATTRIBUTE_OPERATOR @"operator"
#define DOM_ATTRIBUTE_ICON @"icon"
#define DOM_ATTRIBUTE_IMAGE @"image"
#define DOM_ATTRIBUTE_listener_class @"listener-class"
#define DOM_ATTRIBUTE_NAME @"name"
#define DOM_ATTRIBUTE_VENDOR @"vendor"
#define DOM_ATTRIBUTE_appControllerFolder @"appControllerFolder"
#define DOM_ATTRIBUTE_appControllerFolder_default @"ApplicationController"
#define DOM_ATTRIBUTE_VERSION @"version"
#define DOM_ATTRIBUTE_INDEX @"index"
#define DOM_ATTRIBUTE_PRIVILEGE @"privilege"
// Fixed phrases
#define PHRASE_LOGGING_IN @"Logging in..."
#define PHRASE_LOADING_CONFIGURATION @"Loading configuration..."
#define PHRASE_BUILDING_LAYOUT @"Building layout..."
#define PHRASE_WELCOME @"Welcome"

@class oraADFSession;
@class oraADFLogger;
/************************************************************************
 * Class: oraADFBase
 *
 * Purpose: This is a class is the base class object for all the Container
 *   classes.  This class provides some utility functionality that can
 *   be used to perform debug logging and other useful features.
 *
 * Authors: Created:, 22 March 2011 (Created)
 ************************************************************************/
@interface oraADFBase : NSObject 
{
    // The active ADF Session
    //oraADFSession* session;
    oraADFLogger* _logger;
}
// A weak reference to the session
@property (nonatomic, readonly) BOOL isDebugging; 

// A weak reference to the session
@property (nonatomic, assign) oraADFSession* session; 

// The logger for this object.
@property (nonatomic, readonly) oraADFLogger* logger;

// Turns on or offf debug mode
+(void) setDebug:(BOOL) newValue;

@end