//
//  CordovaAdaptorResult.h
//  CordovaLibAdaptor
//
/*
 Copyright (c) 2012 Oracle.
 All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 * CordovaAdaptorResult provides a mechanism to pass a normal NSObject (non-NSDictionary,
 * non-NSString or non-NSArray) to performCordovaResponseForSuccessNSObject.  If you
 * implement this and pass the object this Protocol will be used to serialize the object
 * into an for return to the JavaScript layer.
 */
@protocol CordovaAdaptorResult <NSObject>
/**
 * Serializes the object to an NSDictionary for return to the JavaScript success or fail call.
 **/
-(NSDictionary*) serializeAsCordovaReturn;
@end
