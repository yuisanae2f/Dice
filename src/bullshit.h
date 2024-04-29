#pragma once
#ifndef AE2F_BULLSHIT_DEF
#define AE2F_BULLSHIT_DEF

// loop preprocessor
#define AE2F_FOR(id, start, cond, loopEnd, ...){\
start; \
id##loopStart: \
switch (cond) { case 0: goto id##le; default: break; } \
__VA_ARGS__; \
id##les: loopEnd; \
goto id##loopStart; \
id##le:; \
}

// while
#define AE2F_WHILE(id, cond, ...){ \
id##loopStart: id##les: \
switch (cond) { case 0: goto id##le; default: break; } \
__VA_ARGS__; id##le:; \
}

// continue
#define AE2F_CONTINUE(id) goto id##les;

// break
#define AE2F_BREAK(id) goto id##le;
#define AE2F_CONCAT(a, b) a##b

#endif // !AE2F_BULLSHIT_DEF

#ifdef AE2F_CPP
#include <exception>
namespace ae2f {
	namespace excep {
		class plain : std::exception {
			const char
				* a,
				* b;
		public:
			plain(const char* a, const char* b) : a(a), b(b) {}
			plain(std::exception e) : a(e.what()), b("") {}

			const char* what() noexcept { return a; }
			const char* url() noexcept { return b; }
		};
	}
}
#endif // AE2F_CPP