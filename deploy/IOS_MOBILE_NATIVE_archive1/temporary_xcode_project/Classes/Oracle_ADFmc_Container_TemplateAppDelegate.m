//
//  Oracle_ADFmc_Container_TemplateAppDelegate.m
//  Oracle_ADFmc_Container_Template
//
/*
 Copyright (c) 2011 Oracle.
 All rights reserved. 
 */

#import "Oracle_ADFmc_Container_TemplateAppDelegate.h"
#import "ADFCommandLineArgs.h"
#import "oraADFLogger.h"
#import "ADFApplication.h"
#import "oraADFBase.h"

/************************************************************************
 * Interface: Oracle_ADFmc_Container_TemplateAppDelegate
 *
 * Purpose: This interface is App Delegate for this application.  We 
 *    simply extend the ADFShellDelegator which provides all our
 *    UI features.  Configuration of those features are made through 
 *    the adf-mobile-xml.
 ************************************************************************/
@implementation Oracle_ADFmc_Container_TemplateAppDelegate
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    return [super application:application didFinishLaunchingWithOptions:launchOptions];
}

@end
