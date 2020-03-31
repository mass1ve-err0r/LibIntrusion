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

void LIHookIvar(Class targetClass, const char *targetIvarName, void *replacement) {
    object_setInstanceVariable(targetClass, targetIvarName, replacement);
}