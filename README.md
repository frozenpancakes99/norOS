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
