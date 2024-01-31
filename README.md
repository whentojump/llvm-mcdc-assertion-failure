## Before

Point your `$PATH` to a recent mainline build and run:

```shell
./mcdc.sh
```

Symptom:

```text
Double check LLVM version:

clang version 19.0.0git (/path/to/llvm-project/clang c19436eec1c236cbe622c04e33f35f1f9478fa15)
Target: x86_64-unknown-linux-gnu
Thread model: posix
InstalledDir: /path/to/llvm-project/build/bin

Press any key to continue...

llvm-cov: /path/to/llvm-project/llvm/lib/ProfileData/Coverage/CoverageMapping.cpp:591: llvm::Error llvm::coverage::CoverageMapping::loadFunctionRecord(const llvm::coverage::CoverageMappingRecord&, llvm::IndexedInstrProfReader&): Assertion `NumConds == 0' failed.
PLEASE submit a bug report to https://github.com/llvm/llvm-project/issues/ and include the crash backtrace.
Stack dump:
0.	Program arguments: llvm-cov "llvm-cov show" --show-mcdc main -instr-profile main.profdata -output-dir=./garbage
 #0 0x00005587d0576aaf llvm::sys::PrintStackTrace(llvm::raw_ostream&, int) /path/to/llvm-project/llvm/lib/Support/Unix/Signals.inc:727:3
 #1 0x00005587d057479f llvm::sys::RunSignalHandlers() /path/to/llvm-project/llvm/lib/Support/Signals.cpp:105:20
 #2 0x00005587d0574af6 SignalHandler(int) /path/to/llvm-project/llvm/lib/Support/Unix/Signals.inc:413:1
 #3 0x00007f1e0970a520 (/lib/x86_64-linux-gnu/libc.so.6+0x42520)
 #4 0x00007f1e0975e9fc __pthread_kill_implementation ./nptl/pthread_kill.c:44:76
 #5 0x00007f1e0975e9fc __pthread_kill_internal ./nptl/pthread_kill.c:78:10
 #6 0x00007f1e0975e9fc pthread_kill ./nptl/pthread_kill.c:89:10
 #7 0x00007f1e0970a476 gsignal ./signal/../sysdeps/posix/raise.c:27:6
 #8 0x00007f1e096f07f3 abort ./stdlib/abort.c:81:7
 #9 0x00007f1e096f071b _nl_load_domain ./intl/loadmsgcat.c:1177:9
