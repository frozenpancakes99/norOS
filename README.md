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
