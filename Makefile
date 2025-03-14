DOCS_DIR := docs
OUTPUT_DIR := pdf

kernel_source_files := $(shell find source/kernel -name *.c)
kernel_object_files := $(patsubst source/kernel/%.c, build/kernel/%.o, $(kernel_source_files))

x86_64_c_source_files := $(shell find source/x86_64 -name *.c)
x86_64_c_object_files := $(patsubst source/x86_64/%.c, build/x86_64/%.o, $(x86_64_c_source_files))

x86_64_asm_source_files := $(shell find source/x86_64 -name *.asm)
x86_64_asm_object_files := $(patsubst source/x86_64/%.asm, build/x86_64/%.o, $(x86_64_asm_source_files))

x86_64_object_files := $(x86_64_c_object_files) $(x86_64_asm_object_files)

# Create build directories
$(shell mkdir -p build/kernel build/x86_64)

# Kernel C files compilation
$(kernel_object_files): build/kernel/%.o : source/kernel/%.c
	mkdir -p $(dir $@)
	x86_64-elf-gcc -c -I source/lib -ffreestanding -nostdlib $< -o $@

# x86_64 C files compilation
$(x86_64_c_object_files): build/x86_64/%.o : source/x86_64/%.c
	mkdir -p $(dir $@)
	x86_64-elf-gcc -c -I source/lib -ffreestanding -nostdlib $< -o $@

# x86_64 Assembly files compilation
$(x86_64_asm_object_files): build/x86_64/%.o : source/x86_64/%.asm
	mkdir -p $(dir $@)
	nasm -f elf64 $< -o $@

.PHONY: kernel
kernel: $(kernel_object_files) $(x86_64_object_files)
	mkdir -p dist/x86_64 && \
	x86_64-elf-ld -n -o dist/x86_64/kernel.bin -T targets/x86_64/linker.ld $(kernel_object_files) $(x86_64_object_files) && \
	cp dist/x86_64/kernel.bin targets/x86_64/iso/boot/kernel.bin && \
	mkdir -p targets/x86_64/iso/boot/grub && \
	grub-mkrescue -o dist/x86_64/kernel.iso targets/x86_64/iso


.PHONY: pdfdocs
pdfdocs:
	@rm -rf $(OUTPUT_DIR)/*.pdf
	@mkdir -p $(OUTPUT_DIR)
	@find $(DOCS_DIR) -name '*.rst' | while read file; do \
		filename=$$(basename $$file .rst); \
		rst2pdf $$file -o $(OUTPUT_DIR)/$$filename.pdf || exit 1; \
	done
