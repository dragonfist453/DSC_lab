#! /usr/bin/env bash

CC=gcc
FLAGS="-Wall"
TARGET="./target"

mkdir -p "$TARGET"

build_all() {
    for i in src/*.c; do
        local prg="$(basename $i)"
        prg=${prg%.*}
        eval $CC $FLAGS -o "$TARGET/$prg" $i
    done
}

build_target() {
    local src="./src/$1.c"
    eval $CC $FLAGS -o "$TARGET/$1" $src
}

clean() {
    rm -f $TARGET/*
}

get_help() {
    echo "Dynamic make script - Akshay Oppiliappan <nerdypepper@tuta.io>"

    echo "Usage:"
    echo "make.sh"
    echo '     .. clean       clean up `target` directory'
    echo '     .. all         make all `target`s from `src` directory'
    echo '     .. <target>    build only `target`'
}

case $1 in
    c|clean)
        clean
        ;;
    a|all)
        build_all
        ;;
    h|help)
        get_help
        ;;
    *)
        build_target $1
esac
