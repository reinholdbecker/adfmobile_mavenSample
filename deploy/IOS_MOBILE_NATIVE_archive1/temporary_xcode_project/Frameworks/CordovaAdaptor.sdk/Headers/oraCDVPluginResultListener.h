//
//  oraCDVPluginResultListener.h
//  CordovaLibAdaptor
/*
 Copyright (c) 2012 Oracle.
 All rights reserved.
 */

#import <Foundation/Foundation.h>

@protocol oraCDVPluginResultListener <NSObject>
/* 
 * Determines if the request NSDictionary was a Cordova request and if it was, a success response is 
 * sent back to the Cordova framework.  The return value will indicate: True - response was handled; 
 * False - the request was not a Cordova request.
 */
- (BOOL) performCordovaResponseForSuccessNSObject:(NSObject*)returnValue forRequest:(NSDictionary*)originalRequest;

/*
 * Determines if the request NSDictionary was a Cordova request and if it was, a success response is
 * sent back to the Cordova framework.  The return value will indicate: True - response was handled;
 * False - the request was not a Cordova request.
 */
- (BOOL) performCordovaResponseForFailureValue:(NSObject*)returnValue forRequest:(NSDictionary*)originalRequest;
@end
