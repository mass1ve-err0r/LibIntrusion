#ifndef LIBINTRUSION_LIBINTRUSION_H
#define LIBINTRUSION_LIBINTRUSION_H

#include <stdio.h>
#include <objc/runtime.h>
#define LIInitialize __attribute__((constructor)) static void ctor()

void LIHookIvar(Class targetClass, const char *targetIvarName, void *replacement);
void LIHookMessage(Class targetClass, SEL targetSelector, IMP replacement, IMP* orig);
void LIInjectMethod(Class targetClass, SEL selectorName, IMP injectableFunc);

#endif //LIBINTRUSION_LIBINTRUSION_H
