//
//  SecureFeature.h
//  OracleSecurityLib
//
//  Created by Tadashi Enomori on 12/8/11.
//  Copyright 2011 Oracle. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import "ADFAuthenticationContext.h"

@protocol SecureFeature <NSObject>

-(id)           getAuthContext: (id) authListner;

-(void)         showLoginFeature;

-(NSString *)   getAccessControlConnRefId;

-(NSArray *)    getPrivilegeFilterList;

-(void)         cancelActivation:(NSString*) featureActivationId;

-(void)         resumeActivation:(NSString*) featureActivationId;

@end
