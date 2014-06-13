//
//  oraADFLogging.h
//  OracleADFmcContainerLib
//
/*
 Copyright (c) 2011 Oracle.
 All rights reserved. 
 */

#import <Foundation/Foundation.h>
#import "ADFApplication.h"
#import "ADFLogLevel.h"

#define _ADF_LOGGING_PROPERTIES_FILE_PATH_ @"lib/logging.properties"
#define _ADF_iOS_DEFAULT_PATTERN_DESCRIPTION_ @"oracle.adfmf.util.logging.PatternFormatter.pattern"
#define _ADF_iOS_DEFAULT_LINE_PATTERN_ @"[%LEVEL% %LOGGER% %CLASS% %METHOD% %TIME%] %MESSAGE%"
#define _ADF_iOS_FRAMEWORK_LOGGING_PACKAGE_ @"oracle.adfmf.framework"
#define _ADF_iOS_APPLICATION_LOGGING_PACKAGE_ @"oracle.adfmf.application"
#define _ADF_iOS_PERFORMANCE_LOGGING_PACKAGE_ @"oracle.adfmf.performance"
#define _ADF_iOS_TEST_LOGGING_PACKAGE_ @"oracle.adfmf.test"
#define _ADF_iOS_DEFAULT_LOGGING_PACKAGE_ _ADF_iOS_FRAMEWORK_LOGGING_PACKAGE_
#define LOGGING_PREFIX_INDICATING_CONTAINER self.packageName

#define LOG_RUNNING_CODE(x)     NSLog(@"++++++++++++ RUNNING LOG CODE ++++++++++++ %d >= %d", x, [oraADFLogger defaultLoggerLevel]);
#define LOG_NOT_RUNNING_CODE    NSLog(@"------------ NOT RUNNING LOG CODE ------------");

// If you need to debug security change false to true BUT don't check it in.
#define LOG_SECURE_BEGIN( x )  if((false) && (x>=[oraADFLogger defaultLoggerLevel])){
#define LOG_SECURE_BLOCK( x )  LOG_SECURE_BEGIN( x )

#define LOG_BEGIN( x )  if(x>=[oraADFLogger defaultLoggerLevel]){
#define LOG_BLOCK( x )  LOG_BEGIN( x )
#define LOG_END }

#define LOG_LEVEL(lvl, fmt, ...) [[oraADFLogger getDefaultLogger] logWithLevel:lvl andMethod:__PRETTY_FUNCTION__ andLine:__LINE__ andFormat:fmt, __VA_ARGS__];

#define LOG_DEBUG(fmt, ...) LOG_BEGIN(FINEST) LOG_LEVEL(FINEST, fmt, __VA_ARGS__) LOG_END
#define LOG_DEBUG_STRING(str)  LOG_BEGIN(FINEST) LOG_LEVEL(FINEST, str, nil) LOG_END

#define LOG_SECURE_DEBUG(fmt, ...)    LOG_SECURE_BEGIN(FINEST) LOG_LEVEL(FINEST, fmt, __VA_ARGS__) LOG_END
#define LOG_SECURE_DEBUG_STRING(str)  LOG_SECURE_BEGIN(FINEST) LOG_LEVEL(FINEST, str, nil) LOG_END


#define LOG_INFO_DO_NOT_USE_DIRECT_TRANSLATE_INFO_MSGS(fmt, ...)  LOG_BEGIN(INFO) LOG_LEVEL(INFO, fmt, __VA_ARGS__) LOG_END
#define LOG_INFO(fmt, ...)  LOG_BEGIN(INFO) LOG_LEVEL(INFO, fmt, __VA_ARGS__) LOG_END
#define LOG_INFO_WITH_KEY(key, ...)  LOG_INFO_DO_NOT_USE_DIRECT_TRANSLATE_INFO_MSGS(ADF_PHRASE_INFO(key), __VA_ARGS__)
#define LOG_INFO_WITH_SIMPLE_FORMAT(fmt, ...) LOG_INFO_DO_NOT_USE_DIRECT_TRANSLATE_INFO_MSGS(fmt, __VA_ARGS__) 
#define LOG_INFO_WITH_TRANSLATED_FORMAT(fmt, ...) LOG_INFO_DO_NOT_USE_DIRECT_TRANSLATE_INFO_MSGS(fmt, __VA_ARGS__)

