//
//  TestClass1.m
//  LIExample
//
//  Created by Saadat Baig on 31.03.20.
//  Copyright © 2020 Saadat Baig. All rights reserved.
//

#import "TestClass1.h"

@implementation TestClass1
@synthesize tc1Integer;

- (instancetype)init
{
    self = [super init];
    if (self) {
        tc1Integer = 10;
    }
    return self;
}

+(void)tc1ClassMethod {
    NSLog(@"[TC1]: We have called TestClass1's CLASS METHOD");
}

-(int)tc1InstanceMethod {
    return tc1Integer;
}

@end

