//
//  MyUIApplication.h
//  TestDeviceDataControlsiOS
//
//  Created by Parag Chandra on 9/8/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ADFCommandLineArgs : NSObject
{
}

// Singleton semantics
+(ADFCommandLineArgs*) getInstance;
+(NSString*) appendParenthesesIfNecessary:(NSString*) methodName;

// Get/Set command line args
-(void) setCommandLineArgs:(char *[])argv withCount:(int) argc;
-(NSArray*) getCommandLineArgs;
-(NSString*) getValueForKey:(NSString*) key;
-(NSDictionary*) getKeyValuePairs;
-(BOOL) getValueForKeyAsBOOL:(NSString*) key;
-(BOOL) isRunningInTestMode;
@end

// Constants
extern NSString * const CMDLINE_TESTMODE_PARAM;
extern NSString * const CMDLINE_FEATURE_PARAM;
extern NSString * const CMDLINE_STARTUPMETHOD_PARAM;
extern NSString * const CMDLINE_SHUTDOWNMETHOD_PARAM;
extern NSString * const CMDLINE_FEATUREVIEWCLASS_PARAM;
extern NSString * const CMDLINE_FAKELOCATIONS_PARAM;
extern NSString * const CMDLINE_CONSOLEREDIRECT_PARAM;
extern NSString * const CMDLINE_DEBUGPORT_PARAM;