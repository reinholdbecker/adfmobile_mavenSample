//
//  oraADFSettings.h
//  OracleSettingsLib
//
/*
 Copyright (c) 2011 Oracle.
 All rights reserved. 
 */

#import <Foundation/Foundation.h>
#import "oraADFSetting.h"
/************************************************************************
 * Protocol: oraADFSettings
 *
 * Purpose: This protocol defines the API for a settings object.  This 
 *    represents the collection of all the available settings from the
 *    bundel.  By intacting with this API you will ensure that the 
 *    defaults specified in the adf-mobile.xml file are enforced
 *    when accessing the setings.
 *
 * 3 May, 2011 (Created)
 ************************************************************************/
@protocol oraADFSettings <NSObject>
// All the oraADFSetting defined in the bundle
@property(nonatomic,readonly) NSArray* allSettings;
// All the oraADFSetting objects in a dictionary keyed on 
// the setting's key
@property(nonatomic,readonly) NSDictionary* dictionary;

// Gets the value specified by the key
- (id<oraADFSetting>) getSetting:(NSString*) key;
// Gets the string value specified by the key - bypass intermediate use of 
// the oraADFSetting object.
- (NSString*) getStringSetting:(NSString*) key;
@end

/************************************************************************
 * Class: oraADFSettings
 *
 * Purpose: This class manages getting settings from the app bundle.
 *   it wraps the app bundle and ensures that default values specified 
 *   in the setting bundle are enforced. 
 *
 * 3 May, 2011 (Created)
 ************************************************************************/
@interface oraADFSettings : NSObject 
{
}
// Gets an oraADFSettings that manages settings for the bundle name provided
// assumes the settings bundle is in the root of the app bundle
+ (id<oraADFSettings>) getSettings:(NSString*)settingsBundle;
// Gets a settings object initialized using the "Settings.bundle".
+ (id<oraADFSettings>) getSettingsFromDefaultBundle;
@end