#10 0x00007f1e09701e96 (/lib/x86_64-linux-gnu/libc.so.6+0x39e96)
#11 0x00005587d060ecd2 bool llvm::DenseMapBase<llvm::DenseMap<unsigned long, llvm::SmallVector<unsigned int, 0u>, llvm::DenseMapInfo<unsigned long, void>, llvm::detail::DenseMapPair<unsigned long, llvm::SmallVector<unsigned int, 0u>>>, unsigned long, llvm::SmallVector<unsigned int, 0u>, llvm::DenseMapInfo<unsigned long, void>, llvm::detail::DenseMapPair<unsigned long, llvm::SmallVector<unsigned int, 0u>>>::LookupBucketFor<unsigned long>(unsigned long const&, llvm::detail::DenseMapPair<unsigned long, llvm::SmallVector<unsigned int, 0u>> const*&) const /path/to/llvm-project/llvm/include/llvm/ADT/DenseMap.h:665:7
#12 0x00005587d060ecd2 bool llvm::DenseMapBase<llvm::DenseMap<unsigned long, llvm::SmallVector<unsigned int, 0u>, llvm::DenseMapInfo<unsigned long, void>, llvm::detail::DenseMapPair<unsigned long, llvm::SmallVector<unsigned int, 0u>>>, unsigned long, llvm::SmallVector<unsigned int, 0u>, llvm::DenseMapInfo<unsigned long, void>, llvm::detail::DenseMapPair<unsigned long, llvm::SmallVector<unsigned int, 0u>>>::LookupBucketFor<unsigned long>(unsigned long const&, llvm::detail::DenseMapPair<unsigned long, llvm::SmallVector<unsigned int, 0u>>*&) /path/to/llvm-project/llvm/include/llvm/ADT/DenseMap.h:689:24
#13 0x00005587d060ecd2 llvm::detail::DenseMapPair<unsigned long, llvm::SmallVector<unsigned int, 0u>>* llvm::DenseMapBase<llvm::DenseMap<unsigned long, llvm::SmallVector<unsigned int, 0u>, llvm::DenseMapInfo<unsigned long, void>, llvm::detail::DenseMapPair<unsigned long, llvm::SmallVector<unsigned int, 0u>>>, unsigned long, llvm::SmallVector<unsigned int, 0u>, llvm::DenseMapInfo<unsigned long, void>, llvm::detail::DenseMapPair<unsigned long, llvm::SmallVector<unsigned int, 0u>>>::InsertIntoBucketImpl<unsigned long>(unsigned long const&, unsigned long const&, llvm::detail::DenseMapPair<unsigned long, llvm::SmallVector<unsigned int, 0u>>*) /path/to/llvm-project/llvm/include/llvm/ADT/DenseMap.h:609:22
#14 0x00005587d060ecd2 llvm::detail::DenseMapPair<unsigned long, llvm::SmallVector<unsigned int, 0u>>* llvm::DenseMapBase<llvm::DenseMap<unsigned long, llvm::SmallVector<unsigned int, 0u>, llvm::DenseMapInfo<unsigned long, void>, llvm::detail::DenseMapPair<unsigned long, llvm::SmallVector<unsigned int, 0u>>>, unsigned long, llvm::SmallVector<unsigned int, 0u>, llvm::DenseMapInfo<unsigned long, void>, llvm::detail::DenseMapPair<unsigned long, llvm::SmallVector<unsigned int, 0u>>>::InsertIntoBucket<unsigned long>(llvm::detail::DenseMapPair<unsigned long, llvm::SmallVector<unsigned int, 0u>>*, unsigned long&&) /path/to/llvm-project/llvm/include/llvm/ADT/DenseMap.h:574:37
#15 0x00005587d060ecd2 llvm::DenseMapBase<llvm::DenseMap<unsigned long, llvm::SmallVector<unsigned int, 0u>, llvm::DenseMapInfo<unsigned long, void>, llvm::detail::DenseMapPair<unsigned long, llvm::SmallVector<unsigned int, 0u>>>, unsigned long, llvm::SmallVector<unsigned int, 0u>, llvm::DenseMapInfo<unsigned long, void>, llvm::detail::DenseMapPair<unsigned long, llvm::SmallVector<unsigned int, 0u>>>::FindAndConstruct(unsigned long&&) /path/to/llvm-project/llvm/include/llvm/ADT/DenseMap.h:365:29
#16 0x00005587d060ecd2 llvm::DenseMapBase<llvm::DenseMap<unsigned long, llvm::SmallVector<unsigned int, 0u>, llvm::DenseMapInfo<unsigned long, void>, llvm::detail::DenseMapPair<unsigned long, llvm::SmallVector<unsigned int, 0u>>>, unsigned long, llvm::SmallVector<unsigned int, 0u>, llvm::DenseMapInfo<unsigned long, void>, llvm::detail::DenseMapPair<unsigned long, llvm::SmallVector<unsigned int, 0u>>>::operator[](unsigned long&&) /path/to/llvm-project/llvm/include/llvm/ADT/DenseMap.h:369:28
#17 0x00005587d060ecd2 llvm::coverage::CoverageMapping::loadFunctionRecord(llvm::coverage::CoverageMappingRecord const&, llvm::IndexedInstrProfReader&) /path/to/llvm-project/llvm/lib/ProfileData/Coverage/CoverageMapping.cpp:660:74
#18 0x00005587d060efd0 llvm::Error::setChecked(bool) /path/to/llvm-project/llvm/include/llvm/Support/Error.h:307:22
#19 0x00005587d060efd0 llvm::Error::operator bool() /path/to/llvm-project/llvm/include/llvm/Support/Error.h:239:15
#20 0x00005587d060efd0 llvm::coverage::CoverageMapping::loadFromReaders(llvm::ArrayRef<std::unique_ptr<llvm::coverage::CoverageMappingReader, std::default_delete<llvm::coverage::CoverageMappingReader>>>, llvm::IndexedInstrProfReader&, llvm::coverage::CoverageMapping&) /path/to/llvm-project/llvm/lib/ProfileData/Coverage/CoverageMapping.cpp:681:71
#21 0x00005587d060f629 llvm::Error::setChecked(bool) /path/to/llvm-project/llvm/include/llvm/Support/Error.h:307:22
#22 0x00005587d060f629 llvm::Error::operator bool() /path/to/llvm-project/llvm/include/llvm/Support/Error.h:239:15
#23 0x00005587d060f629 llvm::coverage::CoverageMapping::loadFromFile(llvm::StringRef, llvm::StringRef, llvm::StringRef, llvm::IndexedInstrProfReader&, llvm::coverage::CoverageMapping&, bool&, llvm::SmallVectorImpl<llvm::SmallVector<unsigned char, 10u>>*) /path/to/llvm-project/llvm/lib/ProfileData/Coverage/CoverageMapping.cpp:740:66
#24 0x00005587d06100cd llvm::Error::setChecked(bool) /path/to/llvm-project/llvm/include/llvm/Support/Error.h:307:22
#25 0x00005587d06100cd llvm::Error::operator bool() /path/to/llvm-project/llvm/include/llvm/Support/Error.h:239:15
#26 0x00005587d06100cd llvm::coverage::CoverageMapping::load(llvm::ArrayRef<llvm::StringRef>, llvm::StringRef, llvm::vfs::FileSystem&, llvm::ArrayRef<llvm::StringRef>, llvm::StringRef, llvm::object::BuildIDFetcher const*, bool) /path/to/llvm-project/llvm/lib/ProfileData/Coverage/CoverageMapping.cpp:768:80
#27 0x00005587d036c352 llvm::Expected<std::unique_ptr<llvm::coverage::CoverageMapping, std::default_delete<llvm::coverage::CoverageMapping>>>::takeError() /path/to/llvm-project/llvm/include/llvm/Support/Error.h:603:15
#28 0x00005587d036c352 (anonymous namespace)::CodeCoverageTool::load() /path/to/llvm-project/llvm/tools/llvm-cov/CodeCoverage.cpp:486:41
#29 0x00005587d0370364 (anonymous namespace)::CodeCoverageTool::doShow(int, char const**, llvm::function_ref<int (int, char const**)>) (.constprop.0) /path/to/llvm-project/llvm/tools/llvm-cov/CodeCoverage.cpp:1143:3
#30 0x00005587d0376110 (anonymous namespace)::CodeCoverageTool::run((anonymous namespace)::CodeCoverageTool::Command, int, char const**) /path/to/llvm-project/llvm/tools/llvm-cov/CodeCoverage.cpp:980:18
#31 0x00005587d0376a1f showMain(int, char const**) /path/to/llvm-project/llvm/tools/llvm-cov/CodeCoverage.cpp:1348:1
#32 0x00005587d035809d std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string() /usr/include/c++/11/bits/basic_string.h:672:19
#33 0x00005587d035809d main /path/to/llvm-project/llvm/tools/llvm-cov/llvm-cov.cpp:82:5
#34 0x00007f1e096f1d90 __libc_start_call_main ./csu/../sysdeps/nptl/libc_start_call_main.h:58:16
#35 0x00007f1e096f1e40 call_init ./csu/../csu/libc-start.c:128:20
#36 0x00007f1e096f1e40 __libc_start_main ./csu/../csu/libc-start.c:379:5
#37 0x00005587d0357635 _start (/path/to/llvm-project/build/bin/llvm-cov+0x27e635)
./mcdc.sh: line 26: 433149 Aborted                 llvm-cov show --show-mcdc $bin -instr-profile $bin.profdata -output-dir=./garbage
```

## After

Point your `$PATH` to a patched build and run:

```shell
./mcdc.sh
```

Or you can run:

```shell
./mcdc2.sh
```

which outputs the results directly to the terminal. Example output:

```text
Double check LLVM version:

