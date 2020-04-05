//
//  main.m
//  LIExample
//
//  Created by Saadat Baig on 31.03.20.
//  Copyright © 2020 Saadat Baig. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "TestClass1.h"
#import "TestClass2.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSLog(@"[*]: Hello World from a victim program! Let's create some objects!");
        TestClass1 *tc1 = TestClass1.alloc.init;    // or [[TestClass1 alloc] init]
        TestClass2 *tc2 = TestClass2.alloc.init;
        
        /// Demo 1.1: Class Method of TC1
        NSLog(@"[+]: Let's call TestClass1's Class Method!");
        TestClass1.tc1ClassMethod;
        /// Demo 1.2: Instance Method of TC1 -> INT
        NSLog(@"[+]: Now TestClass1's Instance Method!");
        int rv1 = tc1.tc1InstanceMethod;
        NSLog(@"[=]: Expecting return Value: 10 | real value: %d", rv1);
        
        /// Demo 2: Instance Method of TC2 -> BOOL
        NSLog(@"[+]: Let's call TestClass2's Instance Method!");
        BOOL rv2 = tc2.tc2InstanceMethod;
        NSLog(@"[*]: Expecting YES | real value: %s", rv2 ? "YES" : "NO");
        
        /// Demo 3.1: Injecting Methods to Class, here TestClass1
        NSLog(@"[+]: How about a call from an instance method which is not defined here, but injected?");
        @try {
            [TestClass1 performSelector:@selector(yeet)];
        } @catch (NSException *exception) {
            NSLog(@"[!]: Could not execute because there is no such selector for the class!");
        } @finally {/*code*/}
        /// Demo 3.2: Injecting Methods to Instances, here TestClass1's instance tc1
        @try {
            [tc1 performSelector:@selector(yeet)];
        } @catch (NSException *exception) {
            NSLog(@"[!]: Could not execute because there is no such selector for the instance!");
        } @finally {/*code*/}
        
        NSLog(@"[-]: That's all from the victim, exiting now!");
    }
    return 0;
}
