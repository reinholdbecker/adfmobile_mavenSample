//
//  oraADFPropertiesLoader.h
//  OracleADFmcContainerLib
//
/*
 Copyright (c) 2011 Oracle.
 All rights reserved. 
 */

#import <Foundation/Foundation.h>


/************************************************************************
 * Class: oraADFPropertiesLoader
 *
 * Purpose: This class is used to load a .properties file.  The file
 *    is parsed and all the lines are added to an NSDictionary for 
 *    access
 *
 * Authors: Created:, 11 April 2011 (Created)
 ************************************************************************/
@interface oraADFPropertiesLoader : NSObject 
{
    
}
@property (readonly) NSDictionary* properties;
-(NSString*) valueForKey:(NSString*)key;
-(void) loadPropertiesFile:(NSString*)filePathInAppBundle;
-(id) initWithFile:(NSString*)filePathInAppBundle;
-(float) floatValueForKey:(NSString*)key withDefault:(float) defaultValue;
@end
