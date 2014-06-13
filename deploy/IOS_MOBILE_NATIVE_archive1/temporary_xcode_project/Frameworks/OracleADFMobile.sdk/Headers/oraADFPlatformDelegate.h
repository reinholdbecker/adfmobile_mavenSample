//
//  oraADFPlatform.h
//  OracleADFmcContainerLib
//
/*
 Copyright (c) 2011 Oracle.
 All rights reserved. 
 */

#import <Foundation/Foundation.h>


@protocol oraADFPlatformDelegate <NSObject>
/***************************************************************************************
 * Call this when you need to get the PhoneGap device properties.
 *
 * Authors: Created: 13 April, 2011 (Created)
 ***************************************************************************************/
-(NSDictionary*) deviceProperties;
@end
