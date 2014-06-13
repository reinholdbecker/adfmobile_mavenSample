//
//  CordovaAdaptorAPI.h
//  CordovaLibAdaptor
/*
 Copyright (c) 2012 Oracle.
 All rights reserved.
 */

// General use in the Container Code by plugins
#import "CordovaAdaptorResult.h"

// Container code uses this to get Cordova UIViewController objects
#import "CordovaLibAdaptor.h"

// Used in the base class, oraCDVPluginContainerSide, in the Container.
#import "oraCDVWebViewConsumer.h"
#import "oraCDVPluginResultListener.h"

// Used container side by OracleAdfmfContent to detect the load complete
// and unhide the UIWebView to avoid the empty UIWebView white flash.  It
// is at that time we attempt to initialize the JavaScript logging as well.
#import "oraCDVWebViewDelegate.h"

#ifndef CordovaLibAdaptor_CordovaAdaptorAPI_h
#define CordovaLibAdaptor_CordovaAdaptorAPI_h

#endif
