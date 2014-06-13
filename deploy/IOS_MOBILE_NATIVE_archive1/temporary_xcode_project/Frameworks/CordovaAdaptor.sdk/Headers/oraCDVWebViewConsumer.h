//
//  oraCDVWebViewConsumer.h
//  CordovaLibAdaptor
/*
 Copyright (c) 2012 Oracle.
 All rights reserved.
 */
#import <UIKit/UIKit.h>
#import "oraCDVPluginResultListener.h"
/*
 This Protocol is used to indicate an oraCDVPlugin requires the UIWebView that is being used
 by the CDVPlugin.
 */
@protocol oraCDVWebViewConsumer <NSObject>
// Called to set the webview that is being used by the plugin.  Called once
// when the container side object is created.
-(void) setCordovaWebView:(UIWebView*)webView;
// Called to set the object on the CordovaLibAdaptor side that will listen for
// results responses from the Container Side.  This object will be unique for
// each instance of a plugin.
-(void) setPluginResultListener:(id<oraCDVPluginResultListener>)listener;
@end
