//
//  iJava.h
//  POC_0
//
//  Created by Anki Nelaturu on 5/1/11.
//  Copyright 2011 Oracle. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


extern int JNI_CreateJavaVM(void**, void**, void*);
extern void ansiJavaMain();

@interface iJava : NSObject {
	
}

+(void) startJava;

@end

