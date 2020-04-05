//
//  TestClass2.m
//  LIExample
//
//  Created by Saadat Baig on 31.03.20.
//  Copyright © 2020 Saadat Baig. All rights reserved.
//

#import "TestClass2.h"

@implementation TestClass2
@synthesize tc2Boolean;

- (instancetype)init
{
    self = [super init];
    if (self) {
        tc2Boolean = YES;
    }
    return self;
}

-(BOOL)tc2InstanceMethod {
    return tc2Boolean;
}

@end
