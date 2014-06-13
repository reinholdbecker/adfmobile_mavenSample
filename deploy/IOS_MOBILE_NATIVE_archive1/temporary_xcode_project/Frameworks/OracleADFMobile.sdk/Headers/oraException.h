//
//  oraException.h
//  OracleADFmcContainerLib
//
//  Created by Eric Jumper on 2/6/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface oraException : NSException
+ (void)raiseWithNameKey:(NSString *)name andDescriptionKey:(NSString *)format;
+ (void)raiseWithNameKey:(NSString *)nameKey andTranslatedDescription:(NSString *)description;
@property(nonatomic,retain) NSString* exceptionSeverity;
@end