#define LOG_INFO_STRING(str)   LOG_BEGIN(INFO) LOG_LEVEL(INFO, str, nil) LOG_END
#define LOG_INFO_KEY(key)   LOG_INFO_STRING(ADF_PHRASE_INFO(key))


#define LOG_WARNING(fmt, ...) LOG_BEGIN(WARNING) LOG_LEVEL(WARNING, fmt, __VA_ARGS__) LOG_END
#define LOG_WARNING_WITH_KEY(key, ...)  LOG_WARNING(ADF_PHRASE_WARN(key), __VA_ARGS__)
#define LOG_WARNING_WITH_SIMPLE_FORMAT(fmt, ...) LOG_WARNING(fmt, __VA_ARGS__) 
#define LOG_WARNING_WITH_TRANSLATED_FORMAT(fmt, ...) LOG_WARNING(fmt, __VA_ARGS__)

#define LOG_WARNING_STRING(str)  LOG_BEGIN(WARNING) LOG_LEVEL(WARNING, str, nil) LOG_END
#define LOG_WARNING_KEY(key)   LOG_WARNING_STRING(ADF_PHRASE_WARN(key))


#define LOG_ERROR(fmt, ...) LOG_BEGIN(SEVERE) LOG_LEVEL(SEVERE, fmt, __VA_ARGS__) LOG_END
#define LOG_ERROR_WITH_KEY(key, ...)  LOG_ERROR(ADF_PHRASE_ERROR(key), __VA_ARGS__)
#define LOG_ERROR_WITH_SIMPLE_FORMAT(fmt, ...) LOG_ERROR(fmt, __VA_ARGS__)
#define LOG_ERROR_WITH_TRANSLATED_FORMAT(fmt, ...) LOG_ERROR(fmt, __VA_ARGS__)

#define LOG_ERROR_STRING(str)  LOG_BEGIN(SEVERE) LOG_LEVEL(SEVERE, str, nil) LOG_END
#define LOG_ERROR_KEY(key)   LOG_ERROR_STRING(ADF_PHRASE_ERROR(key))

#define LOG_TEST(fmt, ...) if ([[ADFCommandLineArgs getInstance] isRunningInTestMode]) {oraADFLogger *testLogger = [oraADFLogger getTestLogger]; if(INFO >= testLogger.level) {[testLogger logWithLevel:INFO andMethod:__PRETTY_FUNCTION__ andLine:__LINE__ andFormat:fmt, __VA_ARGS__]; }}

@interface oraADFLogger : NSObject 
{
    ADFLogLevel _logging_level;
    NSString* _packageName;
}

// The Determins if this session has a springboard 
@property(readonly) ADFLogLevel level;
@property(nonatomic,retain)NSString* logLineFormat;
@property(nonatomic,retain)NSArray* logLineTokens;
@property(readonly) NSString* packageName;

// Generates a log entry if the logging requestedLevel is configured to log
-(void) logWithLevel:(ADFLogLevel)level andMethod:(const char*) methodName andLine:(int) lineNum andFormat:(NSString*) format, ...;
-(void) logOutWithLevel:(ADFLogLevel)requestedLevel format:(NSString*)format andArgs: (va_list) argumentList classAndMethod:(NSString*) classAndMethod;
+(void) logWithoutComparingLogLevel:(NSString*)logger classAndMethod:(NSString*) classAndMethod format:(NSString*)format, ...;
+(void) printWithLevel:(NSString*)level logger:(NSString*)logger lineFormat:(NSString*)lineFormat lineTokens:(NSArray*)lineTokens format:(NSString*)format andArgs: (va_list) argumentList classAndMethod:(NSString*) classAndMethod;

+(oraADFLogger*) getLogger:(NSString*)packageName;
+(ADFLogLevel) defaultLoggerLevel;
+(NSString*) getLevelName:(ADFLogLevel)level;
+(oraADFLogger*) getDefaultLogger;
+(oraADFLogger*) getTestLogger;

// Allows us to turn on and off debugging
- (void) alterLevelToFinest;
- (void) resetLevel;

@end
