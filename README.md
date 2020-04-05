# LibIntrusion (WIP)
> A free runtime-modification library for macOS (x64)

## Prelude
`LibIntrusion` is my attempt at understanding the Objective-C runtime functionality. This can be considered a lightweight WIP objc-runtime wrapper.

> "just why"

Why not, it's fun poking around APIs and expanding your knowledge. I'm fully aware that method swizzling is not common practise (unless you're familiar with jailbreaking), but it's good to know and work with nevertheless.

## Usage
To create runtim extensions, download the dylib & header and include them in your Xcode project.
From this point forward you can design however you like:
- You can follow the Example and create on large file to test your injection
- You can split them up and design your hooks as you please since `LIInitialize`allows you to multi-init.

Hooks are either written in C or ObjC, although you will most likely use ObjC.

## Internals
These are my findings so far about the runtime behavior, so you can also follow along why this exactly works:
1. Before ANYTHING, the linker of choice (here `dyld`) will look for constructor/ deconstructor sections within the any `.dylib` and process it first during loadup. This is where `LIInitialize` comes into play:
By putting your hooks inside it, you effectively tell `dyld` _"Hey btw, how about you perform this for me real quick."_ and follow up with any variety of valid `LIHookMessage` et al.
2. _"Hooking"_ a method is a fancy way to describe the act of _replacing an existing implementation with another_. This might not be conclusive at first, but think about it this way:
In ObjC, a `Method` is (roughly speaking) a struct which joins a Selector _(Method **name**)_ and an *IMP*.  An *IMP* is just a function pointer to the actual implementation. Knowing this it becomes clear that you *should* be able to mix these around since all an ObjC `Method` is, is kinda like a table where the runtime quickly looks up which Implementation goes with which Selector. And indeed you can mix things around, since Selector and IMP are distinct from each other!
3. If you are thinking _"If I can replace existing methods, can I also ADD or REMOVE Methods at runtime?"_, you're getting it right. You can ADD and REMOVE Methods at runtime, LibIntrusion provides the `LIInjectMethod` for that -well, for adding Methods at least. Removing methods isn't something I'd suspect people want todo, however that's a taks for the reader if they're curious.
4. In case you have made iOS runtime modifications (aka "Tweaks"), you're familiar with all the magic. Writing in Logos abstracts alot of the actual work away, try running `Logos.pl` to see the code behind the scenes! You'll discover some pretty cool things!

 
## Anecdotes
- ObjC's runtime is a wonderful showcase and entry-point for anyone who's curious about how you can change behavior at runtime.
- The usages can vary from simple DRM breaking to fully customizing existing applications
- Designing the examples allowed me to use something I frankly think is awesome: `performSelector`
- MobileSubstrate's documentations were a solid resource to learn about this entirety
- Apple pls document XNU.

## Credits
- comex (substitute) & saurik (MobileSubstrate)
- StackOverflow
- Apple Developer Forums
