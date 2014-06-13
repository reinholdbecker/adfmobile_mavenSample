//
//  oraCDVWebViewDelegate.h
//  CordovaLibAdaptor
//
//  Created by miniadmin on 3/22/13.
//  Copyright (c) 2013 Eric Jumper. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol oraCDVWebViewDelegate <NSObject>
// Called when the Cordova UIWebView has reported it is loaded. 
-(void) webViewDidFinishLoad:(UIWebView *)webView;
@end
