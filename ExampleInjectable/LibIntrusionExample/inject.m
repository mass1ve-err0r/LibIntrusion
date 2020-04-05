//
//  LibIntrusionExample.m
//  LibIntrusionExample
//
//  Created by Saadat Baig on 31.03.20.
//  Copyright © 2020 Saadat Baig. All rights reserved.
//

#import "LibIntrusion.h"
@class TestClass1;
@class TestClass2;

static int hook1() {
    printf("HOOKED WITH LIBINTRUSION\n");
    return 1998;
}

static BOOL hook2() {
    printf("HOOKED WITH LIBINTRUSION\n");
    return NO;
}

static void hook3() {
    printf("INJECTED METHOD; COURTESY LIBINTRUSION\n");
}

int (*orig1)(void);
BOOL (*orig2)(void);

LIInitialize(1) {
    printf("LibIntrusion v1.0 - INJECTED\n");
    Class targetClass1 = objc_getClass("TestClass1");
    SEL targetelector1 = sel_registerName("tc1InstanceMethod");
    LIHookMessage(targetClass1, targetelector1, (IMP)&hook1, (IMP *)&orig1);
}

LIInitialize(2) {
    Class targetClass2 = objc_getClass("TestClass2");
    SEL targetelector2 = sel_registerName("tc2InstanceMethod");
    LIHookMessage(targetClass2, targetelector2, (IMP)&hook2, (IMP *)&orig2);
    LIInjectMethod(NO, "TestClass1", "yeet", (IMP)&hook3);
}
