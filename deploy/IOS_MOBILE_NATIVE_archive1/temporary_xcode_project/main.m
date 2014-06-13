//
//  main.m
//  Oracle_ADFmc_Container_Template
//
/*
 Copyright (c) 2011 Oracle.
 All rights reserved. 
 */

#import <UIKit/UIKit.h>
#import "ADFCommandLineArgs.h"
#import "ADFApplication.h"

int main(int argc, char *argv[]) 
{    
    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
    
    // Add perf timestamp
    double TimeStamp = (double)([[NSDate date] timeIntervalSince1970] * (1000));
    [ADFApplication recordApplicationStartTime: TimeStamp];
    // !! Do not move to ADF Log macros  !!
    // !! This will occur at a time in the application lifecycle that cannot use framework logging !!
    NSLog(@"Perf log: Application startup, timestamp: %f",  TimeStamp );
    
    [[ADFCommandLineArgs getInstance] setCommandLineArgs:argv withCount:argc];
    int retVal = UIApplicationMain(argc, argv, nil, @"Oracle_ADFmc_Container_TemplateAppDelegate");
    [pool release];
    return retVal;
}
