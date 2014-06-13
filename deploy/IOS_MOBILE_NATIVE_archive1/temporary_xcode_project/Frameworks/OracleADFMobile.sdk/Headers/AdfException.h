//
//  AdfException.h
//  OracleADFmcContainerLib
/*
 Copyright (c) 2011 Oracle.
 All rights reserved. 
 */

#import <Foundation/Foundation.h>
#define ADF_EXCEPTION_KEY @"exception"

/************************************************************************
 * Class: AdfException
 *
 * Purpose: This class manages the serialization into the proper JSON
 *    format required by the Embedded Framework AdfException.
 *
 * Created: Aug 22 2012
 ************************************************************************/
@interface AdfException : NSObject
// Serializes an exception into the proper JSON format required by the Java
// AdfException class.
+ (NSString*) toJSONWithException:(NSException*)exception;
// This function creates a JSON string required by the Java 
// oracle.adfmf.framework.exception.AdfException using the provided message.
+ (NSString*) toJSONWithMessage:(NSString*)message;
+ (NSDictionary*) toNSDictionaryWithMessage:(NSString*)message;
+ (NSDictionary*) toNSDictionaryWithMessage:(NSString*)message andSeverity:(NSString*)severity;
@end
