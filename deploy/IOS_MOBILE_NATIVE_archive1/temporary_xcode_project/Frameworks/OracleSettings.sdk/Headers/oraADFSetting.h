//
//  oraADFSetting.h
//  OracleSettingsLib
//
/*
 Copyright (c) 2011 Oracle.
 All rights reserved. 
 */

#import <Foundation/Foundation.h>

/************************************************************************
 * Protocol: oraADFSetting
 *
 * Purpose: This protocol defines the API for an indavidual setting 
 *    object.  By intacting with this API you will ensure that the 
 *    defaults specified in the adf-mobile.xml file are enforced
 *    when accessing the setings.
 *
 * 3 May, 2011 (Created)
 ************************************************************************/
@protocol oraADFSetting <NSObject>
// The setting lable from the adf-mobile.xml
@property(nonatomic,readonly) NSString* label;
// The setting id from the adf-mobile.xml
@property(nonatomic,readonly) NSString* key;
// The setting as a string value
@property(nonatomic,readonly) NSString* stringValue;
@end
