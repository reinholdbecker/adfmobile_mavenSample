//
//  ADFWebView.h
//  OracleADFmcContainerLib
//
/*
 Copyright (c) 2011 Oracle.
 All rights reserved. 
 */

#import <Foundation/Foundation.h>


@protocol ADFWebView <NSObject>
/***************************************************************************************
 * Property: featureId:
 *
 * Purpose: Provides the feature id this ADFWebView is associated with.
 ***************************************************************************************/
@property(nonatomic,readonly) NSString* featureId;
@end
