//
//  oraADFContainerDelegate.h
//  OracleADFmcContainerLib
//
/*
 Copyright (c) 2011 Oracle.
 All rights reserved. 
 */

#import <UIKit/UIKit.h>
#import <UIKit/UIWebView.h>

/************************************************************************
 * Interface: oraADFContainerDelegate
 *
 * Purpose: This interface is used to handle notification events from the 
 *   oraADFContainer.  These events represent requests from the container
 *   and are generally provided in response to requests from the various
 *   feature views.
 *
 * Authors: Created:, 23 March 2011 (Created)
 ************************************************************************/
@protocol oraADFContainerDelegate <NSObject>

/***************************************************************************************
 * Fired by the oraADFContainer if one of the HTTP features specifies a URL
 * that has no scheme.  That resource is probbably located in the bundle in 
 * a www subdirectory but we do not know for sure so the oraADFContainer
 * delegates that decision out to the oraADFContainerDelegate.
 *
 * Authors: Created: 24 March, 2011 (Created)
 ***************************************************************************************/
- (NSURL*) urlForWebResource:(NSString*)resourcepath;

/***************************************************************************************
 * Fired by the oraADFContainer when it needs a reference to the PhoneGap WebView 
 * Delegate.  This delegate is going to be attached to a new Web View to handle the 
 * PhoneGap API calls.
 *
 * Authors: Created: 8 April, 2011 (Created)
 ***************************************************************************************/
- (id<UIWebViewDelegate>) getPhoneGapWebViewDelegate;

/***************************************************************************************
 * Called when a now view controller has been programatically selected.  Tab Bar 
 * Controller should show the view associated with the view controller.
 *
 * Authors: Created: 27 April, 2011 (Created)
 ***************************************************************************************/
- (void) selectViewController:(UIViewController*) controllerToSelect;

/***************************************************************************************
 * Called when a now view controller has been programatically selected.  This view is
 * not in the view controllers provided for the Navigation Bar controller.  The delegate
 * should show the view associated with the overlay view controller.
 *
 * Authors: Created: 8 June, 2011 (Created)
 ***************************************************************************************/
- (void) overlayViewController:(UIViewController*) controllerToOverlay;

/***************************************************************************************
 * Called to display a native view controller to the user in a modal dialog fashion.
 *
 * 23 Jan 2012
 ***************************************************************************************/
- (NSDictionary*) displayModalViewController:(UIViewController*) controllerToDisplay;

/***************************************************************************************
 * Fired by the hideNavigationBar when it wants the navigation bar to be hidden
 *
 * Authors: Created: 14 April, 2011 (Created)
 ***************************************************************************************/
- (void) hideNavigationBar;

/***************************************************************************************
 * Fired by the hideNavigationBar when it wants the navigation bar to be shown
 *
 * Authors: Created: 14 April, 2011 (Created)
 ***************************************************************************************/
- (void) showNavigationBar;

/***************************************************************************************
 * Fired by the active OracleAdfmfApplication to determine if the display is in a 
 *   slid out springboard state.  Returns true to indicate springboard show should
 *   continue.  False return indicates the springboard is already showing in a slide
 *   out mode.
 *
 * Created: 29 November, 2011
 ***************************************************************************************/
- (BOOL) willShowSpringboard;
@end
