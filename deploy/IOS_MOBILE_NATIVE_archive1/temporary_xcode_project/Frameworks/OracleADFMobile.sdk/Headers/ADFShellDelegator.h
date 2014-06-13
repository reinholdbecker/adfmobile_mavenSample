//
//  ADFShellDelegator.h
//  OracleADFmcContainerLib
//
/*
 Copyright (c) 2011 Oracle.
 All rights reserved. 
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIWebView.h>
#import "oraADFContainerDelegate.h"
#import "oraADFPlatformDelegate.h"
@class UITabBarController;
@class UIView;
@class oraADFActivityView;
@class oraADFAccelerationVector;
/************************************************************************
 * Class: ADFShellDelegator
 *
 * Purpose: This is the App Delegate that we use in the shell template
 *   to initialize and implement all of the ADF Mobile !Shell behavior.
 *
 *   We no linger derive from the PhoneGapDelegate since Cordova
 *
 * Authors: Created:, 22 March 2011 (Created)
 ************************************************************************/
@interface ADFShellDelegator : NSObject <UIApplicationDelegate, oraADFContainerDelegate, oraADFPlatformDelegate,UIDocumentInteractionControllerDelegate>
{
}
- (void) nonblockingDisplayModalViewController:(UIViewController*) controllerToDisplay;
- (NSDictionary*) displayModalViewController:(UIViewController*) controllerToDisplay;
+ (void) updateAvailableWidth:(CGFloat) width andHeight:(CGFloat) height;
+ (BOOL) getIsRunningOnDevice;
@property(retain,nonatomic) NSString* activityIndicatorMessage;
// All the overlaid controllers we have been provided
@property(readonly) oraADFAccelerationVector* acceleration;
@property (readonly) BOOL applicationDefinitionLoadIsComplete;
@property(readwrite) BOOL cvmLoadIsComplete;
@property(retain,nonatomic) UIView* rootView;
@property(retain,nonatomic) UIWindow* topWindow;
@property (nonatomic) dispatch_queue_t jvmDispatchQueue;

@property(readonly) NSString* logFilePath;
@property(readonly) BOOL isRunningOnDevice;
@property(readonly) BOOL isLoginDisplayed;
@property(readonly) UIDeviceOrientation deviceOrientation;
-(void) emailLog;

// oraADFContainerDelegate Methods
- (NSURL*) urlForWebResource:(NSString*)resourcepath;
- (id<UIWebViewDelegate>) getPhoneGapWebViewDelegate;
- (void) selectViewController:(UIViewController*) controllerToSelect;
- (void) hideNavigationBar;
- (void) showNavigationBar;
- (BOOL) nativeFrameworkConfigurationLoadIsComplete;

// PhoneGap override functions for future use.
- (id) getCommandInstance:(NSString*)className withWebView:(UIWebView*)targetWebView;
- (NSDictionary*) deviceProperties;

// Used to keep track of the available width and height occupied by the
// main view
+ (CGFloat) getLastAvailableWidth;
+ (CGFloat) getLastAvailableHeight;

+(void) modalViewControllerIsComplete:(UIViewController*) modalController withDictionary:(NSDictionary*)responseDictionary;

/** This method is used to resume the JVM Dispatch Queue after its called once from setCvmLoadIsComplete and second time from uiBuildOutIsComplete */
-(void) resumeJVMDispatchQueueAfterTwoCalls;
@end
