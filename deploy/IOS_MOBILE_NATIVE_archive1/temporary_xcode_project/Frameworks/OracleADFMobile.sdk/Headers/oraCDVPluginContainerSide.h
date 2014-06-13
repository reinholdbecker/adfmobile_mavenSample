//
//  oraCDVPluginContainerSide.h
//  OracleADFmcContainerLib
//
//  Created by Eric Jumper on 11/29/12.
//
//

#import <UIKit/UIKit.h>
#import "oraCDVWebViewConsumer.h"

@interface oraCDVPluginContainerSide : NSObject <oraCDVWebViewConsumer>
@property(readonly) UIWebView* webView;
// Available Cordova Response Handlers...
- (BOOL) performCordovaResponseForSuccessValue:(NSObject*)returnValue forRequest:(NSDictionary*)originalRequest;
- (BOOL) performCordovaResponseForFailureValue:(NSObject*)returnValue forRequest:(NSDictionary*)originalRequest;
@end
