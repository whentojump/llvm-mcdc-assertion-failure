#include "foo.h"

// The example comes from https://elixir.bootlin.com/linux/v5.15.127/source/fs/open.c#L804
// Note
// 1. In order to trigger assertion failure, there should be one more
//    MCDCDecisionRegion after the ill region.
// 2. Somehow in kernel the same code can trigger Clang warning
//
//      warning: unsupported MC/DC boolean expression; contains an operation
//      with a nested boolean expression. Expression will not be covered
//
//    but here we cannot unless deliberately increase the nesting level.

int main(void) {
    int i;

    // *The* MCDCDecisionRegion that causes trouble
    for (i = 1; i < 10; i++) {
        if (S_ISREG(i) || S_ISDIR(i)) {
            continue;
        }
    }

    // One more MCDCDecisionRegion to trigger the assertion
    if (i < 10 && i > 0 && i < 8) {
        return 1;
    }

    return 0;
}
