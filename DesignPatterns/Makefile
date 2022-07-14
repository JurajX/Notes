SHELL = /bin/zsh
# project constants
comma := ,
empty :=
space := ${empty} ${empty}

src_dir := .
build := build

project_path := ${CURDIR}
src_path := ${project_path}/${src_dir}
docs_path := ${project_path}/${build}/${docs_dir}

extensions := (c|cc|cxx|cpp|c\+\+|h|hh|hxx|hpp|h\+\+)
exclude_dirs := (${build}|\.git)
srcs := $(shell find -E ${src_path} -type f -regex ".*\.${extensions}")
project_files := $(shell \
    find -E ${project_path}\
        -type d -regex "${project_path}/${exclude_dirs}" -prune -o\
        -type f -regex ".*\.${extensions}" -print)

# recursive variables
build_dir = ${build}/${COMPILER}/${BUILD_TYPE}
objs = $(shell find -E ${build_dir} -type f -regex ".*\.o")

# 'gcc' or 'clang'; gcc is the default
COMPILER ?= gcc
# 'Release' or 'Debug'; Debug is the default
BUILD_TYPE ?= Release

# set-up compilers
ifneq (${COMPILER}, gcc)
    ifneq (${COMPILER}, clang)
        $(error Unknown compiler '${COMPILER}'. Must be 'gcc' or 'clang')
    endif
endif
not_gcc = $(subst gcc,${empty},${COMPILER})
C_COMPILER = $(if ${not_gcc},clang,gcc-11)
CXX_COMPILER = $(if ${not_gcc},clang++,g++-11)

# ------------------------------------------ Needs to be adjusted for build on other systems
# expected programs in PATH:
#    make, cmake, clang, clang-format, run-clang-tidy, llvm-profdata, llvm-cov, gcc-11, gcov, lcov

# needed for OS X to avoid Apple clang
gcov := /usr/local/opt/gcc@11/bin/gcov-11
llvm_path := /usr/local/opt/llvm
path := ${PATH}
export PATH = $(if ${not_gcc},${llvm_path}/bin:${path},${path})
export LDFLAGS = $(if ${not_gcc},-L${llvm_path}/lib,${empty})
export CPPFLAGS = $(if ${not_gcc},-I${llvm_path}/include,${empty})
# ------------------------------------------ Needs to be adjusted for build on other systems

.Phony: all cleanall clean build tidy format

all: tidy format
	${MAKE} build

cleanall:
	rm -rf ${build}

clean:
	cd ${build_dir} &&\
	ls -A | grep -vo "_deps" | xargs rm -rf

build: build/cmake
	${MAKE} -C ${build_dir}

tidy: export COMPILER=clang
tidy: export BUILD_TYPE=Tidy
tidy:
	${MAKE} build/cmake
	@echo this echo is necessary else the path is not set-up correctly &&\
	run-clang-tidy \
		-p ${project_path}/${build_dir}\
		${project_files}

format:
	clang-format -i -style=file ${project_files}

# -------------------------------------------
.Phony: build/cmake build/dir

build/cmake: build/dir
	cd ${build_dir} &&\
	cmake\
		-DCMAKE_C_COMPILER=${C_COMPILER}\
		-DCMAKE_CXX_COMPILER=${CXX_COMPILER}\
		-DCMAKE_BUILD_TYPE=${BUILD_TYPE}\
		-DMAKE_DOCS=ON\
		-DMAKE_DOC_PATH=${docs_path}\
		${project_path}

build/dir:
	mkdir -p ${build_dir}