clang version 19.0.0git (/path/to/llvm-project/clang cd5a33851187c872c0de7a766528be097bcc68ad)
Target: x86_64-unknown-linux-gnu
Thread model: posix
InstalledDir: /path/to/llvm-project/build/bin

Press any key to continue...

/users/wtj/workdir/llvm-mcdc-assertion-failure/foo.h:
    1|      9|#define S_IFMT  00170000
    2|       |#define S_IFSOCK 0140000
    3|       |#define S_IFLNK	 0120000
    4|       |#define S_IFREG  0100000
    5|       |#define S_IFBLK  0060000
    6|       |#define S_IFDIR  0040000
    7|       |#define S_IFCHR  0020000
    8|       |#define S_IFIFO  0010000
    9|       |#define S_ISUID  0004000
   10|       |#define S_ISGID  0002000
   11|       |#define S_ISVTX  0001000
   12|       |
   13|       |#define S_ISLNK(m)	(((m) & S_IFMT) == S_IFLNK)
   14|     18|#define S_ISREG(m)	(((m) & S_IFMT) == S_IFREG)
   15|      9|#define S_ISDIR(m)	(((m) & S_IFMT) == S_IFDIR)
   16|       |#define S_ISCHR(m)	(((m) & S_IFMT) == S_IFCHR)
   17|       |#define S_ISBLK(m)	(((m) & S_IFMT) == S_IFBLK)
   18|      1|#define S_ISFIFO(m)	(((m) & S_IFMT) == S_IFIFO)
   19|      1|#define S_ISSOCK(m)	(((m) & S_IFMT) == S_IFSOCK)
   20|      1|
   21|      1|#define S_IRWXU 00700
   22|      1|#define S_IRUSR 00400
   23|       |#define S_IWUSR 00200
   24|       |#define S_IXUSR 00100
   25|      1|
  ------------------
  |---> MC/DC Decision Region (25:9) to (25:33)
  |
  |  Number of Conditions: 3
  |     Condition C1 --> (25:9)
  |     Condition C2 --> (25:19)
  |     Condition C3 --> (25:28)
  |
  |  Executed MC/DC Test Vectors:
  |
  |     C1, C2, C3    Result
  |  1 { F,  -,  -  = F      }
  |
  |  C1-Pair: not covered
  |  C2-Pair: not covered
  |  C3-Pair: not covered
  |  MC/DC Coverage for Decision: 0.00%
  |
  ------------------
   26|      0|#define S_IRWXG 00070
   27|      0|#define S_IRGRP 00040
   28|       |#define S_IWGRP 00020
   29|      1|#define S_IXGRP 00010
   30|      1|
   31|       |#define S_IRWXO 00007
   32|       |#define S_IROTH 00004
   33|       |#define S_IWOTH 00002
   34|       |#define S_IXOTH 00001

