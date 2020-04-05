#ifndef LIBINTRUSION_LIBINTRUSION_H
#define LIBINTRUSION_LIBINTRUSION_H

#include <stdio.h>
#include <objc/runtime.h>
#include <CoreFoundation/CoreFoundation.h>
#define LIInitialize(x) __attribute__((constructor)) static void _LIInitialize_##x()

void LIHookIvar(const char * targetClass, const char *targetIvarName, void *replacement);
void LIHookMessage(Class targetClass, SEL targetSelector, IMP replacement, IMP* orig);
void LIInjectMethod(BOOL intoClass, const char* className, const char* selectorName, IMP func);
void LIInvoke(Class targetClass, SEL targetSelector);

#endif //LIBINTRUSION_LIBINTRUSION_H
