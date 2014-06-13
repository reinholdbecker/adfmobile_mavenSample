//
//  UIView+OracleExtern.h
//  OracleADFmcContainerLib
//
//  Created by Eric Jumper on 12/19/12.
//
//

#import <UIKit/UIKit.h>

@interface UIView (OracleExtern)
// Gets the intenal webview that is being used by this view if it is a content UIView for a feature.
-(UIWebView*) getInternalWebView;
-(void) setInternalWebView:(UIWebView*)internalWebView;
@end
