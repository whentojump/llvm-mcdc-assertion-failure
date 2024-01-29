```shell
./mcdc.sh
```

```text
Double check LLVM version:

clang version 19.0.0git (https://github.com/llvm/llvm-project.git 2d0d65b3babecbd339b01fdf7da29b8dfd69f889)
Target: x86_64-unknown-linux-gnu
Thread model: posix
InstalledDir: /users/wtj/workdir/llvm-latest/llvm/build-mainline-19.x/bin

Press any key to continue...

llvm-cov: /users/wtj/workdir/llvm-latest/llvm/llvm/lib/ProfileData/Coverage/CoverageMapping.cpp:651: llvm::Error llvm::coverage::CoverageMapping::loadFunctionRecord(const llvm::coverage::CoverageMappingRecord&, llvm::IndexedInstrProfReader&): Assertion `NumConds == 0' failed.
PLEASE submit a bug report to https://github.com/llvm/llvm-project/issues/ and include the crash backtrace.
Stack dump:
0.	Program arguments: llvm-cov "llvm-cov show" --show-mcdc main -instr-profile main.profdata -output-dir=./garbage
 #0 0x0000555e8368fc7f llvm::sys::PrintStackTrace(llvm::raw_ostream&, int) /users/wtj/workdir/llvm-latest/llvm/llvm/lib/Support/Unix/Signals.inc:727:3
 #1 0x0000555e8368d96f llvm::sys::RunSignalHandlers() /users/wtj/workdir/llvm-latest/llvm/llvm/lib/Support/Signals.cpp:105:20
 #2 0x0000555e8368dcc6 SignalHandler(int) /users/wtj/workdir/llvm-latest/llvm/llvm/lib/Support/Unix/Signals.inc:413:1
 #3 0x00007fd0dbfad520 (/lib/x86_64-linux-gnu/libc.so.6+0x42520)
 #4 0x00007fd0dc0019fc __pthread_kill_implementation ./nptl/pthread_kill.c:44:76
 #5 0x00007fd0dc0019fc __pthread_kill_internal ./nptl/pthread_kill.c:78:10
 #6 0x00007fd0dc0019fc pthread_kill ./nptl/pthread_kill.c:89:10
 #7 0x00007fd0dbfad476 gsignal ./signal/../sysdeps/posix/raise.c:27:6
 #8 0x00007fd0dbf937f3 abort ./stdlib/abort.c:81:7
 #9 0x00007fd0dbf9371b _nl_load_domain ./intl/loadmsgcat.c:1177:9
