# bfmealloc_alloconly

Alloc-only subset of `../bfmealloc`: just `stl/_alloc.h` (the raw byte
allocator at 0x000307F0 plus `::free` deallocation), without that shim's
`_algobase.h` (`__copy_trivial` out-of-line at 0x000179B0) and
`_uninitialized.h` (`__forceinline` dispatch) changes.

Why the split exists: trivial-type `vector<T>::_M_insert_overflow` bodies
such as `vector<int>` at 0x006887F0 carry the direct allocator call
(`push 0 / push <bytes> / call 0x000307F0`) AND stock inline copies
(memmove import at 0xBBA688 plus an inlined dword loop). The full bfmealloc
emits `call 0x000179B0` for those copies (170B here vs 217B retail), while
stock headers emit the node allocator (`cmp <bytes>,0x80` plus the free-list
call; 265B). Neither matches alone; the alloc-only include gives the direct
allocator with stock copies.

Nontrivial element families (e.g. `Rva001D28F0Element`, `void*` at /Od)
never reach `__copy_trivial`, so they stay on the full `../bfmealloc`.
This directory is opt-in per TU via `/Ireference/shims/bfmealloc_alloconly`
and affects nothing already landed.
