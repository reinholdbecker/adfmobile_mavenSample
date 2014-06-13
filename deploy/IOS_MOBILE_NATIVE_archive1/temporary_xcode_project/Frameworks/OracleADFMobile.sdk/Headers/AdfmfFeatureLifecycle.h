//
//  AdfmfFeatureLifecycle.h
//  OracleADFmcContainerLib
//
//  Created by Eric Jumper on 11/30/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>


/************************************************************************
 * Protocol: AdfmfFeatureLifecycle
 *
 * Purpose: This protocol is provided to allow a custom native view or 
 *    view controller to recieve notification when it is being activated
 *    or deactivated.
 *
 * Created: 30 November, 2011
 ************************************************************************/
@protocol AdfmfFeatureLifecycle <NSObject>
// This method is called when the feature is about to be displayed.  It is 
// a blocking call on the main thread.
- (void) activate;
// This method is called when the feature is about to be deactivated.  It is 
// a blocking call on the main thread.
- (void) deactivate;
@end
