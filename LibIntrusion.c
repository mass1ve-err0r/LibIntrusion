/*
 * LibIntrusion - A hooking library for x86_64 macOS.
 * Having fun with the runtime |
 */

#include "LibIntrusion.h"

/**
 * This is somewhat analogous to Substrate's "MSHookMessageEx".
 * It doesn't have the same "Magic" as Substrate if multipe dylibs injected target the same message
 *
 * Will figure that out eventually, perhaps thats a job for the injector to take care of.
 */
void LIHookMessage(Class targetClass, SEL targetSelector, IMP replacement, IMP* orig) {
    Method origMethod;
    if (class_respondsToSelector(targetClass, targetSelector)) {
        origMethod = class_getInstanceMethod(targetClass, targetSelector);
    } else {
        origMethod = class_getClassMethod(targetClass, targetSelector);
    }
    /*
     * This is another way of doing the objc hook from what I have gathered.
     * Not exactly sure how this differs, but this will also yield a fptr to the original implementation.
    const char *types = method_getTypeEncoding(origMethod);
    *orig = class_replaceMethod(targetClass, targetSelector, replacement, types);
    */
    *orig = method_setImplementation(origMethod, replacement);
}

/**
 * This should be analogous to "MSHookIvar", although iirc MS gets back the Ivar's value.
 * That could be added later/ revamped.
 */
void LIHookIvar(Class targetClass, const char *targetIvarName, void *replacement) {
    object_setInstanceVariable(targetClass, targetIvarName, replacement);
}

/**
 * Not sure if MS has something like this (perhaps with MSClassPair?), but I figured this would be dope to have!
 * You don't need to get the protoype c-string, LIInjectMethod does it for you!
 */
void LIInjectMethod(Class targetClass, SEL selectorName, IMP injectableFunc) {
    Method tramp = NULL;
    method_setImplementation(tramp, injectableFunc);
    const char *IMPproto = method_getTypeEncoding(tramp);
    class_addMethod(targetClass, selectorName, injectableFunc, IMPproto);
}