#10 0x00007fd0dbfa4e96 (/lib/x86_64-linux-gnu/libc.so.6+0x39e96)
#11 0x0000555e837281e4 llvm::Expected<llvm::BitVector>::assertIsChecked() const /users/wtj/workdir/llvm-latest/llvm/llvm/include/llvm/Support/Error.h:718:29
#12 0x0000555e837281e4 llvm::Expected<llvm::BitVector>::~Expected() /users/wtj/workdir/llvm-latest/llvm/llvm/include/llvm/Support/Error.h:555:20
#13 0x0000555e837281e4 llvm::coverage::CoverageMapping::loadFunctionRecord(llvm::coverage::CoverageMappingRecord const&, llvm::IndexedInstrProfReader&) /users/wtj/workdir/llvm-latest/llvm/llvm/lib/ProfileData/Coverage/CoverageMapping.cpp:703:7
#14 0x0000555e83728490 llvm::Error::setChecked(bool) /users/wtj/workdir/llvm-latest/llvm/llvm/include/llvm/Support/Error.h:307:22
#15 0x0000555e83728490 llvm::Error::operator bool() /users/wtj/workdir/llvm-latest/llvm/llvm/include/llvm/Support/Error.h:239:15
#16 0x0000555e83728490 llvm::coverage::CoverageMapping::loadFromReaders(llvm::ArrayRef<std::unique_ptr<llvm::coverage::CoverageMappingReader, std::default_delete<llvm::coverage::CoverageMappingReader>>>, llvm::IndexedInstrProfReader&, llvm::coverage::CoverageMapping&) /users/wtj/workdir/llvm-latest/llvm/llvm/lib/ProfileData/Coverage/CoverageMapping.cpp:741:71
#17 0x0000555e83728ae9 llvm::Error::setChecked(bool) /users/wtj/workdir/llvm-latest/llvm/llvm/include/llvm/Support/Error.h:307:22
#18 0x0000555e83728ae9 llvm::Error::operator bool() /users/wtj/workdir/llvm-latest/llvm/llvm/include/llvm/Support/Error.h:239:15
#19 0x0000555e83728ae9 llvm::coverage::CoverageMapping::loadFromFile(llvm::StringRef, llvm::StringRef, llvm::StringRef, llvm::IndexedInstrProfReader&, llvm::coverage::CoverageMapping&, bool&, llvm::SmallVectorImpl<llvm::SmallVector<unsigned char, 10u>>*) /users/wtj/workdir/llvm-latest/llvm/llvm/lib/ProfileData/Coverage/CoverageMapping.cpp:800:66
#20 0x0000555e8372958d llvm::Error::setChecked(bool) /users/wtj/workdir/llvm-latest/llvm/llvm/include/llvm/Support/Error.h:307:22
#21 0x0000555e8372958d llvm::Error::operator bool() /users/wtj/workdir/llvm-latest/llvm/llvm/include/llvm/Support/Error.h:239:15
#22 0x0000555e8372958d llvm::coverage::CoverageMapping::load(llvm::ArrayRef<llvm::StringRef>, llvm::StringRef, llvm::vfs::FileSystem&, llvm::ArrayRef<llvm::StringRef>, llvm::StringRef, llvm::object::BuildIDFetcher const*, bool) /users/wtj/workdir/llvm-latest/llvm/llvm/lib/ProfileData/Coverage/CoverageMapping.cpp:828:80
#23 0x0000555e83485352 llvm::Expected<std::unique_ptr<llvm::coverage::CoverageMapping, std::default_delete<llvm::coverage::CoverageMapping>>>::takeError() /users/wtj/workdir/llvm-latest/llvm/llvm/include/llvm/Support/Error.h:603:15
#24 0x0000555e83485352 (anonymous namespace)::CodeCoverageTool::load() /users/wtj/workdir/llvm-latest/llvm/llvm/tools/llvm-cov/CodeCoverage.cpp:486:41
#25 0x0000555e83489364 (anonymous namespace)::CodeCoverageTool::doShow(int, char const**, llvm::function_ref<int (int, char const**)>) (.constprop.0) /users/wtj/workdir/llvm-latest/llvm/llvm/tools/llvm-cov/CodeCoverage.cpp:1143:3
#26 0x0000555e8348f110 (anonymous namespace)::CodeCoverageTool::run((anonymous namespace)::CodeCoverageTool::Command, int, char const**) /users/wtj/workdir/llvm-latest/llvm/llvm/tools/llvm-cov/CodeCoverage.cpp:980:18
#27 0x0000555e8348fa1f showMain(int, char const**) /users/wtj/workdir/llvm-latest/llvm/llvm/tools/llvm-cov/CodeCoverage.cpp:1348:1
#28 0x0000555e8347109d std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string() /usr/include/c++/11/bits/basic_string.h:672:19
#29 0x0000555e8347109d main /users/wtj/workdir/llvm-latest/llvm/llvm/tools/llvm-cov/llvm-cov.cpp:82:5
#30 0x00007fd0dbf94d90 __libc_start_call_main ./csu/../sysdeps/nptl/libc_start_call_main.h:58:16
#31 0x00007fd0dbf94e40 call_init ./csu/../csu/libc-start.c:128:20
#32 0x00007fd0dbf94e40 __libc_start_main ./csu/../csu/libc-start.c:379:5
#33 0x0000555e83470635 _start (/users/wtj/workdir/llvm-latest/llvm/build-mainline-19.x/bin/llvm-cov+0x27d635)
./mcdc.sh: line 26: 207223 Aborted                 llvm-cov show --show-mcdc $bin -instr-profile $bin.profdata -output-dir=./garbage
```
