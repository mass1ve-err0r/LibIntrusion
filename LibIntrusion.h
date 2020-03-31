#ifndef LIBINTRUSION_LIBINTRUSION_H
#define LIBINTRUSION_LIBINTRUSION_H

#include <stdio.h>
#include <objc/runtime.h>

void LIHookMessage(Class targetClass, SEL targetSelector, IMP replacement, IMP* orig);

#endif //LIBINTRUSION_LIBINTRUSION_H
