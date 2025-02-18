# norOS
my bare-bones kernel.
## How to build
### Building GCC cross compiler
For building norOS, you need to use Unix like utils. For me, im gonna use WSL

#### Step 1. Install dependencies

```sudo apt update```

```sudo apt install build-essential bison flex libgmp3-dev libmpc-dev libmpfr-dev texinfo xorriso grub-pc-bin grub-common```

#### Step 2. Create a new directory

```mkdir ~/x86_64-elf-cross```

```cd ~/x86_64-elf-cross```

#### Step 3. Download sources and extract them

```wget https://ftp.gnu.org/gnu/binutils/binutils-2.41.tar.xz```

```wget https://ftp.gnu.org/gnu/gcc/gcc-13.2.0/gcc-13.2.0.tar.xz```

```tar -xf binutils-2.41.tar.xz```

```tar -xf gcc-13.2.0.tar.xz```

#### Step 4. Build and install binutils, GCC

```mkdir build-binutils```

```cd build-binutils```

```../binutils-2.41/configure --target=x86_64-elf --prefix=/usr/local/cross --with-sysroot --disable-nls --disable-werror```

```make -j$(nproc)```

```sudo make install```

```cd ..```

##### Same thing for GCC

```mkdir build-gcc```

```cd build-gcc```

```../gcc-13.2.0/configure --target=x86_64-elf --prefix=/usr/local/cross --disable-nls --enable-languages=c,c++ --without-headers```

```make -j$(nproc) all-gcc```

```make -j$(nproc) all-target-libgcc```

```sudo make install-gcc```

```sudo make install-target-libgcc```

```cd ..```

#### Step 5. Update the path

```export PATH="/usr/local/cross/bin:$PATH"```

```echo 'export PATH="/usr/local/cross/bin:$PATH"' >> ~/.bashrc```

```source ~/.bashrc```


