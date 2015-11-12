# raiiBuffer
Short little RAII buffer class that attempts to help reduce the amount of memory allocations. If you need a pool of memories, you can create a vector of these buffers. When you're not using one, you can resize it to whatever size you need. It keeps an average size for the buffer and if you need a smaller size, it'll keep it at least the average size.