/users/wtj/workdir/llvm-mcdc-assertion-failure/main.c:
    1|       |#include "foo.h"
    2|       |
    3|       |// The example comes from https://elixir.bootlin.com/linux/v5.15.127/source/fs/open.c#L804
    4|       |// Note
    5|       |// 1. In order to trigger assertion failure, there should be one more
    6|       |//    MCDCDecisionRegion after the ill region.
    7|       |// 2. Somehow in kernel the same code can trigger Clang warning
    8|       |//
    9|       |//      warning: unsupported MC/DC boolean expression; contains an operation
   10|       |//      with a nested boolean expression. Expression will not be covered
   11|       |//
   12|       |//    but here we cannot unless deliberately increase the nesting level.
   13|       |
   14|       |int main(void) {
   15|       |    int i;
   16|       |
   17|       |    // *The* MCDCDecisionRegion that causes trouble
   18|     10|    for (i = 1; i < 10; i++) {
   19|      9|        if (S_ISREG(i) || S_ISDIR(i)) {
  ------------------
  |---> MC/DC Decision Region (19:13) to (19:34)
  |
  |  Number of Conditions: 2
  |     Condition C1 --> (14:20)
  |     Condition C2 --> (15:20)
  |
  |  Executed MC/DC Test Vectors:
  |
  |     C1, C2    Result
  |  1 { F,  F  = F      }
  |
  |  C1-Pair: not covered
  |  C2-Pair: not covered
  |  MC/DC Coverage for Decision: 0.00%
  |
  ------------------
   20|      0|            continue;
   21|      0|        }
   22|      9|    }
   23|       |
   24|       |    // One more MCDCDecisionRegion to trigger the assertion
   25|      1|    if (i < 10 && i > 0 && i < 8) {
   26|       |        return 1;
   27|       |    }
   28|       |
   29|       |    return 0;
   30|       |}
```
