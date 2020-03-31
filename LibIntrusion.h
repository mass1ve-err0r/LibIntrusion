#ifndef LIBINTRUSION_LIBINTRUSION_H
#define LIBINTRUSION_LIBINTRUSION_H

#include <stdio.h>
#include <objc/runtime.h>

void LIHookIvar(Class targetClass, const char *targetIvarName, void *replacement);
void LIHookMessage(Class targetClass, SEL targetSelector, IMP replacement, IMP* orig);

#endif //LIBINTRUSION_LIBINTRUSION_H
