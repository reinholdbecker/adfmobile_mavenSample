//
//  OracleIdentityLogSink.h
//  OracleSecurityLib
//
/*
 Created by John Jumper on 10/20/2011.
 Copyright (c) 2012 Oracle and/or its affiliate. All rights reserved.
 */

/*
 This logging infrastructure has been created to allow the security library to 
 remain separate from the Native Framework. This library should have no dependencies
 on the OracleNativeFramework Lib.
 */

#import <Foundation/Foundation.h>
typedef enum ADFSECLogLevel
{
	SECLOG_UNKNOWN = -1,
    SECLOG_ALL,
    SECLOG_FINEST,
    SECLOG_FINER,
    SECLOG_FINE,
    SECLOG_CONFIG,
    SECLOG_INFO,
    SECLOG_WARNING,
    SECLOG_SEVERE
} ADFSECLogLevel; 
#define SEC_LOG_BEGIN( x )  if([OracleIdentityLogSink shouldLogLevel: x ]){
#define SEC_LOG_BLOCK( x )  SEC_LOG_BEGIN( x )
#define SEC_LOG_END }
#define SEC_LOG_LEVEL(lvl, fmt, ...) [[OracleIdentityLogSink getActiveSink] logWithLevel:lvl andMethod:__PRETTY_FUNCTION__ andLine:__LINE__ andFormat:fmt, __VA_ARGS__];
#define SEC_LOG_INFO(fmt, ...)  SEC_LOG_BEGIN(SECLOG_INFO) SEC_LOG_LEVEL(SECLOG_INFO, fmt, __VA_ARGS__) SEC_LOG_END
#define SEC_LOG_ERROR(fmt, ...) SEC_LOG_BEGIN(SECLOG_SEVERE) SEC_LOG_LEVEL(SECLOG_SEVERE, fmt, __VA_ARGS__) SEC_LOG_END
#define SEC_LOG_DEBUG(fmt, ...) SEC_LOG_BEGIN(SECLOG_FINEST) SEC_LOG_LEVEL(SECLOG_FINEST, fmt, __VA_ARGS__) SEC_LOG_END

@protocol OracleIdentityLogSink <NSObject>
- (BOOL) shouldLogLevel:(enum ADFSECLogLevel) proposedLevel;
- (void) logWithLevel:(enum ADFSECLogLevel)level andMethod:(const char*) methodName andLine:(int) lineNum andFormat:(NSString*) format, ...;
@end

@interface OracleIdentityLogSink : NSObject 
{
}
+(BOOL) shouldLogLevel:(enum ADFSECLogLevel) proposedLevel;
+(id<OracleIdentityLogSink>) getActiveSink;
+(void) setActiveSink: (id<OracleIdentityLogSink>)newLogSink;
@end